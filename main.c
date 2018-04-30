// nRF Swarm rev 0.3 by Henrik Malvik Halvorsen - Master's project

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "nrf.h"
#include "nordic_common.h"
#include "boards.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_delay.h"

#include "vl53l0x_def.h"

#include "mpu_twi.h"
#include "app_mpu.h"
#include "real_time_clock.h"
#include "swarm_pcb.h"
#include "batt_meas.h"
#include "app_tof.h"
#include "state.h"
#include "romano.h"
#include "ascii_converter.h"
#include "crc_filter.h"


#include "mqttsn_client.h"
#include "thread_utils.h"

#include <openthread/openthread.h>
#include <openthread/cli.h>
#include <openthread/platform/platform.h>

#define ALGORITHM_INTERVAL_MS   100
#define BOOT_DELAY_MS           10

#define SEARCH_GATEWAY_FREQUENCY 10
#define ADVERTISING_LED_FREQUENCY 10

#define LED_ON_REQUEST      1                                               /**< LED ON command. */
#define LED_OFF_REQUEST     0                                               /**< LED OFF command. */

/**
 * @brief Start of main.
 */


// States used by the MQTT-SN API.

static char                 m_client_id[6];                                 /**< The MQTT-SN Client's ID. */
static mqttsn_client_t      m_client;                                       /**< An MQTT-SN client instance. */
static mqttsn_remote_t      m_gateway_addr;                                 /**< A gateway address. */
static uint8_t              m_gateway_id;                                   /**< A gateway ID. */
static mqttsn_connect_opt_t m_connect_opt;                                  /**< Connect options for the MQTT-SN client. */
static bool                 m_subscribed              = 0;                  /**< Current subscription state. */
static bool                 m_connected               = 0;                  /**< Current connection state. */
static uint16_t             m_msg_id                  = 0;                  /**< Message ID thrown with MQTTSN_EVENT_TIMEOUT. */
static char                 m_topic_common_name[]     = "Swarm/Common";     /**< Name of the topic corresponding to Swarm common data. */
static bool                 m_gateway_found           = false;              /**< Stores whether a gateway has been found. */
static mqttsn_topic_t       m_topic_common            =                     /**< Topic corresponding to subscriber's LED. */
{
   .p_topic_name = (unsigned char *)m_topic_common_name,
   .topic_id     = 0,
};


static state_machine_t s_state;
void romano_pub_heartbeat_msg(void); // Prototype needed as main algorithm exist upon ROMANO declaration.

// Timer instance declaration.

static const nrf_drv_timer_t application_timer = NRF_DRV_TIMER_INSTANCE(1); // Main timer
static nrf_drv_timer_t rtc_timer = NRF_DRV_TIMER_INSTANCE(2); // Timer used for real time sensitive data

////////////////////////////////////////////////////////////////////
///////////////// Algorithm / Abstraction Layer ////////////////////
////////////////////////////////////////////////////////////////////

void connection_check(void)
{
  if(!m_gateway_found && m_client.client_state != MQTTSN_CLIENT_SEARCHING_GATEWAY) // Sends a gateway search message in which the gateway will respond.
  {
    if(mqttsn_client_search_gateway(&m_client) != NRF_SUCCESS)
    {
      NRF_LOG_RAW_INFO("[FAIL] Could not send gateway search message. \n");
    }
  }
  else if(m_gateway_found && m_client.client_state != MQTTSN_CLIENT_CONNECTED && !m_subscribed)
  {
    if(mqttsn_client_connect(&m_client, &m_gateway_addr, m_gateway_id, &m_connect_opt) != NRF_SUCCESS)
    {
      NRF_LOG_RAW_INFO("[FAIL] Could not connect to the network. Retrying.. \n");
    }
  }
  else if(m_gateway_found && m_client.client_state == MQTTSN_CLIENT_CONNECTED && !m_subscribed)
  {
    if(mqttsn_client_subscribe(&m_client, m_topic_common.p_topic_name, strlen(m_topic_common_name), &m_msg_id) != NRF_SUCCESS) // TODO: Add subscription to all topics.
      {
        NRF_LOG_RAW_INFO("[FAIL] Could not send a subscribe message. Retrying.. \n")
      }
    else
      {
        m_subscribed = true;
      }
  }
}

void state_printing(void)
{
  #if PRINT_STATE_MAC_ADDRESS
  NRF_LOG_RAW_INFO("MAC: 0x%x%x%x%x%x%x - ", s_state.mac_address[5], s_state.mac_address[4], s_state.mac_address[3], s_state.mac_address[2], s_state.mac_address[1], s_state.mac_address[0]);
  #endif

  #if PRINT_STATE_MAG_VALUES
  NRF_LOG_RAW_INFO("Mag: X %d Y %d Z %d H %d \n", s_state.mag[0], s_state.mag[1], s_state.mag[2], s_state.heading);
  #endif

  #if PRINT_STATE_ACCELEROMETER_VALUES
  NRF_LOG_RAW_INFO("Acc: X %7d Y %7d Z: %7d - ", s_state.accel[0], s_state.accel[1], s_state.accel[2]);
  #endif

  #if PRINT_MOTOR_VALUES
  NRF_LOG_RAW_INFO("M1: %d M2: %d - M1D: %d M2D: %d - \n", s_state.motor.output_motor_a, s_state.motor.output_motor_b, s_state.motor.direction_motor_a, s_state.motor.direction_motor_b);
  #endif

  #if PRINT_STATE_RANGE_MEASUREMENT
  NRF_LOG_RAW_INFO("Range: %dmm - %dmm - %dmm - %dmm - ", s_state.lidarOne.RangeMilliMeter, s_state.lidarTwo.RangeMilliMeter, s_state.lidarThree.RangeMilliMeter, s_state.lidarFour.RangeMilliMeter);
  #endif

  #if PRINT_STATE_RSSI_VALUE
  NRF_LOG_RAW_INFO("RSSI: %d \n", s_state.RSSI);
  #endif

  #if PRINT_STATE_LED_VALUE
  NRF_LOG_RAW_INFO("LED: 1.%d %d %d 2.%d %d %d - ", s_state.led_one_red, s_state.led_one_green, s_state.led_one_blue, s_state.led_two_red, s_state.led_two_green, s_state.led_two_blue);
  #endif

  #if PRINT_STATE_VOLTAGE_VALUE
  NRF_LOG_RAW_INFO("Voltage: "NRF_LOG_FLOAT_MARKER" ", NRF_LOG_FLOAT(s_state.voltage));
  #endif
}

void main_algorithm(void)
{
  static uint32_t heartbeat_count = 0;
  static float delta_time = 0;
  static float prev_time = 0;
  static float range_measurement[4] = {0};
  static uint16_t analytical_data[5] = {0};

  // Poll a connection scheme until a subscription to a broker is obtained.
  if(!m_subscribed)
    connection_check();

  // Main algorithm goes here, runs after connection with the network is established
  if(m_subscribed){
    app_mpu_get_mag(s_state.mag, &s_state.heading);
    app_tof_get_range_all(&s_state.lidarOne, &s_state.lidarTwo, &s_state.lidarThree, &s_state.lidarFour, range_measurement);
    delta_time = rtc_get_delta_time_sec(&prev_time);
    update_pfc_controller(&s_state.motor, s_state.RSSI, s_state.heading, s_state.heading_ref, range_measurement, s_state.speed, delta_time, analytical_data);
    update_motor_values(&s_state.motor); 

    // Data to be analyzed

    s_state.RSSI_pid           = analytical_data[0];
    s_state.obstacle_pid_one   = analytical_data[1];
    s_state.obstacle_pid_two   = analytical_data[2];
    s_state.obstacle_pid_three = analytical_data[3];
    s_state.obstacle_pid_four  = analytical_data[4];

    // Publishes data over a set time interval
    if(heartbeat_count % 10 == 0)
      romano_pub_heartbeat_msg(); //TODO: Add this
    state_printing();
    heartbeat_count++;
  }

  s_state.interrupt_flag = false;
}

// Callback function for battery voltage reading

void batt_callback(float voltage)
{
  s_state.voltage = voltage;
   /*if(s_state.voltage < VOLTAGE_LEVEL_CUTOFF)
   {
   uint32_t err_code;

   err_code = sd_power_system_off();
   APP_ERROR_CHECK(err_code);      //put nRF52 in sleep mode / power off
 }*/
}


////////////////////////////////////////////////////////////////////
/////////////////////////// Thread /////////////////////////////////
////////////////////////////////////////////////////////////////////


// Publish a heartbeat message.
void romano_pub_heartbeat_msg(void)
{
  uint8_t romano_node_message[250];
  uint8_t buffer[250];
  uint16_t len = 0;

  sprintf((char *)&buffer[0], "{ \"MAC\" : \"%02x:%02x:%02x:%02x:%02x:%02x\", \"RSSI\" : %d, \"Range1\" : %d, \"Range2\" : %d, \"Range3\" : %d, \"Range4\" : %d, \"PIDRSSI\" : %d, \"PIDRange1\" : %d, \"PIDRange2\" : %d, \"PIDRange3\" : %d, \"PIDRange4\" : %d, \"CRC\" : %d }\r\n",
              s_state.mac_address[5], s_state.mac_address[4], s_state.mac_address[3], s_state.mac_address[2], s_state.mac_address[1], s_state.mac_address[0],
              s_state.RSSI, s_state.lidarOne.RangeMilliMeter, s_state.lidarTwo.RangeMilliMeter, s_state.lidarThree.RangeMilliMeter, s_state.lidarFour.RangeMilliMeter, 
              s_state.RSSI_pid, s_state.obstacle_pid_one, s_state.obstacle_pid_two, s_state.obstacle_pid_three, s_state.obstacle_pid_four,
              s_state.CRC);

  len = strlen((const char*)&buffer[0]);
  memcpy(romano_node_message, buffer, len);
  mqttsn_client_publish(&m_client, m_topic_common.topic_id, romano_node_message, len, NULL);
}
// Checks data that has been received and acts upon it.

void romano_message_received(uint8_t *p_data)
{
  switch(p_data[0])
  {
    case NORMAL_DATA:
      NRF_LOG_RAW_INFO("Normal data received: ");
      p_data[1] = p_data[1] - 0x30; // Hack to make this byte represent the msg_length instead of the ASCII.
      for(uint8_t i = 2; i < p_data[1] + 2; i++)
          NRF_LOG_RAW_INFO("%c", p_data[i]);
      NRF_LOG_RAW_INFO("\n");
    break;
    case MOVEMENT_CONTROL:
      if(p_data[1] == (s_state.mac_address[0] >> 4) || p_data[1] == 0) // individual control or multiple // TODO: Test this.
        {
          NRF_LOG_RAW_INFO("Movement control data received.");
          if(p_data[2] == HEADING)
            s_state.speed[0] = (float)(p_data[3] << 8 | p_data[4]);
          else if(p_data[2] == SPEED)
            s_state.speed[1] = (float)(p_data[3] << 8 | p_data[4]);
        }
    break;
    case REQUEST_SENSOR_DATA:
      NRF_LOG_RAW_INFO("Sensor data request received. Publishing available sensor data. \n ");
      uint8_t romano_sensor_message[20];
      uint8_t rssi_value = abs(s_state.RSSI);
      uint8_t hex_to_ascii_number_table[] = {0x30, 0x31, 0x31, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46};

      romano_sensor_message[0] = SENSOR_DATA;
      romano_sensor_message[1] = 0x20;
      memcpy(&romano_sensor_message[2], s_state.mac_address_ascii, 12);
      romano_sensor_message[14] = 0x20;
      romano_sensor_message[15] = 0x2D;
      romano_sensor_message[16] = 0x30;
      romano_sensor_message[17] = 0x78;
      romano_sensor_message[18] = hex_to_ascii_number_table[rssi_value >> 4];
      romano_sensor_message[19] = hex_to_ascii_number_table[rssi_value & 0xF];

      mqttsn_client_publish(&m_client, m_topic_common.topic_id, romano_sensor_message, sizeof(romano_sensor_message), NULL);
    break;
    case SENSOR_DATA:
      NRF_LOG_RAW_INFO("Sensor data received: ");
      for(uint8_t i = 2; i < SIZE_SENSOR_DATA; i++)
        NRF_LOG_RAW_INFO("%c", p_data[i]);
      NRF_LOG_RAW_INFO("\n");
    break;
    case REQUEST_CONNECTED_NODES_INFO:
      NRF_LOG_RAW_INFO("Node info request received. Publishing MAC address. \n ");
      uint8_t romano_node_message[14];
      romano_node_message[0] = CONNECTED_NODES_INFO;
      romano_node_message[1] = 0x20; // Space
      for(uint8_t i = 0; i < sizeof(romano_node_message); i++)
      {
        romano_node_message[i+2] = s_state.mac_address_ascii[i];
      }
      mqttsn_client_publish(&m_client, m_topic_common.topic_id, romano_node_message, sizeof(romano_node_message), NULL);
    break;
    case CONNECTED_NODES_INFO:
      NRF_LOG_RAW_INFO("Node info received. MAC address: ");
      for(uint8_t i = 2; i < SIZE_CONNECTED_NODES_INFO; i++)
        NRF_LOG_RAW_INFO("%c", p_data[i]);
      NRF_LOG_RAW_INFO("\n");

    break;
    case HEARTBEAT_MESSAGE:
      NRF_LOG_RAW_INFO("Heartbeat message received. \n");
    break;
  }
}

/**@brief Toggles LED2 based on received LED command. */
static void led_update(uint8_t * p_data)
{
   if (*p_data == LED_ON_REQUEST)
   {
      s_state.led_two_red   = 0;
      s_state.led_two_green = 0;
      s_state.led_two_blue  = 0;
   }
   else if (*p_data == LED_OFF_REQUEST)
   {
      s_state.led_two_red   = 0;
      s_state.led_two_green = 0;
      s_state.led_two_blue  = 0;
   }

   rgb_update_led_color(2,s_state.led_two_red,s_state.led_two_green,s_state.led_two_blue);
   return;
}

/**@brief Callback for received RSSI data.
*
*/

static void rssi_callback(uint16_t id, int8_t rssi, uint8_t crc)
{
  // Checks RSSI signal from all nodes in the network, performs a CRC check on said RSSI signal and returns the largest value
  s_state.CRC  = crc;
  s_state.RSSI = crc_filter(s_state.RSSI_values, id, rssi, crc);
}


/**@brief Processes data published by a broker.
 *
 * @details This function processes LED command.
 */
static void received_callback(mqttsn_event_t * p_event)
{
    if (p_event->event_data.published.packet.topic.topic_id == m_topic_common.topic_id)
    {
        led_update(p_event->event_data.published.p_payload);
        romano_message_received(p_event->event_data.published.p_payload);
    }
}

/**@brief Processes GWINFO message from a gateway.
 *
 * @details This function initializes MQTT-SN Client's connect options and launches the connect procedure.
 *
 * @param[in]    p_event  Pointer to MQTT-SN event.
 */
static void gateway_info_callback(mqttsn_event_t * p_event)
{
    m_gateway_found = true;
    m_gateway_addr  = *(p_event->event_data.connected.p_gateway_addr);
    m_gateway_id    = p_event->event_data.connected.gateway_id;

    m_connect_opt.alive_duration = MQTTSN_DEFAULT_ALIVE_DURATION,
    m_connect_opt.clean_session  = MQTTSN_DEFAULT_CLEAN_SESSION_FLAG,
    m_connect_opt.will_flag      = MQTTSN_DEFAULT_WILL_FLAG,
    m_connect_opt.client_id_len  = strlen(m_client_id),

    memcpy(m_connect_opt.p_client_id,  (unsigned char *)m_client_id,  m_connect_opt.client_id_len);

    uint32_t err_code = mqttsn_client_connect(&m_client, &m_gateway_addr, m_gateway_id, &m_connect_opt);
    if (err_code != NRF_SUCCESS)
    {
        NRF_LOG_ERROR("CONNECT message could not be sent. Error code: 0x%x\r\n", err_code);
    }
}


/**@brief Processes CONNACK message from a gateway.
 *
 * @details This function launches the topic registration procedure if necessary.
 */
static void connected_callback(void)
{
    s_state.led_one_red   = 0;
    s_state.led_one_green = 0;
    s_state.led_one_blue  = 1000;
    rgb_update_led_color(1,s_state.led_one_red,s_state.led_one_green,s_state.led_one_blue);

    uint32_t err_code;

    do{
    err_code = mqttsn_client_topic_register(&m_client, m_topic_common.p_topic_name, strlen(m_topic_common_name), &m_msg_id);
    } while(err_code != NRF_SUCCESS);

    /*err_code = mqttsn_client_topic_register(&m_client, m_topic_heartbeat.p_topic_name, strlen(m_topic_heartbeat_name), &m_msg_id);
    if (err_code != NRF_SUCCESS)
        NRF_LOG_ERROR("REGISTER message could not be sent. Error code: 0x%x\r\n", err_code);*/
}


/**@brief Processes DISCONNECT message from a gateway. */
static void disconnected_callback(void)
{
    s_state.led_one_red   = 0;
    s_state.led_one_green = 1000;
    s_state.led_one_blue  = 0;
    rgb_update_led_color(1,s_state.led_one_red,s_state.led_one_green,s_state.led_one_blue);
}


/**@brief Processes REGACK message from a gateway.
 *
 * @param[in] p_event Pointer to MQTT-SN event.
 */
static void regack_callback(mqttsn_event_t * p_event)
{
    if(m_topic_common.topic_id  == 0)
    {
      m_topic_common.topic_id = p_event->event_data.registered.packet.topic.topic_id;
      NRF_LOG_RAW_INFO("MQTT-SN event: Common topic has been registered with ID: %d.\n",
                 p_event->event_data.registered.packet.topic.topic_id);
    }
    /*else if(m_topic_heartbeat.topic_id == 0) //NOTE: This is not a good solution and should be seen as a hack. This solution assumes that the common topic will be registered first at all times.
                                              //     However, at the current point of the MQTT_SN API there is no other solution, and the assignment does not cover the time to change this. It works and we will leave it at that.
    {
      m_topic_heartbeat.topic_id = p_event->event_data.registered.packet.topic.topic_id;
      NRF_LOG_RAW_INFO("MQTT-SN event: Heartbeat topic has been registered with ID: %d.\n",
                 p_event->event_data.registered.packet.topic.topic_id);
    }*/
}

/**@brief Processes retransmission limit reached event. */
static void timeout_callback(mqttsn_event_t * p_event)
{
    NRF_LOG_RAW_INFO("MQTT-SN event: Timed-out message: %d. Message ID: %d.\r\n",
                  p_event->event_data.error.msg_type,
                  p_event->event_data.error.msg_id);
}


/**@brief Function for handling MQTT-SN events. */
void mqttsn_evt_handler(mqttsn_client_t * p_client, mqttsn_event_t * p_event)
{
    switch(p_event->event_id)
    {
        case MQTTSN_EVENT_GATEWAY_FOUND:
            NRF_LOG_RAW_INFO("MQTT-SN event: Client has found an active gateway.\r\n");
            gateway_info_callback(p_event);
            break;

        case MQTTSN_EVENT_CONNECTED:
            NRF_LOG_RAW_INFO("MQTT-SN event: Client connected.\r\n");
            connected_callback();
            break;

        case MQTTSN_EVENT_DISCONNECTED:
            NRF_LOG_RAW_INFO("MQTT-SN event: Client disconnected.\r\n");
            disconnected_callback();
            break;

        case MQTTSN_EVENT_REGISTERED:
            NRF_LOG_RAW_INFO("MQTT-SN event: Client registered topic.\r\n");
            regack_callback(p_event);
            break;

        case MQTTSN_EVENT_SUBSCRIBED:
            NRF_LOG_RAW_INFO("MQTT-SN event: Client subscribed to topic.\r\n");
            break;

        case MQTTSN_EVENT_UNSUBSCRIBED:
            NRF_LOG_RAW_INFO("MQTT-SN event: Client unsubscribed to topic.\r\n");
            break;

        case MQTTSN_EVENT_RECEIVED:
            //NRF_LOG_RAW_INFO("MQTT-SN event: Client received content.\r\n");
            received_callback(p_event);
            break;

        case MQTTSN_EVENT_TIMEOUT:
            NRF_LOG_RAW_INFO("MQTT-SN event: Retransmission retries limit has been reached.\r\n");
            timeout_callback(p_event);
            break;

        default:
            break;
    }
}

static void state_changed_callback(uint32_t flags, void * p_context)
{
    NRF_LOG_RAW_INFO("State changed! Flags: 0x%08x Current role: %d\r\n",
                 flags, otThreadGetDeviceRole(p_context));
}

/**@brief Function for initializing the Thread Stack.
 */
static void thread_instance_init(void)
{
    thread_configuration_t thread_configuration =
    {
        .role              = RX_ON_WHEN_IDLE,
        .autocommissioning = true,
    };

    thread_init(&thread_configuration);
    thread_cli_init();
    thread_state_changed_callback_set(state_changed_callback);

    NRF_LOG_RAW_INFO("Thread protocol enabled. \n");
}

/**@brief Function for initializing the MQTTSN client.
 */
static void mqttsn_init(void)
{
    uint32_t err_code = mqttsn_client_init(&m_client,
                                           MQTTSN_DEFAULT_CLIENT_PORT,
                                           mqttsn_evt_handler,
                                           thread_ot_instance_get(),
                                           rssi_callback);
    APP_ERROR_CHECK(err_code);
    NRF_LOG_RAW_INFO("MQTT-SN client initialized. \n");
}

////////////////////////////////////////////////////////////////////
/////////////////////////// Peripherals ////////////////////////////
////////////////////////////////////////////////////////////////////

// Init function for logging of data

void log_init(void)
{
   ret_code_t err_code = NRF_LOG_INIT(NULL);
   APP_ERROR_CHECK(err_code);

   NRF_LOG_DEFAULT_BACKENDS_INIT();
}

// Event handler for the main timer

void timer_event_handler(nrf_timer_event_t event_type, void* p_context)
{
  static uint32_t advertising_count = 0;
  static uint32_t adv_led_green = 1000;
  static uint32_t adv_led_blue  = 0;
  static bool led_flag = false;

  s_state.interrupt_flag = true;

  /// Code here will only be used if the system is not connected to gateway

  if(m_client.client_state != MQTTSN_CLIENT_CONNECTED)
    {

    // Code to restart search if gateway is not found. IMPORTANT

    if(m_client.client_state == MQTTSN_CLIENT_SEARCHING_GATEWAY && (advertising_count % SEARCH_GATEWAY_FREQUENCY)  == 0)
      m_client.client_state = MQTTSN_CLIENT_DISCONNECTED;

     // Some code to make LED1 blink when trying to connect to a gateway, indicating a connection process.

    if(m_gateway_found) // Changes the color of the LED if the gateway is found but no connection to the broker is established.
    {
      adv_led_green = 0;
      adv_led_blue  = 1000;
    }

    if(advertising_count % ADVERTISING_LED_FREQUENCY == 0)
      {
        if(led_flag)
        {
         rgb_update_led_color(1, 0, 0, 0);
         led_flag = false;
        }
        else
        {
          rgb_update_led_color(1, 0, adv_led_green, adv_led_blue);
          led_flag = true;
        }
      }
    }
    advertising_count++;
}

//Init function for initiation of the main timer.

void timer_init()
{
   uint32_t err_code;
   uint32_t time_ticks;

   static nrf_drv_timer_config_t timer_cfg =
   {
       .frequency = NRF_TIMER_FREQ_16MHz,
       .mode      = NRF_TIMER_MODE_TIMER,
       .bit_width = NRF_TIMER_BIT_WIDTH_32,
       .interrupt_priority = 3
   };
   err_code = nrf_drv_timer_init(&application_timer, &timer_cfg, timer_event_handler);
   APP_ERROR_CHECK(err_code);

   time_ticks = nrf_drv_timer_ms_to_ticks(&application_timer, ALGORITHM_INTERVAL_MS);

   nrf_drv_timer_extended_compare(&application_timer, NRF_TIMER_CC_CHANNEL0, time_ticks, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);

   nrf_drv_timer_enable(&application_timer);

   NRF_LOG_RAW_INFO("[SUCCESS] Main timer enabled. \n");
}

// Fetches the MAC address of the device to use it as a unique client ID.

void get_device_address()
{
  m_client_id[0] = (NRF_FICR->DEVICEADDR[0])       & 0xFF;
  m_client_id[1] = (NRF_FICR->DEVICEADDR[0] >> 8)  & 0xFF;
  m_client_id[2] = (NRF_FICR->DEVICEADDR[0] >> 16) & 0xFF;
  m_client_id[3] = (NRF_FICR->DEVICEADDR[0] >> 24) & 0xFF;
  m_client_id[4] = (NRF_FICR->DEVICEADDR[1])       & 0xFF;
  m_client_id[5] = (NRF_FICR->DEVICEADDR[1] >> 8)  & 0xFF;

  memcpy(s_state.mac_address, m_client_id, 6);
  s_state.mac_address_ascii_size = hex_array_to_ascii(s_state.mac_address, s_state.mac_address_ascii);
}

////////////////////////////////////////////////////////////////////
/////////////////////////// Main ///////////////////////////////////
////////////////////////////////////////////////////////////////////

int main(void)
{
  log_init();
  get_device_address();

  NRF_LOG_RAW_INFO("\n \n nRF Swarm revision 0.3.2 online. \n \n");
  NRF_LOG_RAW_INFO("The device MAC address is given by: 0x%x%x%x%x%x%x \n", s_state.mac_address[5], s_state.mac_address[4], s_state.mac_address[3], s_state.mac_address[2], s_state.mac_address[1], s_state.mac_address[0]);
  NRF_LOG_RAW_INFO("Initializing all systems in %d ms. \n", BOOT_DELAY_MS);

  nrf_delay_ms(BOOT_DELAY_MS); // Delay must be here since the MPU-9250 needs a small time interval in order to be ready for TWI-communication.

  // Initialization

  pcb_peripherals_init(); // Initializes RGB LEDs and GPIO

  rtc_init(&rtc_timer);               // Real time clock used for configuration and timing of the MPU 9250 and additional real time sensitive data
  mpu_twi_init();                     // Initialize two wire interface used to communicate with the MPU 9250.
  app_mpu_init();                     // Initialize MPU 9250, flashing DMP firmware to the unit.
  app_tof_init();                     // Initialize all VL53L0X LIDAR units.
  batt_mon_enable(batt_callback);     // Battery voltage monitoring.
  motor_pwm_init();                   // PWM used to control the motors of the vessel.
  potential_field_controller_init();  // Potential field controller which makes the vessel move based on sensory input.
  timer_init();                       // Main timer used to run the swarm algorithm.

  thread_instance_init();
  mqttsn_init();


  rgb_update_led_color(1,0,1000,0);
  nrf_gpio_cfg_output(3);

  NRF_LOG_RAW_INFO ("All systems online. \n \n");

  while (true)
    {
      thread_process();

      if (NRF_LOG_PROCESS() == false)
      {
          nrf_gpio_pin_set(3);
          thread_sleep();
          nrf_gpio_pin_clear(3);
      }

      if(s_state.interrupt_flag)
        {
          main_algorithm();
        }
    }
}
/** @} */

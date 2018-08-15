// nRF Swarm rev 0.5 by Henrik Malvik Halvorsen - Continuation master's project, demonstration work

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
#include "light_meas.h"
#include "beeclust.h"
#include "app_tof.h"
#include "state.h"
#include "romano.h"
#include "ascii_converter.h"
#include "crc_filter.h"

#include "thread_utils.h"
#include "thread_coap_utils.h"

#include <openthread/openthread.h>
#include <openthread/cli.h>
#include <openthread/platform/platform.h>

#define ALGORITHM_INTERVAL_MS   100
#define BOOT_DELAY_MS           10

/**
 * @brief Start of main.
 */

static state_machine_t s_state;

// Timer instance declaration.

static const nrf_drv_timer_t application_timer = NRF_DRV_TIMER_INSTANCE(1); // Main timer
static nrf_drv_timer_t rtc_timer = NRF_DRV_TIMER_INSTANCE(2); // Timer used for real time sensitive data

void thread_send_messsage(uint8_t command);

////////////////////////////////////////////////////////////////////
///////////////// Algorithm / Abstraction Layer ////////////////////
////////////////////////////////////////////////////////////////////


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

  #if PRINT_STATE_LIGHT_VALUE
  NRF_LOG_RAW_INFO("Light percentage: "NRF_LOG_FLOAT_MARKER" \n", NRF_LOG_FLOAT(s_state.light_percentage));
  #endif
}

void main_algorithm(void)
{
  static uint32_t heartbeat_count = 0;
  static float delta_time = 0;
  static float prev_time = 0;
  static float range_measurement[4] = {0};
  static int16_t analytical_data[5] = {0};
  static float static_speed[2] = {500, 500};

  // Main algorithm goes here

  app_tof_get_range_all(&s_state.lidarOne, &s_state.lidarTwo, &s_state.lidarThree, &s_state.lidarFour, range_measurement);
  delta_time = rtc_get_delta_time_sec(&prev_time);
  s_state.stop_motors = beeclust_check(delta_time, s_state.stop_motors, s_state.light_percentage);
  update_pfc_controller(&s_state.motor, s_state.RSSI, s_state.heading, s_state.heading_ref, range_measurement, static_speed, delta_time, analytical_data);

  if(s_state.stop_motors == 0)
    update_motor_values(&s_state.motor);
  else if(s_state.stop_motors == 1)
    stop_motors();

  // Publishes data over a set time interval
  if(heartbeat_count % 1 == 0){
    state_printing();
    heartbeat_count++;
  }

  s_state.interrupt_flag = false;
}

// Callback function for battery voltage reading

void light_callback(float voltage)
{
  s_state.light_percentage = voltage;
}


////////////////////////////////////////////////////////////////////
/////////////////////////// Thread /////////////////////////////////
////////////////////////////////////////////////////////////////////

// Send a multicast data message.

void thread_send_messsage(uint8_t command)
{
  thread_coap_utils_multicast_light_request_send(thread_ot_instance_get(),
                                                 command,
                                                 THREAD_COAP_UTILS_MULTICAST_REALM_LOCAL);
}

// Data received callback.

static void thread_data_received_callback(uint8_t data)
{
  static bool led_toggle = true;

  if(led_toggle)
  {
    rgb_update_led_color(1,1000,200,333);
    led_toggle = false;
  }
  else
  {
    rgb_update_led_color(1,0,1000,0);
    led_toggle = true;
  }

  beeclust_data_update(data);
}

static void thread_state_changed_callback(uint32_t flags, void * p_context)
{
    if (flags & OT_CHANGED_THREAD_ROLE)
    {
        switch (otThreadGetDeviceRole(p_context))
        {
            case OT_DEVICE_ROLE_CHILD:
            case OT_DEVICE_ROLE_ROUTER:
            case OT_DEVICE_ROLE_LEADER:
                break;

            case OT_DEVICE_ROLE_DISABLED:
            case OT_DEVICE_ROLE_DETACHED:
            default:
                thread_coap_utils_peer_addr_clear();
                break;
        }
    }

    if (flags & OT_CHANGED_THREAD_PARTITION_ID)
    {
        thread_coap_utils_peer_addr_clear();
    }

    NRF_LOG_INFO("State changed! Flags: 0x%08x Current role: %d\r\n",
                 flags,
                 otThreadGetDeviceRole(p_context));
}

/**@brief Function for initializing the Thread Stack
 */
static void thread_instance_init(void)
{
    thread_configuration_t thread_configuration =
    {
        .role                  = RX_ON_WHEN_IDLE,
        .autocommissioning     = true,
        .poll_period           = 2500,
        .default_child_timeout = 10,
    };

    thread_init(&thread_configuration);
    thread_cli_init();
    thread_state_changed_callback_set(thread_state_changed_callback);
}


/**@brief Function for initializing the Constrained Application Protocol Module
 */
static void thread_coap_init(void)
{
    thread_coap_configuration_t thread_coap_configuration =
    {
        .coap_server_enabled               = true,
        .coap_client_enabled               = true,
        .coap_cloud_enabled                = false,
        .configurable_led_blinking_enabled = false,
    };

    thread_coap_utils_init(&thread_coap_configuration, thread_data_received_callback);
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
  s_state.interrupt_flag = true;
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
  s_state.mac_address[0] = (NRF_FICR->DEVICEADDR[0])       & 0xFF;
  s_state.mac_address[1] = (NRF_FICR->DEVICEADDR[0] >> 8)  & 0xFF;
  s_state.mac_address[2] = (NRF_FICR->DEVICEADDR[0] >> 16) & 0xFF;
  s_state.mac_address[3] = (NRF_FICR->DEVICEADDR[0] >> 24) & 0xFF;
  s_state.mac_address[4] = (NRF_FICR->DEVICEADDR[1])       & 0xFF;
  s_state.mac_address[5] = (NRF_FICR->DEVICEADDR[1] >> 8)  & 0xFF;
}

////////////////////////////////////////////////////////////////////
/////////////////////////// Main ///////////////////////////////////
////////////////////////////////////////////////////////////////////

int main(void)
{
  log_init();
  get_device_address();

  NRF_LOG_RAW_INFO("\n \n nRF Swarm Beeclust revision 0.5 online. \n \n");
  NRF_LOG_RAW_INFO("The device MAC address is given by: 0x%x%x%x%x%x%x \n", s_state.mac_address[5], s_state.mac_address[4], s_state.mac_address[3], s_state.mac_address[2], s_state.mac_address[1], s_state.mac_address[0]);
  NRF_LOG_RAW_INFO("Initializing all systems in %d ms. \n", BOOT_DELAY_MS);

  nrf_delay_ms(BOOT_DELAY_MS); // Delay must be here since the MPU-9250 needs a small time interval in order to be ready for TWI-communication.

  // Initialization

  pcb_peripherals_init(); // Initializes RGB LEDs and GPIO

  rtc_init(&rtc_timer);                // Real time clock used for configuration and timing of the MPU 9250 and additional real time sensitive data
  app_tof_init();                      // Initialize all VL53L0X LIDAR units.
  light_sensor_init(light_callback);   // Light sensor voltage monitoring.
  motor_pwm_init();                    // PWM used to control the motors of the vessel.
  potential_field_controller_init();   // Potential field controller which makes the vessel move based on sensory input.
  beeclust_init(thread_send_messsage); // Initialize the BEECLUST search algorithm.
  timer_init();                        // Main timer used to run the swarm algorithm.

  rgb_update_led_color(1,0,1000,0);

  thread_instance_init();
  thread_coap_init();

  NRF_LOG_RAW_INFO ("All systems online. \n \n");

  while (true)
  {
      thread_process();

      if (NRF_LOG_PROCESS() == false)
      {
          thread_sleep();
      }

      if(s_state.interrupt_flag)
      {
        main_algorithm();
      }
  }
}
/** @} */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "mqttsn_client.h"
#include "thread_utils.h"
#include "romano.h"
#include "nrf_log.h"

#include <openthread/openthread.h>
#include <openthread/cli.h>
#include <openthread/platform/platform.h>

static char                 mac_address[6];
static mqttsn_client_t      *m_client_pointer;                                       /**< An MQTT-SN client instance pointer. */
static motor_t              *motor_pointer;                                          /**< A pointer for the motor state machine. */
static mqttsn_topic_t       *m_topic_common;
static mqttsn_topic_t       *m_topic_client;

void romano_subscribe(mqttsn_topic_t m_topic)
{
  uint8_t  topic_name_len = strlen(m_topic_name.p_topic_name);
  mqttsn_client_subscribe(m_client_pointer, m_topic.p_topic_name, topic_name_len, &m_msg_id) // TODO: Check if static msg id (0) is sufficient. If not, add an id to the payload.
}

void romano_unsubscribe(mqttsn_topic_t m_topic)
{
  uint8_t  topic_name_len = strlen(m_topic_name.p_topic_name);
  mqttsn_client_unsubscribe(m_client_pointer, m_topic.p_topic_name, topic_name_len, &m_msg_id)
}

// Checks data that has been received and acts upon it.

void romano_message_received(uint8_t *p_data)
{
  switch(p_data[0])
  {
    case NORMAL_DATA:
      NRF_LOG_RAW_INFO("Normal data received: ");
      for(uint8_t i = 0; i < p_data[1] ; i++)
          NRF_LOG_RAW_INFO("%c", p_data[i]);
      NRF_LOG_RAW_INFO("\n");
    break;

    case MQTT_SUBSCRIBE:
      NRF_LOG_RAW_INFO("Subscribe request receieved, subscribing to topic: ");
      for(uint8_t i = 0; i < p_data[1]; i++)
        {
          m_topic_name[i] = p_data[i+2]; // Obtaining topic name from received data.
          NRF_LOG_RAW_INFO("%d", p_data[i]);
        }
      NRF_LOG_RAW_INFO("\n");
      mqttsn_topic_t m_topic.p_topic_name = (unsigned char *)m_topic_name; // Setting the topic name to a format expected by the thread API.
      romano_subscribe(mqttsn_topic_t m_topic);
    break;

    case MQTT_UNSUBSCRIBE:
      NRF_LOG_RAW_INFO("Unsubscribe request receieved, unsubscribing to topic: ");
      for(uint8_t i = 0; i < p_data[1]; i++)
        {
          m_topic_name[i] = p_data[i+2]; // Obtaining topic name from received data.
          NRF_LOG_RAW_INFO("%d", p_data[i]);
        }
      NRF_LOG_RAW_INFO("\n");
      mqttsn_topic_t m_topic.p_topic_name = (unsigned char *)m_topic_name; // Setting the topic name to a format expected by the thread API.
      romano_unsubscribe(mqttsn_topic_t m_topic);
    break;

    case MOVEMENT_CONTROL:
      NRF_LOG_RAW_INFO("Movement control data received."); //TODO: Add functionality for PFC/Compass rather than assume direct control
      if(p_data[1] == DIRECT_CONTROL) // Checks if the movement control type demands direct control rather than regulatory control
      {
        motor_pointer->output_motor_a = p_data[3] << 8 || p_data[2];
        motor_pointer->output_motor_b = p_data[5] << 8 || p_data[4];
        motor_pointer->direction_motor_a = p_data[6];
        motor_pointer->direction_motor_b = p_data[7];
        // TODO: add code that will stop the regulator
      }
    break;

    case REQUEST_SENSOR_DATA:

    break;

    case SENSOR_DATA:

    break;

    case REQUEST_CONNECTED_NODES_INFO:
      NRF_LOG_RAW_INFO("Node info request received. Publishing MAC address on topic Swarm/Common. \n ")
      mqttsn_client_publish(m_client_pointer, m_topic_common->topic_id, mac_address, 6, NULL);
    break;

    case CONNECTED_NODES_INFO:
      NRF_LOG_RAW_INFO("Node info received. MAC address:");
    break;

    case HEARTBEAT_MESSAGE:
    break;


  }
}

void romano_init(mqttsn_client_t *m_client, mqttsn_topic_t *m_topic_common, mqttsn_topic_t *m_topic_client ,char *m_client_id, motor_t *motor)
{
  m_client_pointer       = m_client;
  m_topic_common_pointer = m_topic_common;
  m_topic_client_pointer = m_topic_client;
  mac_address            = m_client_id;
  motor_pointer          = motor;

}

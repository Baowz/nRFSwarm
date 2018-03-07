#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "nrf_log.h"

#include "mqttsn_client.h"
#include "thread_utils.h"

#include "romano.h."
#include "state.h"

#include <openthread/openthread.h>
#include <openthread/cli.h>
#include <openthread/platform/platform.h>

static mqttsn_client_t      *m_client_pointer;                                       /**< An MQTT-SN client instance pointer. */                                        /**< A pointer for the motor state machine. */
static mqttsn_topic_t       *m_topic_common_pointer;
static mqttsn_topic_t       *m_topic_client_pointer;
static s_state              *state_pointer;

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

    case MOVEMENT_CONTROL:
      NRF_LOG_RAW_INFO("Movement control data received."); //TODO: Add functionality for PFC/Compass rather than assume direct control
      if(p_data[1] == DIRECT_CONTROL) // Checks if the movement control type demands direct control rather than regulatory control
      {
        state_pointer->motor->output_motor_a = p_data[3] << 8 || p_data[2];
        state_pointer->motor->output_motor_b = p_data[5] << 8 || p_data[4];
        state_pointer->motor->direction_motor_a = p_data[6];
        state_pointer->motor->direction_motor_b = p_data[7];
        // TODO: add code that will stop the regulator
      }
    break;

    case REQUEST_SENSOR_DATA:

    break;

    case SENSOR_DATA:

    break;

    case REQUEST_CONNECTED_NODES_INFO:
    uint8_t test = '3';
      NRF_LOG_RAW_INFO("Node info request received. Publishing MAC address on topic Swarm/Common. \n ")
      mqttsn_client_publish(m_client_pointer, m_topic_common_pointer->topic_id, &test, 6, NULL);
    break;

    case CONNECTED_NODES_INFO:
      NRF_LOG_RAW_INFO("Node info received. MAC address:");
    break;

    case HEARTBEAT_MESSAGE:
    break;


  }
}

void romano_init(mqttsn_client_t *m_client, mqttsn_topic_t *m_topic_common, mqttsn_topic_t *m_topic_client, state_machine_t *s_state)
{
  m_client_pointer       = m_client;
  m_topic_common_pointer = m_topic_common;
  m_topic_client_pointer = m_topic_client;
  state_pointer          = s_state;

  NRF_LOG_RAW_INFO("[SUCCESS] ROMANO application overlay protocol initialized. \n");
}

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

static mqttsn_client_t      *m_client_pointer;                                       /**< An MQTT-SN client instance pointer. */
static char m_topic_name[]                     = DEFAULT_TOPIC_NAME;
static mqttsn_topic_t       m_topic            =
{
   .p_topic_name = 0,
   .topic_id     = 0,
};
static uint8_t publish_data[] = 0;


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
      for(uint8_t i = 2; i < p_data[1] + 2; i++)
        {
          m_topic_name[i-2] = p_data[i]; // Obtaining topic name from received data.
          NRF_LOG_RAW_INFO("%d", p_data[i]);
        }
      NRF_LOG_RAW_INFO("\n");
      mqttsn_topic_t m_topic.p_topic_name = (unsigned char *)m_topic_name; // Setting the topic name to a format expected by the thread API.
      romano_subscribe(mqttsn_topic_t m_topic);
    break;

    case MQTT_UNSUBSCRIBE:
      NRF_LOG_RAW_INFO("Unsubscribe request receieved, unsubscribing to topic: ");
      for(uint8_t i = 2; i < p_data[1] + 2; i++)
        {
          m_topic_name[i-2] = p_data[i]; // Obtaining topic name from received data.
          NRF_LOG_RAW_INFO("%d", p_data[i]);
        }
      NRF_LOG_RAW_INFO("\n");
      mqttsn_topic_t m_topic.p_topic_name = (unsigned char *)m_topic_name; // Setting the topic name to a format expected by the thread API.
      romano_unsubscribe(mqttsn_topic_t m_topic);
    break;

    case PUBLISH_REQUEST:
      NRF_LOG_RAW_INFO("Publish request received. Publishing on topic: ");
      uint16_t topic_length =  ((uint16_t)p_data[2]) << 8 | p_data[1];
      for(uint8_t i = 4; i < topic_length + 4; i++)
        {
          m_topic_name[i-4] = p_data[i]; // Obtaining topic name from received data.
          NRF_LOG_RAW_INFO("%d", p_data[i]);
        }
        NRF_LOG_RAW_INFO("\n");
      for(uint8_t i = 4 + topic_length; i < p_data[1]; i++)
        {
          publish_data[i - 4 + topic_length] = p_data[i];
        }
        mqttsn_client_publish(&m_client, m_topic.topic_id, publish_data, 1, &m_msg_id); // TODO: Fix this
      break;

    case MOVEMENT_CONTROL:
      NRF_LOG_RAW_INFO("Movement control data received.");
  }
}

void romano_init(mqttsn_client_t *m_client)
{
  m_client_pointer = m_client;
}

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "mqttsn_client.h"
#include "app_error.h"
#include "nrf_log.h"

#include "m_thread.h"

#include "m_mqtt.h"

static mqttsn_client_t m_client;                        /**< An MQTT-SN client instance. */
static mqttsn_remote_t m_gateway_addr;                  /**< A gateway address. */
static uint8_t m_gateway_id;                            /**< A gateway ID. */
static mqttsn_connect_opt_t m_connect_opt;              /**< Connect options for the MQTT-SN client. */
static bool m_subscribed = 0;                           /**< Current subscription state. */
static uint16_t m_msg_id = 0;                           /**< Message ID thrown with MQTTSN_EVENT_TIMEOUT. */
static char m_client_id[] = "nRF52840_subscriber";      /**< The MQTT-SN Client's ID. */
static char m_topic_name[] = "nRF52840_resources/led3"; /**< Name of the topic corresponding to subscriber's BSP_LED_2. */
static mqttsn_topic_t m_topic =                         /**< Topic corresponding to subscriber's BSP_LED_2. */
    {
        .p_topic_name = (unsigned char *)m_topic_name,
        .topic_id = 0,
};

/**@brief Initializes MQTT-SN client's connection options. */
static void connect_opt_init(void)
{
    m_connect_opt.alive_duration = MQTTSN_DEFAULT_ALIVE_DURATION,
    m_connect_opt.clean_session = MQTTSN_DEFAULT_CLEAN_SESSION_FLAG,
    m_connect_opt.will_flag = MQTTSN_DEFAULT_WILL_FLAG,
    m_connect_opt.client_id_len = strlen(m_client_id),

    memcpy(m_connect_opt.p_client_id, (unsigned char *)m_client_id, m_connect_opt.client_id_len);
}

/**@brief Processes GWINFO message from a gateway.
 *
 * @details This function updates MQTT-SN Gateway information.
 *
 * @param[in]    p_event  Pointer to MQTT-SN event.
 */
static void gateway_info_callback(mqttsn_event_t *p_event)
{
    m_gateway_addr = *(p_event->event_data.connected.p_gateway_addr);
    m_gateway_id = p_event->event_data.connected.gateway_id;
}

/**@brief Processes CONNACK message from a gateway.
 *
 * @details This function launches the topic registration procedure if necessary.
 */
static void connected_callback(void)
{
    uint32_t err_code = mqttsn_client_topic_register(&m_client,
                                                     m_topic.p_topic_name,
                                                     strlen(m_topic_name),
                                                     &m_msg_id);
    if (err_code != NRF_SUCCESS)
    {
        NRF_LOG_ERROR("REGISTER message could not be sent. Error code: 0x%x\r\n", err_code);
    }
}

/**@brief Processes DISCONNECT message from a gateway. */
static void disconnected_callback(void)
{
}

/**@brief Processes REGACK message from a gateway.
 *
 * @param[in] p_event Pointer to MQTT-SN event.
 */
static void regack_callback(mqttsn_event_t *p_event)
{
    m_topic.topic_id = p_event->event_data.registered.packet.topic.topic_id;
    NRF_LOG_INFO("MQTT-SN event: Topic has been registered with ID: %d.\r\n",
                 p_event->event_data.registered.packet.topic.topic_id);
}

/**@brief Processes data published by a broker.
 *
 * @details This function processes LED command.
 */
static void received_callback(mqttsn_event_t *p_event)
{
    if (p_event->event_data.published.packet.topic.topic_id == m_topic.topic_id)
    {
        NRF_LOG_INFO("MQTT-SN event: Content to subscribed topic received.\r\n");
    }
    else
    {
        NRF_LOG_INFO("MQTT-SN event: Content to unsubscribed topic received. Dropping packet.\r\n");
    }
}

/**@brief Processes retransmission limit reached event. */
static void timeout_callback(mqttsn_event_t *p_event)
{
    NRF_LOG_INFO("MQTT-SN event: Timed-out message: %d. Message ID: %d.\r\n",
                 p_event->event_data.error.msg_type,
                 p_event->event_data.error.msg_id);
}

/**@brief Processes results of gateway discovery procedure. */
static void searchgw_timeout_callback(mqttsn_event_t *p_event)
{
    NRF_LOG_INFO("MQTT-SN event: Gateway discovery result: 0x%x.\r\n", p_event->event_data.discovery);
}

/**@brief Function for handling MQTT-SN events. */
void mqttsn_evt_handler(mqttsn_client_t *p_client, mqttsn_event_t *p_event)
{
    switch (p_event->event_id)
    {
    case MQTTSN_EVENT_GATEWAY_FOUND:
        NRF_LOG_INFO("MQTT-SN event: Client has found an active gateway.\r\n");
        gateway_info_callback(p_event);
        break;

    case MQTTSN_EVENT_CONNECTED:
        NRF_LOG_INFO("MQTT-SN event: Client connected.\r\n");
        connected_callback();
        break;

    case MQTTSN_EVENT_DISCONNECT_PERMIT:
        NRF_LOG_INFO("MQTT-SN event: Client disconnected.\r\n");
        disconnected_callback();
        break;

    case MQTTSN_EVENT_REGISTERED:
        NRF_LOG_INFO("MQTT-SN event: Client registered topic.\r\n");
        regack_callback(p_event);
        break;

    case MQTTSN_EVENT_SUBSCRIBED:
        NRF_LOG_INFO("MQTT-SN event: Client subscribed to topic.\r\n");
        break;

    case MQTTSN_EVENT_UNSUBSCRIBED:
        NRF_LOG_INFO("MQTT-SN event: Client unsubscribed to topic.\r\n");
        break;

    case MQTTSN_EVENT_RECEIVED:
        NRF_LOG_INFO("MQTT-SN event: Client received content.\r\n");
        received_callback(p_event);
        break;

    case MQTTSN_EVENT_TIMEOUT:
        NRF_LOG_INFO("MQTT-SN event: Retransmission retries limit has been reached.\r\n");
        timeout_callback(p_event);
        break;

    case MQTTSN_EVENT_SEARCHGW_TIMEOUT:
        NRF_LOG_INFO("MQTT-SN event: Gateway discovery procedure has finished.\r\n");
        searchgw_timeout_callback(p_event);
        break;

    default:
        break;
    }
}

/**@brief Function for initializing the MQTTSN client.
 */
static void mqttsn_init(void)
{
    uint32_t err_code = mqttsn_client_init(&m_client,
                                           MQTTSN_DEFAULT_CLIENT_PORT,
                                           mqttsn_evt_handler,
                                           get_thread_instance());
    APP_ERROR_CHECK(err_code);

    connect_opt_init();
}

void mqttsn_publish(uint8_t payload[], uint16_t payload_len)
{
    uint32_t err_code = mqttsn_client_publish(&m_client, m_topic.topic_id, payload, payload_len, &m_msg_id);

    if (err_code != NRF_SUCCESS)
    {
        NRF_LOG_ERROR("PUBLISH message could not be sent. Error code: 0x%x\r\n", err_code)
    }
}
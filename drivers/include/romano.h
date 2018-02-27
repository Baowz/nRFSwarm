#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_TOPIC_NAME            "nRFSwarm/common"
// ROMANO message types

#define NORMAL_DATA                   0x00
#define MQTT_SUBSCRIBE                0x01
#define MQTT_UNSUBSCRIBE              0x02
#define MQTT_PUBLISH_REQUEST          0x03
#define MOVEMENT_CONTROL              0x04
#define SENSOR_DATA                   0x05
#define REQUEST_CONNECTED_NODES_INFO  0x06
#define CONNECTED_NODES_INFO          0x07
#define HEARTBEAT_MESSAGE             0x08


// Movement control types

#define MOVE_FRONT    0x00
#define MOVE_BACK     0x01
#define MOVE_LEFT     0x02
#define MOVE_RIGHT    0x03
#define ROTATE_LEFT   0x04
#define ROTATE_RIGHT  0x05

// Prototypes

void romano_message_received(uint8_t * p_data);
void romano_init(mqttsn_client_t *m_client);

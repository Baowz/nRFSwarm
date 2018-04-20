#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// ROMANO message types

#define NORMAL_DATA                   '0'
#define MOVEMENT_CONTROL              '1'
#define REQUEST_SENSOR_DATA           '2'
#define SENSOR_DATA                   '3'
#define REQUEST_CONNECTED_NODES_INFO  '4'
#define CONNECTED_NODES_INFO          '5'
#define HEARTBEAT_MESSAGE             '6'
#define ALGORITHM_CONTROL             '7'

// Movement control types (To be used when compass is added)

#define HEADING        '0'
#define SPEED          '1'
#define DIRECT_CONTROL '2'

// Size of different message types

#define SIZE_CONNECTED_NODES_INFO 14
#define SIZE_SENSOR_DATA          20

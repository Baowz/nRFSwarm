#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Dropout value

#define DROP_OUT_VALUE  100
#define NUMBER_OF_NODES 10


//Prototypes for functions used externally

int8_t crc_filter(int8_t *RSSI_values, uint16_t id, int8_t rssi, uint8_t crc);

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static void mqttsn_init(void);

void mqttsn_publish(uint8_t payload[], uint16_t payload_len);
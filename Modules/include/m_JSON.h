#include <stdbool.h>
#include <stdint.h>

#include "cJSON.h"

void data_parser(uint16_t _address, char _data_type, uint16_t _data, char *p_out);
void location_parser(uint16_t _address, int16_t _x_cor, int16_t _y_cor, char *p_out);

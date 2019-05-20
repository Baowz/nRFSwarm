#include <stdbool.h>
#include <stdint.h>

#include "cJSON.h"

#include "m_JSON.h"

// example on predefined parsers with variable input
void location_parser(uint16_t _address, int16_t _x_cor, int16_t _y_cor, char *p_out)
{
    cJSON *root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "addr", _address);
    cJSON_AddNumberToObject(root, "x", _x_cor);
    cJSON_AddNumberToObject(root, "y", _y_cor);
    p_out = cJSON_Print(root);
    cJSON_Delete(root);
}

void data_parser(uint16_t _address, char _data_type, uint16_t _data, char *p_out)
{
    cJSON *root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "addr", _address);
    cJSON_AddNumberToObject(root, &_data_type, _data);
    p_out = cJSON_Print(root);
    cJSON_Delete(root);
}
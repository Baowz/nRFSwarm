#include <stdbool.h>
#include <stdint.h>

#define VALUE_R1 1500
#define VALUE_R2 180

#define VOLTAGE_DIVIDER_VALUE VALUE_R2/(VALUE_R2+VALUE_R1)

uint32_t battery_value(void);
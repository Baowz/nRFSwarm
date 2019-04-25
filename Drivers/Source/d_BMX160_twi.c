#include <stdint.h>
#include <stdbool.h>

#include "d_BMX160_RegisterMap.h"

#include "d_BMX160_twi.h"
#include "d_twi.h"

#include "nrf_gpiote.h"

status_code_t BMX160_INIT(void)
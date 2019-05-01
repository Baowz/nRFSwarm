#include <stdint.h>
#include <stdbool.h>

#include "m_batt_meas.h"
#include "d_swarm_board.h"
#include "nrf_gpio.h"
#include "nordic_common.h"

uint32_t battery_value(void){
    uint32_t bat_val;
    nrf_gpio_pin_set(BAT_MON_ENABLE_PIN);
    bat_val = nrf_gpio_pin_read(BAT_MON_PIN);
    nrf_gpio_pin_clear(BAT_MON_ENABLE_PIN);
    return bat_val;
}
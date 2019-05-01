#include <stdint.h>

#include "nrf_gpio.h"

#include "d_swarm_board.h"
#include "config.h"

void board_init(void){
    #if SECONDARY_CHIP

    #else
    nrf_gpio_cfg_output(BAT_MON_ENABLE_PIN);
    nrf_gpio_cfg_input(BAT_MON_PIN, NRF_GPIO_PIN_NOPULL);
    #endif
}
#include <stdint.h>
#include <stdbool.h>

#include "app_error.h"
#include "nrfx_twim.h"


#include "d_swarm_board.h"
#include "d_twi.h"


nrfx_twim_config_t sensor_twi_conf = {
    .scl = SCL_PIN,
    .sda = SDA_PIN,
    .frequency = NRF_TWIM_FREQ_100K,
    .interrupt_priority = NRFX_TWIM_DEFAULT_CONFIG_IRQ_PRIORITY,                    \
    .hold_bus_uninit    = NRFX_TWIM_DEFAULT_CONFIG_HOLD_BUS_UNINIT,
};

nrfx_twim_t twi_0 = NRFX_TWIM_INSTANCE(0);


void twi_init(){
    APP_ERROR_CHECK(nrfx_twim_init(&twi_0, &sensor_twi_conf, NULL, NULL));
    nrfx_twim_enable(&twi_0);
}
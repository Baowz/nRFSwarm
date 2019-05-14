#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "nrf_gpio.h"
#include "nrfx_gpiote.h"
#include "m_motor.h"

#include "d_encoder.h"

static int32_t ticks_a = 0;
static int32_t ticks_b = 0;

void encoder_a_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    if (nrf_gpio_pin_read(ENCODERA_DIR_PIN))
    {
        ticks_a++;
    }
    else
    {
        ticks_a--;
    }
}

void encoder_b_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    if (nrf_gpio_pin_read(ENCODERB_DIR_PIN))
    {
        ticks_a++;
    }
    else
    {
        ticks_a--;
    }
}

void encoder_init(void)
{
    nrf_gpio_cfg_input(ENCODERA_DIR_PIN, NRF_GPIO_PIN_NOPULL);
    nrf_gpio_cfg_input(ENCODERB_DIR_PIN, NRF_GPIO_PIN_NOPULL);

    nrfx_gpiote_in_config_t encoder_in_conf = NRFX_GPIOTE_CONFIG_IN_SENSE_LOTOHI(1);

    APP_ERROR_CHECK(nrfx_gpiote_init());

    APP_ERROR_CHECK(nrfx_gpiote_in_init(ENCODERA_INT_PIN, &encoder_in_conf, encoder_a_handler));
    APP_ERROR_CHECK(nrfx_gpiote_in_init(ENCODERB_INT_PIN, &encoder_in_conf, encoder_b_handler));
}

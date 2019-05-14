#include <stdbool.h>
#include <stdint.h>

#include "nrfx_uarte.h"
#include "config.h"

#include "m_uart.h"

nrfx_uarte_t uarte_0_inst = NRFX_UARTE_INSTANCE(0);

void uart_init(void)
{
#if SECONDARY_CHIP
    nrfx_uarte_config_t uarte_config = {
        .pseltxd = 5,
        .pselrxd = 6,
        .pselcts = 7,
        .pselrts = 8,
        .p_context = NULL,
        .hwfc = (nrf_uarte_hwfc_t)NRFX_UARTE_DEFAULT_CONFIG_HWFC,
        .parity = (nrf_uarte_parity_t)NRFX_UARTE_DEFAULT_CONFIG_PARITY,
        .baudrate = (nrf_uarte_baudrate_t)NRFX_UARTE_DEFAULT_CONFIG_BAUDRATE,
        .interrupt_priority = NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY,
    };
#else
    nrfx_uarte_config_t uarte_config = {
        .pseltxd = 5,
        .pselrxd = 6,
        .pselcts = 7,
        .pselrts = 8,
        .p_context = NULL,
        .hwfc = (nrf_uarte_hwfc_t)NRFX_UARTE_DEFAULT_CONFIG_HWFC,
        .parity = (nrf_uarte_parity_t)NRFX_UARTE_DEFAULT_CONFIG_PARITY,
        .baudrate = (nrf_uarte_baudrate_t)NRFX_UARTE_DEFAULT_CONFIG_BAUDRATE,
        .interrupt_priority = NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY,
    };
#endif
    APP_ERROR_CHECK(nrfx_uarte_init(&uarte_0_inst, &uarte_config, NULL));
}

void uart_rx(uint8_t *data)
{
    APP_ERROR_CHECK(nrfx_uarte_rx(&uarte_0_inst, data, 4));
}

void uart_tx(uint8_t *data)
{
    APP_ERROR_CHECK(nrfx_uarte_tx(&uarte_0_inst, data, 4));
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "nrf_drv_spi.h"
#include "nrfx_spim.h"
#include "app_error.h"
#include "app_util_platform.h"
#include "nrf_log.h"

#include "m_spi.h"


static const nrfx_spim_t spi_shield  = NRFX_SPIM_INSTANCE(0);

static uint8_t SPI_data_rx;
static uint8_t _tx_buf;
static uint8_t rx_data;

void spi_transfer(nrfx_spim_t *spi_instance, uint8_t tx_data)
{
  _tx_buf = tx_data;
  static nrfx_spim_xfer_desc_t simp_transf_desc = //NRFX_SPIM_SINGLE_XFER(tx_data, lengthof(tx_data), rx_data, 8);
  {
    .p_tx_buffer = &_tx_buf,
    .tx_length   = 8,
    .p_rx_buffer = &rx_data,
    .rx_length   = 8
  };
  APP_ERROR_CHECK(nrfx_spim_xfer(&spi_instance, &simp_transf_desc, 0));
}

void spi_init(void)
{
  ret_code_t err_code;

  nrfx_spim_config_t shield_config = {
    .sck_pin  = SHIELD_SPI_SCK_PIN,
    .mosi_pin = SHIELD_SPI_MOSI_PIN,
    .miso_pin = SHIELD_SPI_MISO_PIN,
    .ss_pin   = SHIELD_SPI_CS_PIN,
    .irq_priority = SPI_DEFAULT_CONFIG_IRQ_PRIORITY,
    .orc = 0xFF,
    .frequency = NRF_SPI_FREQ_4M,
    .mode = NRF_SPI_MODE_0,
    .bit_order = NRF_SPI_BIT_ORDER_MSB_FIRST,
  };

  err_code = nrfx_spim_init(&spi_shield, &shield_config, NULL, NULL);
  APP_ERROR_CHECK(err_code);

  NRF_LOG_RAW_INFO("[SUCCESS] SPI enabled for shield interface. \n")
}

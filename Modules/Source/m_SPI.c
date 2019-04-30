#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "nrf_drv_spi.h"
#include "nrfx_spi.h"
#include "app_error.h"
#include "app_util_platform.h"
#include "nrf_log.h"

#include "m_spi.h"

//static const nrf_drv_spi_t spi_sensory = NRF_DRV_SPI_INSTANCE(1);
static const nrfx_spi_t spi_shield  = NRFX_SPI_INSTANCE(0);

void spi_transfer(nrfx_spi_t *spi_instance, uint8_t tx_data, uint8_t rx_data)
{
  APP_ERROR_CHECK(nrf_drv_spi_transfer(&spi_instance, tx_data, sizeof(tx_data), rx_data, sizeof(rx_data)));
}

void spi_init(void)
{
  ret_code_t err_code;

  /*nrf_drv_spi_config_t sensory_config = {
    .sck_pin  = SENSORY_SPI_SCK_PIN,
    .mosi_pin = SENSORY_SPI_MOSI_PIN,
    .miso_pin = SENSORY_SPI_MISO_PIN,
    .ss_pin   = SENSORY_SPI_CS_PIN,
    .irq_priority = SPI_DEFAULT_CONFIG_IRQ_PRIORITY,
    .orc = 0xFF,
    .frequency = NRF_DRV_SPI_FREQ_4M,
    .mode = NRF_DRV_SPI_MODE_0,
    .bit_order = NRF_DRV_SPI_BIT_ORDER_MSB_FIRST,
  }; */

  nrfx_spi_config_t shield_config = {
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

  /*err_code = nrf_drv_spi_init(&spi_sensory, &sensory_config, NULL, NULL);
  APP_ERROR_CHECK(err_code);*/

  err_code = nrfx_spi_init(&spi_shield, &shield_config, NULL, NULL);
  APP_ERROR_CHECK(err_code);

  NRF_LOG_RAW_INFO("[SUCCESS] SPI enabled for shield interface. \n")
}

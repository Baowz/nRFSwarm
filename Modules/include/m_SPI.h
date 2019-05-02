#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "nrfx_spim.h"

#include "pca10056.h"

#define SHIELD_SPI_SCK_PIN      NRF_GPIO_PIN_MAP(0,27)
#define SHIELD_SPI_MOSI_PIN     NRF_GPIO_PIN_MAP(0,2)
#define SHIELD_SPI_MISO_PIN     NRF_GPIO_PIN_MAP(0,26)
#define SHIELD_SPI_CS_PIN       NRF_GPIO_PIN_MAP(1,13)


void spi_init(void);
void spi_transfer(nrfx_spim_t *spi_instance, uint8_t tx_data);
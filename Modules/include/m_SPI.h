#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "nrf_drv_spi.h"

#include "pca10056.h"

#define SENSORY_SPI_SCK_PIN     ARDUINO_0_PIN
#define SENSORY_SPI_MOSI_PIN    ARDUINO_6_PIN
#define SENSORY_SPI_MISO_PIN    ARDUINO_2_PIN
#define SENSORY_SPI_CS_PIN      ARDUINO_4_PIN

#define SHIELD_SPI_SCK_PIN      27
#define SHIELD_SPI_MOSI_PIN     5
#define SHIELD_SPI_MISO_PIN     7
#define SHIELD_SPI_CS_PIN       ARDUINO_7_PIN //TODO: Check if I could just number this with 30 something instead. This is not pretty.

// Prototypes used externally by other parts of the program

void spi_init(void);
void spi_tranfer(nrf_drv_spi_t *spi_instance, uint8_t tx_data, uint8_t rx_data);
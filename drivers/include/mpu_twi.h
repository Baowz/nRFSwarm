#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "pca10056.h"

#define MPU_SCL_PIN ARDUINO_3_PIN
#define MPU_SDA_PIN ARDUINO_1_PIN


// Prototypes used in twi.c

// Initializes the twi driver
void mpu_twi_init(void);

// Writes data on the twi-channel, returns 0 if successful

uint8_t twi_write(uint8_t slave_addr, uint8_t reg_addr, uint8_t length, uint8_t* data);

// Reads data on the twi-channel, returns 0 if successful

uint8_t twi_read(uint8_t slave_addr, uint8_t reg_addr, uint8_t length, uint8_t* data);

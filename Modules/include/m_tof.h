#include <stdbool.h>
#include <stdint.h>

#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"
//#include "d_swarm_board.h"
#include "nrf_gpio.h"

#define VL53L0X_TWI_ADDRESS_DEFAULT 0x29

#define VL53L0X_TWI_ADDRESS_1 0x29
#define VL53L0X_TWI_ADDRESS_2 0x30
#define VL53L0X_TWI_ADDRESS_3 0x31
#define VL53L0X_TWI_ADDRESS_4 0x32
#define VL53L0X_TWI_ADDRESS_5 0x33
#define VL53L0X_TWI_ADDRESS_6 0x34
#define VL53L0X_TWI_ADDRESS_7 0x35
#define VL53L0X_TWI_ADDRESS_8 0x36

#define XSHUT_PIN_1 NRF_GPIO_PIN_MAP(1,8)
#define XSHUT_PIN_2 NRF_GPIO_PIN_MAP(1,10)
#define XSHUT_PIN_3 NRF_GPIO_PIN_MAP(1,0)
#define XSHUT_PIN_4 NRF_GPIO_PIN_MAP(0,11)
#define XSHUT_PIN_5 NULL
#define XSHUT_PIN_6 NULL
#define XSHUT_PIN_7 NULL
#define XSHUT_PIN_8 NULL

#define TOF_NUMBER_OF_SENSORS 4

#define WAKE_UP_TIME 10
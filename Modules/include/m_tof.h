#include <stdbool.h>
#include <stdint.h>

#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"
#include "d_swarm_board.h"

#define VL53L0X_TWI_ADDRESS_DEFAULT 0x29

#define VL53L0X_TWI_ADDRESS_1 0x29
#define VL53L0X_TWI_ADDRESS_2 0x30
#define VL53L0X_TWI_ADDRESS_3 0x31
#define VL53L0X_TWI_ADDRESS_4 0x32
#define VL53L0X_TWI_ADDRESS_5 0x33
#define VL53L0X_TWI_ADDRESS_6 0x34
#define VL53L0X_TWI_ADDRESS_7 0x35
#define VL53L0X_TWI_ADDRESS_8 0x36

#define XSHUT_PIN_1 MOD_CS_1_PIN
#define XSHUT_PIN_2 MOD_CS_2_PIN
#define XSHUT_PIN_3 MOD_CS_3_PIN
#define XSHUT_PIN_4 MOD_CS_4_PIN
#define XSHUT_PIN_5 MOD_CS_5_PIN
#define XSHUT_PIN_6 MOD_CS_6_PIN
#define XSHUT_PIN_7 MOD_CS_7_PIN
#define XSHUT_PIN_8 MOD_CS_8_PIN

#define WAKE_UP_TIME 10
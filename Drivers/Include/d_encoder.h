#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "d_swarm_board.h"
////////////////////////////////
////////Encoder settings////////
#define WHEEL_DIAMETER 39 //In MM
#define ENCODER_COUNT  12 //Number of times the encoder counts per revolution.
#define PI 3.14159265359
#define CIRCUMFERENCE  WHEEL_DIAMETER*PI
#define COUNT_DISTANCE CIRCUMFERENCE/ENCODER_COUNT

#define ENCODERA_LEFT  MOTOR_ENCODER_A1_PIN
#define ENCODERB_LEFT  MOTOR_ENCODER_B1_PIN
#define ENCODERA_RIGHT MOTOR_ENCODER_A2_PIN
#define ENCODERB_RIGHT MOTOR_ENCODER_B2_PIN

nrf_gpio_cfg_input(ENCODERA_LEFT);
nrf_gpio_cfg_input(ENCODERB_LEFT);
nrf_gpio_cfg_input(ENCODERA_RIGHT);
nrf_gpio_cfg_input(ENCODERB_RIGHT);


void count_ticks(ENCODERA_LEFT, ENCODERA_RIGHT);
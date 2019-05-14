#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "d_swarm_board.h"

#define WHEEL_DIAMETER 39 //In MM
#define ENCODER_COUNT 12  //Number of times the encoder counts per revolution.
#define PI 3.14159265359
#define CIRCUMFERENCE WHEEL_DIAMETER *PI
#define COUNT_DISTANCE CIRCUMFERENCE / ENCODER_COUNT

#define ENCODERA_INT_PIN GPIO_1_PIN
#define ENCODERA_DIR_PIN GPIO_2_PIN
#define ENCODERB_INT_PIN GPIO_3_PIN
#define ENCODERB_DIR_PIN GPIO_4_PIN

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "nrf_gpio.h"

#include "d_swarm_board.h"

#define PWM_PIN_A MOTOR_PWM_A_PIN
#define PWM_PIN_B MOTOR_PWM_B_PIN
#define MOTOR_PIN_A1 MOTOR_AIN_1_PIN
#define MOTOR_PIN_A2 MOTOR_AIN_2_PIN
#define MOTOR_PIN_B1 MOTOR_BIN_1_PIN
#define MOTOR_PIN_B2 MOTOR_BIN_2_PIN

typedef struct
{
  bool motor0forward;
  bool motor1forward;
} motor_direction_t;

typedef struct
{
  uint16_t speedA;
  uint16_t speedB;
} motor_speed_t;

void motor_direction(motor_direction_t *direction);
void motor_speed(motor_speed_t *speed);
void init_motor_pwm(void);

void motor_run(void);


#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MOTOR_A_PWM_OUTPUT_PIN 14
#define MOTOR_B_PWM_OUTPUT_PIN 25
#define MOTOR_AIN1             19
#define MOTOR_AIN2             16
#define MOTOR_BIN1             21
#define MOTOR_BIN2             23

#define PWM_TOP_VALUE 1000 // Counting to 1000, 16kHz
#define PRINT_PWM 0

typedef struct
{
  float output_motor_a;
  float output_motor_b;

  bool direction_motor_a; // TRUE = CW, FALSE = CCW
  bool direction_motor_b; // TRUE = CW, FALSE = CCW
}motor_t;

void motor_pwm_init(void);
void stop_motors(void);
void update_motor_values(motor_t *motor);

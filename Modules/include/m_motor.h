#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MOTOR_A_PWM_OUTPUT_PIN nrf_gpio_pin_map(0.23)
#define MOTOR_B_PWM_OUTPUT_PIN nrf_gpio_pin_map(0.25)
#define MOTOR_AIN1             nrf_gpio_pin_map(0.20)
#define MOTOR_AIN2             nrf_gpio_pin_map(1.10)
#define MOTOR_BIN1             nrf_gpio_pin_map(1.04)
#define MOTOR_BIN2             nrf_gpio_pin_map(1.03)
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
void update_motor_values(motor_t *motor);
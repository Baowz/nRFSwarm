#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Define Pin for PWM motor control
#define PWM_PIN_0               NRF_GPIO_PIN_MAP(0,04)    // Pin P0.04 Selected
#define PWM_PIN_1               NRF_GPIO_PIN_MAP(0,07)    // Pin P0.04 Selected
#define Motor_PIN_OA            NRF_GPIO_PIN_MAP(0,05)    // Pin P0.04 Selected
#define Motor_PIN_OB            NRF_GPIO_PIN_MAP(0,06)    // Pin P0.04 Selected
#define Motor_PIN_1A            NRF_GPIO_PIN_MAP(0,08)    // Pin P0.04 Selected
#define Motor_PIN_1B            NRF_GPIO_PIN_MAP(0,09)    // Pin P0.04 Selected

typedef struct
{
  float output_motor_a;
  float output_motor_b;

  bool direction_motor_a; // TRUE = CW, FALSE = CCW
  bool direction_motor_b; // TRUE = CW, FALSE = CCW
}motor_values;

void motor_pwm_init(void);
void update_motor_values(motor_t *motor);
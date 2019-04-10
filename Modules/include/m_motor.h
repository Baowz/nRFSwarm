#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Define Pin for PWM motor control
#define PWM_PIN_0               NRF_GPIO_PIN_MAP(0,04)    // Pin P0.04 Selected
#define PWM_PIN_1               NRF_GPIO_PIN_MAP(0,07)    // Pin P0.04 Selected
#define MOTOR_PIN_OA            NRF_GPIO_PIN_MAP(0,28)    // Pin P0.04 Selected
#define MOTOR_PIN_OB            NRF_GPIO_PIN_MAP(0,29)    // Pin P0.04 Selected
#define MOTOR_PIN_1A            NRF_GPIO_PIN_MAP(0,30)    // Pin P0.04 Selected
#define MOTOR_PIN_1B            NRF_GPIO_PIN_MAP(0,31)    // Pin P0.04 Selected

typedef struct
{
  uint8_t motor0throttle;
  uint8_t motor1throttle;

  bool motor0forward; 
  bool motor1forward;
}motor_values_t;

void init_motor_pwm(void);
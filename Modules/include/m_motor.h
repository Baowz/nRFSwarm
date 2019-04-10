#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Define Pin for PWM motor control
#define PWM_PIN_0               NRF_GPIO_PIN_MAP(0,04)    // Pin P0.04 Selected
#define PWM_PIN_1               NRF_GPIO_PIN_MAP(0,07)    // Pin P0.04 Selected
#define MOTOR_PIN_OA            NRF_GPIO_PIN_MAP(0,05)    // Pin P0.04 Selected
#define MOTOR_PIN_OB            NRF_GPIO_PIN_MAP(0,06)    // Pin P0.04 Selected
#define MOTOR_PIN_1A            NRF_GPIO_PIN_MAP(0,08)    // Pin P0.04 Selected
#define MOTOR_PIN_1B            NRF_GPIO_PIN_MAP(0,09)    // Pin P0.04 Selected

typedef struct
{
  uint8_t motor0throttle;
  uint8_t motor1throttle;

  char motor0dir; 
  char motor1dir;
}motor_values_t;

void MOTOR_INIT(void);
void update_motor_values(motor_t *motor);
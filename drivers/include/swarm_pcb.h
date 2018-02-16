#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "pca10056.h"

#define LED_ONE_R_PIN     13
#define LED_ONE_G_PIN     17
#define LED_ONE_B_PIN     15

#define LED_TWO_R_PIN     20
#define LED_TWO_G_PIN     24
#define LED_TWO_B_PIN     22

#define RGB_ONE_DEFAULT_RED     255 // Tomato
#define RGB_ONE_DEFAULT_GREEN   255
#define RGB_ONE_DEFAULT_BLUE    255

#define RGB_TWO_DEFAULT_RED     0 // Tomato
#define RGB_TWO_DEFAULT_GREEN   0
#define RGB_TWO_DEFAULT_BLUE    0

#define PWM_TOP_VALUE     1000 // Counting to 1000, 16kHz

#define GPIO_PIN_ONE     ARDUINO_12_PIN
#define GPIO_PIN_TWO     3
#define GPIO_PIN_THREE   ARDUINO_10_PIN
#define GPIO_PIN_FOUR    ARDUINO_9_PIN

// Prototypes for functions used externally

void pcb_peripherals_init(void);
void rgb_update_led_color(uint8_t led, uint16_t red, uint16_t green, uint16_t blue);

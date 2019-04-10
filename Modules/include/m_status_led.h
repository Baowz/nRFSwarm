/**
 *
 *
 *
 */
#include "config.h"

typedef struct {
    int r;
    int g;
    int b;
    int r_pin;
    int g_pin;
    int b_pin;
}status_led_t;

void status_led_init(status_led_t *status_led, int address_r, int address_g, int address_b);

#if DUAL_CHIP_ENABLE
#if SECONDARY_CHIP

    status_led_t status_led_1;
    status_led_t status_led_2;

#else

    status_led_t status_led;


#endif
#else

    status_led_t status_led;


#endif


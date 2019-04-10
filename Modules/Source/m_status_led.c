/**
 *
 *
 *
 */
#include "m_status_led.h"

void status_led_init(status_led_t *status_led, int address_r, int address_g, int address_b){
    status_led -> r_pin = address_r;
    status_led -> g_pin = address_g;
    status_led -> b_pin = address_b;
    status_led -> r = 0;
    status_led -> g = 0;
    status_led -> b = 0;
}
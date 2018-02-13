#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "nrf_drv_timer.h"

void rtc_init(nrf_drv_timer_t * timer_instance);
uint32_t rtc_get_current_time_ticks(void);
float rtc_get_current_time_ms(void);
float rtc_get_delta_time_sec(float * prev_time);

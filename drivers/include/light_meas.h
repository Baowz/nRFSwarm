#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "pca10056.h"

#define SAMPLES_IN_BUFFER			100					/* The saadc_callback handles the measured ADC data when SAPMLES_IN_BUFFER is full*/
#define COMPARE_EVT_MS				6					/* How often the timer should do a compare event (in milliseconds). SAMPLES_IN_BUFFER * COMPARE_EVT_MS = How often voltage is measured*/


typedef void (*light_mon_cb_t)(float voltage);
void light_sensor_init(light_mon_cb_t callback);

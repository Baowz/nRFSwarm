#include "nrfx_gpiote.h"


#define encoderA_left	    NRF_GPIO_PIN_MAP(0,11) 
#define encoderA_right	    NRF_GPIO_PIN_MAP(0,12) 


typedef struct
{
  uint32_t leftmotorticks;
  uint32_t rightmotorticks;
}encoder_ticks_t;

static encoder_ticks_t encodercounter =
{
.leftmotorticks = 0,
.rightmotorticks = 0,
};

void encoderintnerrupt(nrfx_gpiote_pin_t input,  nrf_gpiote_polarity_t action);
void gpio_init(void);
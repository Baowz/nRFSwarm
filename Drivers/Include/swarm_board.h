/**
 *
 *
 *
 *
 *
 *
 *
 */
#include "config.h"

#define NRF_GPIO_PIN_MAP(port, pin) ((port << 5) | (pin & 0x1F))

#define DUAL_CHIP_UART_RX_PIN NRF_GPIO_PIN_MAP(0,0)
#define DUAL_CHIP_UART_TX_PIN NRF_GPIO_PIN_MAP(0,0)

#ifdef SECONDARY_CHIP
#if SECONDARY_CHIP



#else



#endif
#else

#endif
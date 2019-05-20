#include <stdbool.h>
#include <stdint.h>

/**
 * init function for uarte
 * must be called before using uart
 */
void uart_init(void);

/**
 * void uart_rx(uint8_t *data)
 *
 * simple read function
 * takes in pointer to buffer
 * [IN] = data array, must be atleast 4 in length
 */
void uart_rx(uint8_t *data);

/**
 * void uart_tx(uint8_t *data)
 *
 * simple transfer function
 * takes in pointer to buffer
 * [IN] = data array, must be atleast 4 in length
 */
void uart_tx(uint8_t *data);
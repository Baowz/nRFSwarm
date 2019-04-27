#include <stdint.h>


void twi_init(void);

void twi_tx(uint8_t _addr, uint8_t * p_data, bool _no_stop);
void twi_rx(uint8_t _addr, uint8_t * p_buffer, uint8_t _buffer_size);
void twi_txtx(uint8_t _addr, uint8_t _sec_addr, uint8_t data);
void twi_txrx(uint8_t _addr, uint8_t _sec_addr, uint8_t * p_buffer, uint8_t buffer_size);

/*
void twi_tx(uint8_t _address, uint8_t * p_data);
void twi_rx(uint8_t _address, uint8_t * p_buffer, size_t _buffer_size);
void twi_txtx(uint8_t _address, uint8_t * p_prim_data, uint8_t * p_sec_data);
void twi_txrx(uint8_t _address, uint8_t * p_prim_data, uint8_t * p_buffer, size_t _buffer_size);
*/
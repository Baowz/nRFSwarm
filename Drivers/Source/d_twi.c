#include <stdint.h>
#include <stdbool.h>

#include "app_error.h"
#include "nrfx_twim.h"


#include "d_swarm_board.h"
#include "d_twi.h"



nrfx_twim_t twi_0 = NRFX_TWIM_INSTANCE(0);

static volatile bool m_xfer_done = false;

void twi_init(void){
    nrfx_twim_config_t sensor_twi_conf = {
        .scl = SCL_PIN,
        .sda = SDA_PIN,
        .frequency = NRF_TWIM_FREQ_100K,
        .interrupt_priority = NRFX_TWIM_DEFAULT_CONFIG_IRQ_PRIORITY,
        .hold_bus_uninit    = NRFX_TWIM_DEFAULT_CONFIG_HOLD_BUS_UNINIT,
    };

    APP_ERROR_CHECK(nrfx_twim_init(&twi_0, &sensor_twi_conf, NULL, NULL));

    nrfx_twim_enable(&twi_0);
}

void twi_handler(nrfx_twim_evt_t const * p_event, void * p_context)
{

}

void twi_tx(uint8_t _addr, uint8_t * p_data, bool _no_stop){
    m_xfer_done = false;
    APP_ERROR_CHECK(nrfx_twim_tx(&twi_0, _addr, &p_data, lengthof(p_data), _no_stop));
    while(m_xfer_done == false);
}

void twi_rx(uint8_t _addr, uint8_t * p_buffer, uint8_t _buffer_size){
    m_xfer_done = false;
    APP_ERROR_CHECK(nrfx_twim_rx(&twi_0, _addr, &p_buffer, _buffer_size));
    while(m_xfer_done == false);
}

void twi_txtx(uint8_t _addr, uint8_t _sec_addr, uint8_t data){
    m_xfer_done = false;
    nrfx_err_t err;
    err = nrfx_twim_tx(&twi_0, _addr, _sec_addr, 1, true);
    if( NRF_SUCCESS == err){
        err = nrfx_twim_tx(&twi_0, _addr, data, lengthof(data), false);
    }
    APP_ERROR_CHECK(err);
    while(m_xfer_done == false);
}

void twi_txrx(uint8_t _addr, uint8_t _sec_addr, uint8_t * p_buffer, uint8_t buffer_size){
    m_xfer_done = false;
    nrfx_err_t err;
    err = nrfx_twim_tx(&twi_0, _addr, _sec_addr, 1, true);
    if( NRF_SUCCESS == err){
        err = nrfx_twim_rx(&twi_0, _addr, &p_buffer, buffer_size);
    }
    APP_ERROR_CHECK(err);
    while(m_xfer_done == false);
}

/*
void twi_tx(uint8_t _address, uint8_t * p_data){
    while(nrfx_twim_is_busy(&twi_0)){
        static nrfx_twim_xfer_desc_t tx = {
            .type = NRFX_TWIM_XFER_TX,
            .address = _address,
            .primary_length = lengthof(p_data),
            .p_primary_buf = &p_data
        };

        APP_ERROR_CHECK(nrfx_twim_xfer(&twi_0, *tx, 0));
    }
}

void twi_rx(uint8_t _address, uint8_t * p_buffer, size_t _buffer_size){
    while(nrfx_twim_is_busy(&twi_0)){
        static nrfx_twim_xfer_desc_t rx = {
            .type = NRFX_TWIM_XFER_TX,
            .address = _address,
            .primary_length = _buffer_size,
            .p_primary_buf = &p_buffer
        };

        APP_ERROR_CHECK(nrfx_twim_xfer(&twi_0, *rx, 0));
    }
}

void twi_txtx(uint8_t _address, uint8_t * p_prim_data, uint8_t * p_sec_data){
    while(nrfx_twim_is_busy(&twi_0)){
        static nrfx_twim_xfer_desc_t txtx = {
            .type = NRFX_TWIM_XFER_TXTX,
            .address = _address,
            .primary_length = lengthof(p_prim_data),
            .p_primary_buf = &p_prim_data,
            .secondary_length = lengthof(p_sec_data),
            .p_secondary_buf = &p_sec_data
        };

        APP_ERROR_CHECK(nrfx_twim_xfer(&twi_0, *tx, 0));
    }
}

void twi_txrx(uint8_t _address, uint8_t * p_prim_data, uint8_t * p_buffer, size_t _buffer_size){
    while(nrfx_twim_is_busy(&twi_0)){
        static nrfx_twim_xfer_desc_t txrx= {
            .type = NRFX_TWIM_XFER_TXRX,
            .address = _address,
            .primary_length = lengthof(p_prim_data),
            .p_primary_buf = &p_prim_data,
            .secondary_length = _buffer_size,
            .p_secondary_buf = &p_buffer
        };

        APP_ERROR_CHECK(nrfx_twim_xfer(&twi_0, *tx, 0));
    }
}
*/
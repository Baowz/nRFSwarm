#include <stdint.h>
#include <stdbool.h>

#include "d_BMX160_RegisterMap.h"

#include "d_BMX160_twi.h"
#include "d_twi.h"

#include "nrf_gpiote.h"

#include "nrf_log.h"

BMX160_chipfound = false;


void BMX160_init(void){
    static uint8_t chipid;
    twi_txrx(BMX160_ADDR, BMX160_CHIPID, &chipid, 1);
    if(chipid == BMX160_CHIPID_HEX){
        BMX160_chipfound = true;
    }else{
        NRF_LOG_INFO("BMX160 not found");
    }
}

// magnetometer
void get_mag_x_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA0, &p_buffer, 1);
}

void get_mag_x_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA1, &p_buffer, 1);
}

void get_mag_y_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA2, &p_buffer, 1);
}

void get_mag_y_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA3, &p_buffer, 1);
}

void get_mag_z_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA4, &p_buffer, 1);
}

void get_mag_z_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA5, &p_buffer, 1);
}

// accelerometer
void get_acc_x_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA8, &p_buffer, 1);
}

void get_acc_x_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA9, &p_buffer, 1);
}

void get_acc_y_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA10, &p_buffer, 1);
}

void get_acc_y_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA11, &p_buffer, 1);
}

void get_acc_z_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA12, &p_buffer, 1);
}

void get_acc_z_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA13, &p_buffer, 1);
}

// gyroscope
void get_gyr_x_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA14, &p_buffer, 1);
}

void get_gyr_x_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA15, &p_buffer, 1);
}

void get_gyr_y_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA16, &p_buffer, 1);
}

void get_gyr_y_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA17, &p_buffer, 1);
}

void get_gyr_z_data_low(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA18, &p_buffer, 1);
}

void get_gyr_z_data_high(uint8_t * p_buffer){
    twi_txrx(BMX160_ADDR, BMX160_DATA19, &p_buffer, 1);
}
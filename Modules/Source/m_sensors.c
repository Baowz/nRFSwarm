#include <stdint.h>

#include "d_twi.h"
#include "d_BMX160_twi.h"
#include "config.h"

#include "m_sensors.h"

static struct
{
    uint8_t x_low_data;
    uint8_t x_high_data;
    uint8_t y_low_data;
    uint8_t y_high_data;
    uint8_t z_low_data;
    uint8_t z_high_data;
}mag_data;

static struct
{
    uint8_t x_low_data;
    uint8_t x_high_data;
    uint8_t y_low_data;
    uint8_t y_high_data;
    uint8_t z_low_data;
    uint8_t z_high_data;
}acc_data;

static struct
{
    uint8_t x_low_data;
    uint8_t x_high_data;
    uint8_t y_low_data;
    uint8_t y_high_data;
    uint8_t z_low_data;
    uint8_t z_high_data;
}gyr_data;

void sensors_init(void){
    twi_init();
    #if BMX160_ENABLE
    BMX160_init();
    #endif
}

void update_mag_data(void){
    if (BMX160_chipfound) {
        get_mag_x_data_low(&mag_data.x_low_data);
        get_mag_x_data_high(&mag_data.x_high_data);
        get_mag_y_data_low(&mag_data.y_low_data);
        get_mag_y_data_high(&mag_data.y_high_data);
        get_mag_z_data_low(&mag_data.z_low_data);
        get_mag_z_data_high(&mag_data.z_high_data);
    }
}

void update_acc_data(void){
    if (BMX160_chipfound) {
        get_acc_x_data_low(&acc_data.x_low_data);
        get_acc_x_data_high(&acc_data.x_high_data);
        get_acc_y_data_low(&acc_data.y_low_data);
        get_acc_y_data_high(&acc_data.y_high_data);
        get_acc_z_data_low(&acc_data.z_low_data);
        get_acc_z_data_high(&acc_data.z_high_data);
    }
}

void update_gyr_data(void){
    if (BMX160_chipfound) {
        get_gyr_x_data_low(&gyr_data.x_low_data);
        get_gyr_x_data_high(&gyr_data.x_high_data);
        get_gyr_y_data_low(&gyr_data.y_low_data);
        get_gyr_y_data_high(&gyr_data.y_high_data);
        get_gyr_z_data_low(&gyr_data.z_low_data);
        get_gyr_z_data_high(&gyr_data.z_high_data);
    }
}
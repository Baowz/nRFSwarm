#include <stdint.h>
#include <stdbool.h>

#define BMX160_WRITE_BIT    0x00
#define BMX160_READ_BIT     0x01
#define BMX160_ADDR         0x68

#define BMX160_CHIPID_HEX   0b11011000

#define BMX160_WRITE_ADDR   BMX160_ADDR|BMX160_WRITE_BIT
#define BMX160_READ_ADDR    BMX160_ADDR|BMX160_READ_BIT

void BMX160_init(void);

void get_mag_x_data_low(uint8_t * p_buffer);
void get_mag_x_data_high(uint8_t * p_buffer);
void get_mag_y_data_low(uint8_t * p_buffer);
void get_mag_y_data_high(uint8_t * p_buffer);
void get_mag_z_data_low(uint8_t * p_buffer);
void get_mag_z_data_high(uint8_t * p_buffer);

void get_acc_x_data_low(uint8_t * p_buffer);
void get_acc_x_data_high(uint8_t * p_buffer);
void get_acc_y_data_low(uint8_t * p_buffer);
void get_acc_y_data_high(uint8_t * p_buffer);
void get_acc_z_data_low(uint8_t * p_buffer);
void get_acc_z_data_high(uint8_t * p_buffer);

void get_gyr_x_data_low(uint8_t * p_buffer);
void get_gyr_x_data_high(uint8_t * p_buffer);
void get_gyr_y_data_low(uint8_t * p_buffer);
void get_gyr_y_data_high(uint8_t * p_buffer);
void get_gyr_z_data_low(uint8_t * p_buffer);
void get_gyr_z_data_high(uint8_t * p_buffer);

static bool BMX160_chipfound;

///////// configs ////////////

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "nrf_log.h"

#include "inv_mpu.h"
#include "inv_mpu_dmp.h"

#include "app_mpu.h"
#include "MPU9250_RegisterMap.h"
#include "eulerconversion.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

#include "real_time_clock.h"

bool app_mpu_who_am_i(void)
{
    uint16_t try_count = 0;
    uint8_t tmp_u8;

    do
    {
        if ( (try_count) < 100 )
        {
            ++try_count;
        }
        else
        {
            NRF_LOG_RAW_INFO("[FAIL] MPU not found. Cancelling initiation. \n");
            return false;
        }

    } while ( (mpu_read_reg(0x75, &tmp_u8) != 0)
    ||        (tmp_u8 != 0x71) );


    NRF_LOG_RAW_INFO("[SUCCESS] MPU found at try %d\n", try_count);
    return true;

}

unsigned short app_mpu_fifo_available(void)
{
    unsigned char fifoH, fifoL;

	if (mpu_read_reg(MPU9250_FIFO_COUNTH, &fifoH) != INV_SUCCESS)
		return 0;
	if (mpu_read_reg(MPU9250_FIFO_COUNTL, &fifoL) != INV_SUCCESS)
		return 0;

	return (fifoH << 8 ) | fifoL;
}

inv_error_t app_dmp_enable_features(unsigned short mask)
{
	unsigned short enMask = 0;
	enMask |= mask;
	// Combat known issue where fifo sample rate is incorrect
	// unless tap is enabled in the DMP.
	enMask |= DMP_FEATURE_TAP;
	return dmp_enable_feature(enMask);
}

void app_dmp_load(void)
{
    unsigned short feat = FEATURES;

    if(dmp_load_motion_driver_firmware() == INV_SUCCESS)
    {
        NRF_LOG_RAW_INFO("[SUCCESS] DMP firmware loaded. \n");
    }
    else
    {
        NRF_LOG_RAW_INFO("[FAIL] DMP firmware failed to load. \n")
    return;
    }

    if (feat & DMP_FEATURE_LP_QUAT)
    {
        feat &= ~(DMP_FEATURE_6X_LP_QUAT);
        dmp_enable_lp_quat(1);
    }
    else if (feat & DMP_FEATURE_6X_LP_QUAT)
        dmp_enable_6x_lp_quat(1);

    if (feat & DMP_FEATURE_GYRO_CAL)
        dmp_enable_gyro_cal(1);

    if (app_dmp_enable_features(feat) != INV_SUCCESS)
    {
        NRF_LOG_RAW_INFO("[FAIL] DMP failed to be configured.")
    }
    else
    {
        dmp_set_fifo_rate(DMP_FIFO_RATE);
        mpu_set_dmp_state(1);
        NRF_LOG_RAW_INFO("[SUCCESS] DMP configured. \n");
    }
}

void app_mpu_init(void)
{
    uint8_t result;
    struct int_param_s int_param;

    nrf_gpio_cfg_output(MPU_ADDRESS_PIN);
    nrf_gpio_pin_clear(MPU_ADDRESS_PIN);


    if(!app_mpu_who_am_i()) //If MPU is not found, the initiation is cancelled.
        return;

    result = mpu_init(&int_param);
    if(!result)
    {
        NRF_LOG_RAW_INFO("[SUCCESS] MPU initiated with default values. \n");
    }
    else
    {
        NRF_LOG_RAW_INFO("[FAIL] Failed to initiate MPU properly. \n");
    }

    mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);

    mpu_set_bypass(1);


	#if ENABLE_DMP
		app_dmp_load();
	#endif
}

ret_code_t app_mpu_get_angles(float *measurement, float *accel)
{
    static FIFO_t FIFO;
    if(app_mpu_fifo_available())
    {
        app_mpu_dmp_update_fifo(&FIFO);
        compute_euler(FIFO.quat, FIFO.rpy);

        memcpy(measurement, FIFO.rpy, 12);
        memcpy(accel, FIFO.accel, 12);
        #if PRINT_ANGLE_VALUES
            NRF_LOG_RAW_INFO("Angles: roll "NRF_LOG_FLOAT_MARKER" - pitch "NRF_LOG_FLOAT_MARKER" - yaw "NRF_LOG_FLOAT_MARKER" \n", NRF_LOG_FLOAT(FIFO.rpy[0]), NRF_LOG_FLOAT(FIFO.rpy[1]), NRF_LOG_FLOAT(FIFO.rpy[2]));
        #endif

        #if PRINT_PITCH_ANGLE
            NRF_LOG_RAW_INFO("pitch "NRF_LOG_FLOAT_MARKER"  \n", NRF_LOG_FLOAT(FIFO.rpy[1]));
        #endif

        #if PRINT_ACCELEROMETER_DATA
            NRF_LOG_RAW_INFO("Acceleration: X: %7d \t Y: %7d \t Z: %7d \n", FIFO.accel[0], FIFO.accel[1], FIFO.accel[2]);
        #endif

        #if PRINT_ACCELEROMETER_GRAPH_DATA
            NRF_LOG_RAW_INFO("%d %d %d \r", FIFO.accel[0], FIFO.accel[1], FIFO.accel[2]);
        #endif

        return NRF_SUCCESS;

    }
    else
    {
        #if APP_MPU_PRINT_ERRORS
            NRF_LOG_RAW_INFO("FIFO is not available. \n")
        #endif

        return 1;
    }
}

void app_mpu_dmp_update_fifo(FIFO_t* FIFO)
{
    dmp_read_fifo(FIFO->gyro, FIFO->accel, FIFO->quat, &FIFO->timestamp, &FIFO->sensors, &FIFO->more);
}

float app_mpu_exp_moving_avg(short new_measurement, short prev_avg, float alpha)
{
    return (short)(alpha * (float)new_measurement + (1 - alpha) * (float)prev_avg);
}

void app_mpu_get_ms(unsigned long *count)
{
    *count = (unsigned long)rtc_get_current_time_ms();
}

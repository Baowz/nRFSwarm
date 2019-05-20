#ifndef d_CCS811_REGISTER_MAP_H_
#define d_CCS811_REGISTER_MAP_H_

enum CCS811_bootloader_register{
    CCS811_bootloader_status = 0x00,
    CCS811_bootloader_hw_id = 0x20,
    CCS811_bootloader_hw_version = 0x21,
    CCS811_bootloader_fw_boot_version = 0x23,
    CCS811_bootloader_fw_app_version = 0x24,
    CCS811_bootloader_error_id = 0xE0,
    CCS811_bootloader_app_erase = 0xF1,
    CCS811_bootloader_app_data = 0xF2,
    CCS811_bootloader_app_verify = 0xF3,
    CCS811_bootloader_app_start = 0xF4,
    CCS811_bootloader_sw_reset = 0xFF
};

enum CCS811_application_register{
    CCS811_application_status = 0x00,
    CCS811_application_meas_mode = 0x01,
    CCS811_application_alg_result_data = 0x02,
    CCS811_application_raw_data = 0x03,
    CCS811_application_env_data = 0x05,
    CCS811_application_ntc = 0x06,
    CCS811_application_thresholds = 0x10,
    CCS811_application_baseline = 0x11,
    CCS811_application_hw_id = 0x20,
    CCS811_application_hw_version = 0x21,
    CCS811_application_fw_boot_version = 0x23,
    CCS811_application_fw_app_version = 0x24,
    CCS811_application_error_id = 0xE0,
    CCS811_application_sw_reset = 0xFF
};

enum CCS811_status_bits{
    CCS811_status_error = 0,
    CCS811_status_data_ready = 3,
    CCS811_status_app_valid = 4,
    CCS811_status_fw_mode = 7
};

enum CCS811_meas_mode{
    CCS811_meas_mode_thresh = 2,
    CCS811_meas_mode_interrupt = 3,
    CCS811_meas_mode_drive_mode = 4
};
#define CCS811_MEAS_MODE_DRIVE_MODE_MASK = 0x07


#endif
#ifndef d_HTS221_REGISTER_MAP_H_
#define d_HTS221_REGISTER_MAP_H_

enum HTS221_register{
    HTS221_who_am_i = 0x0F,
    HTS221_av_conf = 0x10,
    HTS221_ctrl_reg_1 = 0x20,
    HTS221_ctrl_reg_2 = 0x21,
    HTS221_ctrl_reg_3 = 0x22,
    HTS221_status_reg = 0x27,
    HTS221_humidity_out_l = 0x28,
    HTS221_humidity_out_h = 0x29,
    HTS221_temp_out_l = 0x2A,
    HTS221_temp_out_h = 0x2B,
    HTS221_calib_0 = 0x30,
    HTS221_calib_1 = 0x31,
    HTS221_calib_2 = 0x32,
    HTS221_calib_3 = 0x33,
    HTS221_calib_4 = 0x34,
    HTS221_calib_5 = 0x35,
    HTS221_calib_6 = 0x36,
    HTS221_calib_7 = 0x37,
    HTS221_calib_8 = 0x38,
    HTS221_calib_9 = 0x39,
    HTS221_calib_A = 0x3A,
    HTS221_calib_B = 0x3B,
    HTS221_calib_C = 0x3C,
    HTS221_calib_D = 0x3D,
    HTS221_calib_E = 0x3E,
    HTS221_calib_F = 0x3F
};

enum HTS221_av_conf_bits{
    HTS221_av_conf_avgh = 0,
    HTS221_av_conf_avgt = 3
};
#define HTS221_AV_CONF_AVGH 0x07
#define HTS221_AV_CONF_AVGT 0x07

enum HTS221_ctrl_reg_1_bits{
    HTS221_ctrl_reg_1_odr = 0,
    HTS221_ctrl_reg_1_bdu = 2,
    HTS221_ctrl_reg_1_pd  = 7
};
#define HTS221_CTRL_REG_1_ODR 0x03

enum HTS221_ctrl_reg_2_bits{
    HTS221_ctrl_reg_2_one_shot = 0,
    HTS221_ctrl_reg_2_heater   = 1,
    HTS221_ctrl_reg_2_boot     = 7
};

enum HTS221_ctrl_reg_3_bits{
    HTS221_ctrl_reg_3_drdy      = 2,
    HTS221_ctrl_reg_3_pp_od     = 6,
    HTS221_ctrl_reg_3_drdy_h_l  = 7
};

enum HTS221_status_reg_bits{
    HTS221_status_reg_t_da = 0,
    HTS221_status_reg_h_da = 1
};
#endif
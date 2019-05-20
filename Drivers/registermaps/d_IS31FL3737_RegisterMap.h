#ifndef D_IS31FL3737_REGISTER_MAP_H_
#define D_IS31FL3737_REGISTER_MAP_H_

/////register for the twi page register//////
enum IS31FL3737_page_register{
    IS31FL3737_led_control_register_address = 0x00,
    IS31FL3737_pwm_register_address         = 0x01,
    IS31FL3737_ABM_address                  = 0x02,
    IS31FL3737_function_register_address    = 0x03
};
/////register for page 0 led controll register///
enum IS31FL3737_led_control_register{
    // led on/off 0x00 to 0x17
    IS31FL3737_led_on_off_sw1_cs1_cs6,
    IS31FL3737_led_on_off_sw1_cs7_cs12,
    IS31FL3737_led_on_off_sw2_cs1_cs6,
    IS31FL3737_led_on_off_sw2_cs7_cs12,
    IS31FL3737_led_on_off_sw3_cs1_cs6,
    IS31FL3737_led_on_off_sw3_cs7_cs12,
    IS31FL3737_led_on_off_sw4_cs1_cs6,
    IS31FL3737_led_on_off_sw4_cs7_cs12,
    IS31FL3737_led_on_off_sw5_cs1_cs6,
    IS31FL3737_led_on_off_sw5_cs7_cs12,
    IS31FL3737_led_on_off_sw6_cs1_cs6,
    IS31FL3737_led_on_off_sw6_cs7_cs12,
    IS31FL3737_led_on_off_sw7_cs1_cs6,
    IS31FL3737_led_on_off_sw7_cs7_cs12,
    IS31FL3737_led_on_off_sw8_cs1_cs6,
    IS31FL3737_led_on_off_sw8_cs7_cs12,
    IS31FL3737_led_on_off_sw9_cs1_cs6,
    IS31FL3737_led_on_off_sw9_cs7_cs12,
    IS31FL3737_led_on_off_sw10_cs1_cs6,
    IS31FL3737_led_on_off_sw10_cs7_cs12,
    IS31FL3737_led_on_off_sw11_cs1_cs6,
    IS31FL3737_led_on_off_sw11_cs7_cs12,
    IS31FL3737_led_on_off_sw12_cs1_cs6,
    IS31FL3737_led_on_off_sw12_cs7_cs12,
    // led open 0x18 to 0x2F
    IS31FL3737_led_open_sw1_cs1_cs6,
    IS31FL3737_led_open_sw1_cs7_cs12,
    IS31FL3737_led_open_sw2_cs1_cs6,
    IS31FL3737_led_open_sw2_cs7_cs12,
    IS31FL3737_led_open_sw3_cs1_cs6,
    IS31FL3737_led_open_sw3_cs7_cs12,
    IS31FL3737_led_open_sw4_cs1_cs6,
    IS31FL3737_led_open_sw4_cs7_cs12,
    IS31FL3737_led_open_sw5_cs1_cs6,
    IS31FL3737_led_open_sw5_cs7_cs12,
    IS31FL3737_led_open_sw6_cs1_cs6,
    IS31FL3737_led_open_sw6_cs7_cs12,
    IS31FL3737_led_open_sw7_cs1_cs6,
    IS31FL3737_led_open_sw7_cs7_cs12,
    IS31FL3737_led_open_sw8_cs1_cs6,
    IS31FL3737_led_open_sw8_cs7_cs12,
    IS31FL3737_led_open_sw9_cs1_cs6,
    IS31FL3737_led_open_sw9_cs7_cs12,
    IS31FL3737_led_open_sw10_cs1_cs6,
    IS31FL3737_led_open_sw10_cs7_cs12,
    IS31FL3737_led_open_sw11_cs1_cs6,
    IS31FL3737_led_open_sw11_cs7_cs12,
    IS31FL3737_led_open_sw12_cs1_cs6,
    IS31FL3737_led_open_sw12_cs7_cs12,
    // led short 0x30 to 0x47
    IS31FL3737_led_short_sw1_cs1_cs6,
    IS31FL3737_led_short_sw1_cs7_cs12,
    IS31FL3737_led_short_sw2_cs1_cs6,
    IS31FL3737_led_short_sw2_cs7_cs12,
    IS31FL3737_led_short_sw3_cs1_cs6,
    IS31FL3737_led_short_sw3_cs7_cs12,
    IS31FL3737_led_short_sw4_cs1_cs6,
    IS31FL3737_led_short_sw4_cs7_cs12,
    IS31FL3737_led_short_sw5_cs1_cs6,
    IS31FL3737_led_short_sw5_cs7_cs12,
    IS31FL3737_led_short_sw6_cs1_cs6,
    IS31FL3737_led_short_sw6_cs7_cs12,
    IS31FL3737_led_short_sw7_cs1_cs6,
    IS31FL3737_led_short_sw7_cs7_cs12,
    IS31FL3737_led_short_sw8_cs1_cs6,
    IS31FL3737_led_short_sw8_cs7_cs12,
    IS31FL3737_led_short_sw9_cs1_cs6,
    IS31FL3737_led_short_sw9_cs7_cs12,
    IS31FL3737_led_short_sw10_cs1_cs6,
    IS31FL3737_led_short_sw10_cs7_cs12,
    IS31FL3737_led_short_sw11_cs1_cs6,
    IS31FL3737_led_short_sw11_cs7_cs12,
    IS31FL3737_led_short_sw12_cs1_cs6,
    IS31FL3737_led_short_sw12_cs7_cs12
};

enum IS31FL3737_pwm_register{
    IS31FL3737_pwm_led_1_A  = 0x00,
    IS31FL3737_pwm_led_2_A  = 0x01,
    IS31FL3737_pwm_led_3_A  = 0x02,
    IS31FL3737_pwm_led_4_A  = 0x03,
    IS31FL3737_pwm_led_5_A  = 0x04,
    IS31FL3737_pwm_led_6_A  = 0x05,
    IS31FL3737_pwm_led_7_A  = 0x08,
    IS31FL3737_pwm_led_8_A  = 0x09,
    IS31FL3737_pwm_led_9_A  = 0x0A,
    IS31FL3737_pwm_led_10_A = 0x0B,
    IS31FL3737_pwm_led_11_A = 0x0C,
    IS31FL3737_pwm_led_12_A = 0x0D,

    IS31FL3737_pwm_led_1_B  = 0x10,
    IS31FL3737_pwm_led_2_B  = 0x11,
    IS31FL3737_pwm_led_3_B  = 0x12,
    IS31FL3737_pwm_led_4_B  = 0x13,
    IS31FL3737_pwm_led_5_B  = 0x14,
    IS31FL3737_pwm_led_6_B  = 0x15,
    IS31FL3737_pwm_led_7_B  = 0x18,
    IS31FL3737_pwm_led_8_B  = 0x19,
    IS31FL3737_pwm_led_9_B  = 0x1A,
    IS31FL3737_pwm_led_10_B = 0x1B,
    IS31FL3737_pwm_led_11_B = 0x1C,
    IS31FL3737_pwm_led_12_B = 0x1D,

    IS31FL3737_pwm_led_1_C  = 0x20,
    IS31FL3737_pwm_led_2_C  = 0x21,
    IS31FL3737_pwm_led_3_C  = 0x22,
    IS31FL3737_pwm_led_4_C  = 0x23,
    IS31FL3737_pwm_led_5_C  = 0x24,
    IS31FL3737_pwm_led_6_C  = 0x25,
    IS31FL3737_pwm_led_7_C  = 0x28,
    IS31FL3737_pwm_led_8_C  = 0x29,
    IS31FL3737_pwm_led_9_C  = 0x2A,
    IS31FL3737_pwm_led_10_C = 0x2B,
    IS31FL3737_pwm_led_11_C = 0x2C,
    IS31FL3737_pwm_led_12_C = 0x2D,

    IS31FL3737_pwm_led_1_D  = 0x30,
    IS31FL3737_pwm_led_2_D  = 0x31,
    IS31FL3737_pwm_led_3_D  = 0x32,
    IS31FL3737_pwm_led_4_D  = 0x33,
    IS31FL3737_pwm_led_5_D  = 0x34,
    IS31FL3737_pwm_led_6_D  = 0x35,
    IS31FL3737_pwm_led_7_D  = 0x38,
    IS31FL3737_pwm_led_8_D  = 0x39,
    IS31FL3737_pwm_led_9_D  = 0x3A,
    IS31FL3737_pwm_led_10_D = 0x3B,
    IS31FL3737_pwm_led_11_D = 0x3C,
    IS31FL3737_pwm_led_12_D = 0x3D,

    IS31FL3737_pwm_led_1_E  = 0x40,
    IS31FL3737_pwm_led_2_E  = 0x41,
    IS31FL3737_pwm_led_3_E  = 0x42,
    IS31FL3737_pwm_led_4_E  = 0x43,
    IS31FL3737_pwm_led_5_E  = 0x44,
    IS31FL3737_pwm_led_6_E  = 0x45,
    IS31FL3737_pwm_led_7_E  = 0x48,
    IS31FL3737_pwm_led_8_E  = 0x49,
    IS31FL3737_pwm_led_9_E  = 0x4A,
    IS31FL3737_pwm_led_10_E = 0x4B,
    IS31FL3737_pwm_led_11_E = 0x4C,
    IS31FL3737_pwm_led_12_E = 0x4D,

    IS31FL3737_pwm_led_1_F  = 0x50,
    IS31FL3737_pwm_led_2_F  = 0x51,
    IS31FL3737_pwm_led_3_F  = 0x52,
    IS31FL3737_pwm_led_4_F  = 0x53,
    IS31FL3737_pwm_led_5_F  = 0x54,
    IS31FL3737_pwm_led_6_F  = 0x55,
    IS31FL3737_pwm_led_7_F  = 0x58,
    IS31FL3737_pwm_led_8_F  = 0x59,
    IS31FL3737_pwm_led_9_F  = 0x5A,
    IS31FL3737_pwm_led_10_F = 0x5B,
    IS31FL3737_pwm_led_11_F = 0x5C,
    IS31FL3737_pwm_led_12_F = 0x5D,

    IS31FL3737_pwm_led_1_G  = 0x60,
    IS31FL3737_pwm_led_2_G  = 0x61,
    IS31FL3737_pwm_led_3_G  = 0x62,
    IS31FL3737_pwm_led_4_G  = 0x63,
    IS31FL3737_pwm_led_5_G  = 0x64,
    IS31FL3737_pwm_led_6_G  = 0x65,
    IS31FL3737_pwm_led_7_G  = 0x68,
    IS31FL3737_pwm_led_8_G  = 0x69,
    IS31FL3737_pwm_led_9_G  = 0x6A,
    IS31FL3737_pwm_led_10_G = 0x6B,
    IS31FL3737_pwm_led_11_G = 0x6C,
    IS31FL3737_pwm_led_12_G = 0x6D,

    IS31FL3737_pwm_led_1_H  = 0x70,
    IS31FL3737_pwm_led_2_H  = 0x71,
    IS31FL3737_pwm_led_3_H  = 0x72,
    IS31FL3737_pwm_led_4_H  = 0x73,
    IS31FL3737_pwm_led_5_H  = 0x74,
    IS31FL3737_pwm_led_6_H  = 0x75,
    IS31FL3737_pwm_led_7_H  = 0x78,
    IS31FL3737_pwm_led_8_H  = 0x79,
    IS31FL3737_pwm_led_9_H  = 0x7A,
    IS31FL3737_pwm_led_10_H = 0x7B,
    IS31FL3737_pwm_led_11_H = 0x7C,
    IS31FL3737_pwm_led_12_H = 0x7D,

    IS31FL3737_pwm_led_1_I  = 0x80,
    IS31FL3737_pwm_led_2_I  = 0x81,
    IS31FL3737_pwm_led_3_I  = 0x82,
    IS31FL3737_pwm_led_4_I  = 0x83,
    IS31FL3737_pwm_led_5_I  = 0x84,
    IS31FL3737_pwm_led_6_I  = 0x85,
    IS31FL3737_pwm_led_7_I  = 0x88,
    IS31FL3737_pwm_led_8_I  = 0x89,
    IS31FL3737_pwm_led_9_I  = 0x8A,
    IS31FL3737_pwm_led_10_I = 0x8B,
    IS31FL3737_pwm_led_11_I = 0x8C,
    IS31FL3737_pwm_led_12_I = 0x8D,

    IS31FL3737_pwm_led_1_J  = 0x90,
    IS31FL3737_pwm_led_2_J  = 0x91,
    IS31FL3737_pwm_led_3_J  = 0x92,
    IS31FL3737_pwm_led_4_J  = 0x93,
    IS31FL3737_pwm_led_5_J  = 0x94,
    IS31FL3737_pwm_led_6_J  = 0x95,
    IS31FL3737_pwm_led_7_J  = 0x98,
    IS31FL3737_pwm_led_8_J  = 0x99,
    IS31FL3737_pwm_led_9_J  = 0x9A,
    IS31FL3737_pwm_led_10_J = 0x9B,
    IS31FL3737_pwm_led_11_J = 0x9C,
    IS31FL3737_pwm_led_12_J = 0x9D,

    IS31FL3737_pwm_led_1_K  = 0xA0,
    IS31FL3737_pwm_led_2_K  = 0xA1,
    IS31FL3737_pwm_led_3_K  = 0xA2,
    IS31FL3737_pwm_led_4_K  = 0xA3,
    IS31FL3737_pwm_led_5_K  = 0xA4,
    IS31FL3737_pwm_led_6_K  = 0xA5,
    IS31FL3737_pwm_led_7_K  = 0xA8,
    IS31FL3737_pwm_led_8_K  = 0xA9,
    IS31FL3737_pwm_led_9_K  = 0xAA,
    IS31FL3737_pwm_led_10_K = 0xAB,
    IS31FL3737_pwm_led_11_K = 0xAC,
    IS31FL3737_pwm_led_12_K = 0xAD,

    IS31FL3737_pwm_led_1_L  = 0xB0,
    IS31FL3737_pwm_led_2_L  = 0xB1,
    IS31FL3737_pwm_led_3_L  = 0xB2,
    IS31FL3737_pwm_led_4_L  = 0xB3,
    IS31FL3737_pwm_led_5_L  = 0xB4,
    IS31FL3737_pwm_led_6_L  = 0xB5,
    IS31FL3737_pwm_led_7_L  = 0xB8,
    IS31FL3737_pwm_led_8_L  = 0xB9,
    IS31FL3737_pwm_led_9_L  = 0xBA,
    IS31FL3737_pwm_led_10_L = 0xBB,
    IS31FL3737_pwm_led_11_L = 0xBC,
    IS31FL3737_pwm_led_12_L = 0xBD
};

enum IS31FL3737_ABM_register{
    IS31FL3737_ABM_1_A  = 0x00,
    IS31FL3737_ABM_2_A  = 0x01,
    IS31FL3737_ABM_3_A  = 0x02,
    IS31FL3737_ABM_4_A  = 0x03,
    IS31FL3737_ABM_5_A  = 0x04,
    IS31FL3737_ABM_6_A  = 0x05,
    IS31FL3737_ABM_7_A  = 0x08,
    IS31FL3737_ABM_8_A  = 0x09,
    IS31FL3737_ABM_9_A  = 0x0A,
    IS31FL3737_ABM_10_A = 0x0B,
    IS31FL3737_ABM_11_A = 0x0C,
    IS31FL3737_ABM_12_A = 0x0D,

    IS31FL3737_ABM_1_B  = 0x10,
    IS31FL3737_ABM_2_B  = 0x11,
    IS31FL3737_ABM_3_B  = 0x12,
    IS31FL3737_ABM_4_B  = 0x13,
    IS31FL3737_ABM_5_B  = 0x14,
    IS31FL3737_ABM_6_B  = 0x15,
    IS31FL3737_ABM_7_B  = 0x18,
    IS31FL3737_ABM_8_B  = 0x19,
    IS31FL3737_ABM_9_B  = 0x1A,
    IS31FL3737_ABM_10_B = 0x1B,
    IS31FL3737_ABM_11_B = 0x1C,
    IS31FL3737_ABM_12_B = 0x1D,

    IS31FL3737_ABM_1_C  = 0x20,
    IS31FL3737_ABM_2_C  = 0x21,
    IS31FL3737_ABM_3_C  = 0x22,
    IS31FL3737_ABM_4_C  = 0x23,
    IS31FL3737_ABM_5_C  = 0x24,
    IS31FL3737_ABM_6_C  = 0x25,
    IS31FL3737_ABM_7_C  = 0x28,
    IS31FL3737_ABM_8_C  = 0x29,
    IS31FL3737_ABM_9_C  = 0x2A,
    IS31FL3737_ABM_10_C = 0x2B,
    IS31FL3737_ABM_11_C = 0x2C,
    IS31FL3737_ABM_12_C = 0x2D,

    IS31FL3737_ABM_1_D  = 0x30,
    IS31FL3737_ABM_2_D  = 0x31,
    IS31FL3737_ABM_3_D  = 0x32,
    IS31FL3737_ABM_4_D  = 0x33,
    IS31FL3737_ABM_5_D  = 0x34,
    IS31FL3737_ABM_6_D  = 0x35,
    IS31FL3737_ABM_7_D  = 0x38,
    IS31FL3737_ABM_8_D  = 0x39,
    IS31FL3737_ABM_9_D  = 0x3A,
    IS31FL3737_ABM_10_D = 0x3B,
    IS31FL3737_ABM_11_D = 0x3C,
    IS31FL3737_ABM_12_D = 0x3D,

    IS31FL3737_ABM_1_E  = 0x40,
    IS31FL3737_ABM_2_E  = 0x41,
    IS31FL3737_ABM_3_E  = 0x42,
    IS31FL3737_ABM_4_E  = 0x43,
    IS31FL3737_ABM_5_E  = 0x44,
    IS31FL3737_ABM_6_E  = 0x45,
    IS31FL3737_ABM_7_E  = 0x48,
    IS31FL3737_ABM_8_E  = 0x49,
    IS31FL3737_ABM_9_E  = 0x4A,
    IS31FL3737_ABM_10_E = 0x4B,
    IS31FL3737_ABM_11_E = 0x4C,
    IS31FL3737_ABM_12_E = 0x4D,

    IS31FL3737_ABM_1_F  = 0x50,
    IS31FL3737_ABM_2_F  = 0x51,
    IS31FL3737_ABM_3_F  = 0x52,
    IS31FL3737_ABM_4_F  = 0x53,
    IS31FL3737_ABM_5_F  = 0x54,
    IS31FL3737_ABM_6_F  = 0x55,
    IS31FL3737_ABM_7_F  = 0x58,
    IS31FL3737_ABM_8_F  = 0x59,
    IS31FL3737_ABM_9_F  = 0x5A,
    IS31FL3737_ABM_10_F = 0x5B,
    IS31FL3737_ABM_11_F = 0x5C,
    IS31FL3737_ABM_12_F = 0x5D,

    IS31FL3737_ABM_1_G  = 0x60,
    IS31FL3737_ABM_2_G  = 0x61,
    IS31FL3737_ABM_3_G  = 0x62,
    IS31FL3737_ABM_4_G  = 0x63,
    IS31FL3737_ABM_5_G  = 0x64,
    IS31FL3737_ABM_6_G  = 0x65,
    IS31FL3737_ABM_7_G  = 0x68,
    IS31FL3737_ABM_8_G  = 0x69,
    IS31FL3737_ABM_9_G  = 0x6A,
    IS31FL3737_ABM_10_G = 0x6B,
    IS31FL3737_ABM_11_G = 0x6C,
    IS31FL3737_ABM_12_G = 0x6D,

    IS31FL3737_ABM_1_H  = 0x70,
    IS31FL3737_ABM_2_H  = 0x71,
    IS31FL3737_ABM_3_H  = 0x72,
    IS31FL3737_ABM_4_H  = 0x73,
    IS31FL3737_ABM_5_H  = 0x74,
    IS31FL3737_ABM_6_H  = 0x75,
    IS31FL3737_ABM_7_H  = 0x78,
    IS31FL3737_ABM_8_H  = 0x79,
    IS31FL3737_ABM_9_H  = 0x7A,
    IS31FL3737_ABM_10_H = 0x7B,
    IS31FL3737_ABM_11_H = 0x7C,
    IS31FL3737_ABM_12_H = 0x7D,

    IS31FL3737_ABM_1_I  = 0x80,
    IS31FL3737_ABM_2_I  = 0x81,
    IS31FL3737_ABM_3_I  = 0x82,
    IS31FL3737_ABM_4_I  = 0x83,
    IS31FL3737_ABM_5_I  = 0x84,
    IS31FL3737_ABM_6_I  = 0x85,
    IS31FL3737_ABM_7_I  = 0x88,
    IS31FL3737_ABM_8_I  = 0x89,
    IS31FL3737_ABM_9_I  = 0x8A,
    IS31FL3737_ABM_10_I = 0x8B,
    IS31FL3737_ABM_11_I = 0x8C,
    IS31FL3737_ABM_12_I = 0x8D,

    IS31FL3737_ABM_1_J  = 0x90,
    IS31FL3737_ABM_2_J  = 0x91,
    IS31FL3737_ABM_3_J  = 0x92,
    IS31FL3737_ABM_4_J  = 0x93,
    IS31FL3737_ABM_5_J  = 0x94,
    IS31FL3737_ABM_6_J  = 0x95,
    IS31FL3737_ABM_7_J  = 0x98,
    IS31FL3737_ABM_8_J  = 0x99,
    IS31FL3737_ABM_9_J  = 0x9A,
    IS31FL3737_ABM_10_J = 0x9B,
    IS31FL3737_ABM_11_J = 0x9C,
    IS31FL3737_ABM_12_J = 0x9D,

    IS31FL3737_ABM_1_K  = 0xA0,
    IS31FL3737_ABM_2_K  = 0xA1,
    IS31FL3737_ABM_3_K  = 0xA2,
    IS31FL3737_ABM_4_K  = 0xA3,
    IS31FL3737_ABM_5_K  = 0xA4,
    IS31FL3737_ABM_6_K  = 0xA5,
    IS31FL3737_ABM_7_K  = 0xA8,
    IS31FL3737_ABM_8_K  = 0xA9,
    IS31FL3737_ABM_9_K  = 0xAA,
    IS31FL3737_ABM_10_K = 0xAB,
    IS31FL3737_ABM_11_K = 0xAC,
    IS31FL3737_ABM_12_K = 0xAD,

    IS31FL3737_ABM_1_L  = 0xB0,
    IS31FL3737_ABM_2_L  = 0xB1,
    IS31FL3737_ABM_3_L  = 0xB2,
    IS31FL3737_ABM_4_L  = 0xB3,
    IS31FL3737_ABM_5_L  = 0xB4,
    IS31FL3737_ABM_6_L  = 0xB5,
    IS31FL3737_ABM_7_L  = 0xB8,
    IS31FL3737_ABM_8_L  = 0xB9,
    IS31FL3737_ABM_9_L  = 0xBA,
    IS31FL3737_ABM_10_L = 0xBB,
    IS31FL3737_ABM_11_L = 0xBC,
    IS31FL3737_ABM_12_L = 0xBD
};

enum IS31FL3737_function_register{
    IS31FL3737_config_register                  = 0x00,
    IS31FL3737_global_current_control_register  = 0x01,
    IS31FL3737_ABM_1_control_register_1         = 0x02,
    IS31FL3737_ABM_1_control_register_2         = 0x03,
    IS31FL3737_ABM_1_control_register_3         = 0x04,
    IS31FL3737_ABM_1_control_register_4         = 0x05,
    IS31FL3737_ABM_2_control_register_1         = 0x06,
    IS31FL3737_ABM_2_control_register_2         = 0x07,
    IS31FL3737_ABM_2_control_register_3         = 0x08,
    IS31FL3737_ABM_2_control_register_4         = 0x09,
    IS31FL3737_ABM_3_control_register_1         = 0x0A,
    IS31FL3737_ABM_3_control_register_2         = 0x0B,
    IS31FL3737_ABM_3_control_register_3         = 0x0C,
    IS31FL3737_ABM_3_control_register_4         = 0x0D,
    IS31FL3737_time_update_register             = 0x0E,
    IS31FL3737_sw_pullup_selection_register     = 0x0F,
    IS31FL3737_cs_pulldown_selection_register   = 0x10,
    IS31FL3737_reset_register                   = 0x11
};

enum IS31FL3737_config_bits{
    IS31FL3737_config_ssd   = 0,
    IS31FL3737_config_b_en  = 1,
    IS31FL3737_config_osd   = 2,
    IS31FL3737_config_sync  = 6
};
#define IS31FL3737_CONFIG_SYNC_MASK 0x03

enum IS31FL3737_ABM_1_control_register_1_bits{
    IS31FL3737_ABM_1_T2 = 1,
    IS31FL3737_ABM_1_T1 = 5
};
#define IS31FL3737_ABM_1_T2_MASK 0x0F
#define IS31FL3737_ABM_1_T1_MASK 0x07

enum IS31FL3737_ABM_1_control_register_2_bits{
    IS31FL3737_ABM_1_T4 = 1,
    IS31FL3737_ABM_1_T3 = 5
};
#define IS31FL3737_ABM_1_T4_MASK 0x0F
#define IS31FL3737_ABM_1_T3_MASK 0x07

enum IS31FL3737_ABM_1_control_register_3_bits{
    IS31FL3737_ABM_1_lta    = 0,
    IS31FL3737_ABM_1_lb     = 4,
    IS31FL3737_ABM_1_le     = 6
};
#define IS31FL3737_ABM_1_lta_MASK 0x0F
#define IS31FL3737_ABM_1_lb_MASK 0x03
#define IS31FL3737_ABM_1_le_MASK 0x03

enum IS31FL3737_ABM_2_control_register_1_bits{
    IS31FL3737_ABM_2_T2 = 1,
    IS31FL3737_ABM_2_T1 = 5
};
#define IS31FL3737_ABM_2_T2_MASK 0x0F
#define IS31FL3737_ABM_2_T1_MASK 0x07

enum IS31FL3737_ABM_2_control_register_2_bits{
    IS31FL3737_ABM_2_T4 = 1,
    IS31FL3737_ABM_2_T3 = 5
};
#define IS31FL3737_ABM_2_T4_MASK 0x0F
#define IS31FL3737_ABM_2_T3_MASK 0x07

enum IS31FL3737_ABM_2_control_register_3_bits{
    IS31FL3737_ABM_2_lta    = 0,
    IS31FL3737_ABM_2_lb     = 4,
    IS31FL3737_ABM_2_le     = 6
};
#define IS31FL3737_ABM_2_lta_MASK 0x0F
#define IS31FL3737_ABM_2_lb_MASK 0x03
#define IS31FL3737_ABM_2_le_MASK 0x03

enum IS31FL3737_ABM_3_control_register_1_bits{
    IS31FL3737_ABM_3_T2 = 1,
    IS31FL3737_ABM_3_T1 = 5
};
#define IS31FL3737_ABM_3_T2_MASK 0x0F
#define IS31FL3737_ABM_3_T1_MASK 0x07

enum IS31FL3737_ABM_3_control_register_2_bits{
    IS31FL3737_ABM_3_T4 = 1,
    IS31FL3737_ABM_3_T3 = 5
};
#define IS31FL3737_ABM_3_T4_MASK 0x0F
#define IS31FL3737_ABM_3_T3_MASK 0x07

enum IS31FL3737_ABM_3_control_register_3_bits{
    IS31FL3737_ABM_3_lta    = 0,
    IS31FL3737_ABM_3_lb     = 4,
    IS31FL3737_ABM_3_le     = 6
};
#define IS31FL3737_ABM_3_lta_MASK 0x0F
#define IS31FL3737_ABM_3_lb_MASK 0x03
#define IS31FL3737_ABM_3_le_MASK 0x03

#define IS31FL3737_SW_PULLUP_SELECTION_MASK 0x07
#define IS31FL3737_CS_PULLDOWN_SELECTION_MASK 0x07


#endif
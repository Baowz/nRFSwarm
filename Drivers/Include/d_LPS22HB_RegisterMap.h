#ifndef D_LPS22HB_REGISTER_MAP_H_
#define D_LPS22HB_REGISTER_MAP_H_

enum LPS22HB_register {
    LPS22HB_interrupt_cfg   = 0x0B,
    LPS22HB_ths_p_l         = 0x0C,
    LPS22HB_ths_p_h         = 0x0D,
    LPS22HB_who_am_i        = 0x0F,
    LPS22HB_ctrl_reg_1      = 0x10,
    LPS22HB_ctrl_reg_2      = 0x11,
    LPS22HB_ctrl_reg_3      = 0x12,
    LPS22HB_fifo_ctrl       = 0x14,
    LPS22HB_ref_p_xl        = 0x15,
    LPS22HB_ref_p_l         = 0x16,
    LPS22HB_ref_p_h         = 0x17,
    LPS22HB_rpds_l          = 0x18,
    LPS22HB_rpds_h          = 0x19,
    LPS22HB_res_conf        = 0x1A,
    LPS22HB_int_source      = 0x25,
    LPS22HB_fifo_status     = 0x26,
    LPS22HB_status          = 0x27,
    LPS22HB_press_out_xl    = 0x28,
    LPS22HB_press_out_l     = 0x29,
    LPS22HB_press_out_h     = 0x2A,
    LPS22HB_temp_out_l      = 0x2B,
    LPS22HB_temp_out_h      = 0x2C,
    LPS22HB_lpfp_res        = 0x33
};

enum LPS22HB_interrupt_cfg_bits{
    LPS22HB_interrupt_cfg_phe       = 0,
    LPS22HB_interrupt_cfg_ple       = 1,
    LPS22HB_interrupt_cfg_lir       = 2,
    LPS22HB_interrupt_cfg_diff_en   = 3,
    LPS22HB_interrupt_cfg_reset_az  = 4,
    LPS22HB_interrupt_cfg_autozero  = 5,
    LPS22HB_interrupt_cfg_reset_app = 6,
    LPS22HB_interrupt_cfg_autorifp  = 7
};

enum LPS22HB_ctrl_reg_1_bits{
    LPS22HB_ctrl_reg_1_sim      = 0,
    LPS22HB_ctrl_reg_1_bdu      = 1,
    LPS22HB_ctrl_reg_1_lpfp_cfg = 2,
    LPS22HB_ctrl_reg_1_en_lpfp  = 3,
    LPS22HB_ctrl_reg_1_odr      = 4
};
#define LPS22HB_CTRL_REG_1_ODR_MASK 0x07

enum LPS22HB_ctrl_reg_2_bits{
    LPS22HB_ctrl_reg_2_one_shot    = 0,
    LPS22HB_ctrl_reg_2_swreset     = 2,
    LPS22HB_ctrl_reg_2_i2c_dis     = 3,
    LPS22HB_ctrl_reg_2_if_add_inc  = 4,
    LPS22HB_ctrl_reg_2_stop_on_fth = 5,
    LPS22HB_ctrl_reg_2_fifo_en     = 6,
    LPS22HB_ctrl_reg_2_boot        = 7
};

enum LPS22HB_ctrl_reg_3_bits{
    LPS22HB_ctrl_reg_3_int_s    = 0,
    LPS22HB_ctrl_reg_3_drdy     = 2,
    LPS22HB_ctrl_reg_3_f_ovr    = 3,
    LPS22HB_ctrl_reg_3_f_fth    = 4,
    LPS22HB_ctrl_reg_3_f_fss5   = 5,
    LPS22HB_ctrl_reg_3_pp_od    = 6,
    LPS22HB_ctrl_reg_3_int_h_l  = 7
};
#define LPS22HB_CTRL_REG_3_INT_S_MASK 0x03

enum LPS22HB_fifo_ctrl_bits{
    LPS22HB_fifo_ctrl_wtm    = 0,
    LPS22HB_fifo_ctrl_f_mode = 5
};
#define LPS22HB_FIFO_CTRL_WTM_MASK    0x0F
#define LPS22HB_FIFO_CTRL_F_MODE_MASK 0x07

enum LPS22HB_res_conf_bits{
    LPS22HB_res_conf_lc_en = 0
};

enum LPS22HB_int_source_bits{
    LPS22HB_int_source_ph       = 0,
    LPS22HB_int_source_pl       = 1,
    LPS22HB_int_source_ia       = 2,
    LPS22HB_int_source_boot     = 7
};

enum LPS22HB_fifo_status_bits{
    LPS22HB_fifo_status_fss         = 0,
    LPS22HB_fifo_status_ovr         = 6,
    LPS22HB_fifo_status_fth_fifo    = 7,
};
#define LPS22HB_FIFO_STATUS_FSS_MASK 0x3F

enum LPS22HB_status_bits{
    LPS22HB_status_p_da = 0,
    LPS22HB_status_t_da = 1,
    LPS22HB_status_p_or = 4,
    LPS22HB_status_t_or = 5
};
#endif
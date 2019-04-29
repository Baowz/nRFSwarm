#include <stdbool.h>
#include <stdint.h>

#include "nrf_log.h"
#include "d_LPS22HB_twi.h"
#include "d_LPS22HB_RegisterMap.h"

void LPS22HB_init(void){
    static uint8_t chipid;
    twi_txrx(LPS22HB_ADDR, LPS22HB_who_am_i, &chipid, 1);
    if (chipid == LPS22HB_CHIPID) {
        LPS22HB_chipfound = true;
        LPS22HB_settings();
    }else
    {
        NRF_LOG_INFO("LPS22HB not found")
    }
}

void LPS22HB_settings(void){

}

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "app_scheduler.h"
#include "app_timer.h"
#include "nrf_log.h"

#include "thread_utils.h"
#include <openthread/thread.h>
#include "bsp_thread.h"

static void state_changed_callback(uint32_t flags, void *p_context)
{
    NRF_LOG_INFO("State changed! Flags: 0x%08x Current role: %d\r\n",
                 flags, otThreadGetDeviceRole(p_context));
}

static void thread_instance_init(void)
{
    thread_configuration_t thread_configuration =
        {
            .radio_mode = THREAD_RADIO_MODE_RX_ON_WHEN_IDLE,
            .autocommissioning = true,
        };

    thread_init(&thread_configuration);
    thread_cli_init();
    thread_state_changed_callback_set(state_changed_callback);
}

void process_thread_stack(void)
{
    thread_process();
}

otInstance * get_thread_instance(void)
{
    return thread_ot_instance_get();
}
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "thread_utils.h"

static void thread_instance_init(void);

void process_thread_stack(void);

otInstance * get_thread_instance(void);
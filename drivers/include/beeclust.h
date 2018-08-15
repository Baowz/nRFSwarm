#include <stdint.h>
#include <stdbool.h>

#define MAX_LIGHT_VALUE 50.0f
#define LIGHT_TOLERANCE 5.0f

#define BEECLUST_RESET  200
#define START_SEARCH    201
#define STOP_SEARCH     202

typedef void (*pub_cb_t)(uint8_t data);

// Prototypes used externally

bool beeclust_check(float delta_time, bool stop_motors, float light_percentage);
void beeclust_data_update(uint8_t data);
void beeclust_init(pub_cb_t publish_callback);

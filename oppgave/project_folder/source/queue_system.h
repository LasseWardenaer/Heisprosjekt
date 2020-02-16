#ifndef QUEUE_SYSTEM
#define QUEUE_SYSTEM

#include "stdbool.h"

struct queue_system{
    bool floor_1_down = false;
    bool floor_1_up = false;
    bool floor_2_down = false;
    bool floor_2_up = false;
    bool floor_3_down = false;
    bool floor_3_up = false;
    bool floor_4_down = false;
    bool floor_4_up = false;
};

/**
 * @brief Check if the elevator should stop at a floor
 * @return 1 if the elevator should stop at a floor
 */

bool queue_system_check_if_stop();

#endif
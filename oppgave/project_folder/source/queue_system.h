#ifndef QUEUE_SYSTEM
#define QUEUE_SYSTEM

#include "stdbool.h"

/**
 * @brief Updates the queue list
 */

void queue_system_update(int* floor_states[]);
/**
 * @brief Check if the elevator should stop at a floor
 * @return 1 if the elevator should stop at a floor
 */

bool queue_system_check_if_stop();

#endif

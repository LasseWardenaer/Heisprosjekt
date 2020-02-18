#ifndef QUEUE_SYSTEM
#define QUEUE_SYSTEM

#include <stdbool.h>

/**
 * @brief Updates the queue list
 */

void queue_system_update(int* floor_states[]);
/**
 * @brief Check if the elevator should stop at a floor
 * @return 1 if the elevator should stop at a floor
 */

bool queue_system_check_if_stop();

/**
 * @brief Clears all orders if stop button is pressed.
 * @return void
 */

void queue_system_clear_all_orders();

#endif

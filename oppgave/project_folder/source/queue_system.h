#ifndef QUEUE_SYSTEM
#define QUEUE_SYSTEM


#include "hardware.h"

/**
 * @brief Evaluates whether there are any new orders and
 */

void queue_system_check_for_orders();

/**
 * @brief Check if there are any orders above the current floor.
 * @return 1 if the elevator has any orders above the current floor.
 */

int queue_system_check_above();

/**
 * @brief Check if there are any orders below the current floor.
 * @return 1 if the elevator has any orders below the current floor.
 */

int queue_system_check_below();

/**
 * @brief Check if the elevator should stop at a floor
 * @return 1 if the elevator should stop at a floor
 */

void queue_system_check_if_stop();

/**
 * @brief Clears all orders if stop button is pressed.
 * @return void
 */

void queue_system_clear_all_orders();

/**
 * @brief Gets the last visited floor.
 * @return The last floor number.
 */

floor_enum queue_system_return_floor();

/**
 * @brief Updates the floor light when the elevator reaches a new floor
 *
 */

void queue_system_update_floor_ligths();

/**
 * @brief Updates the state of the elevator
 */

void queue_system_set_state();

/**
 * @brief Checks if the elevator is between two floors. 
 * @return 1 if the elevator is between two floors.
 */

int queue_system_is_between_floor();

#endif

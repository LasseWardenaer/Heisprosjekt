#ifndef QUEUE_SYSTEM
#define QUEUE_SYSTEM

#include <stdbool.h>
#include "hardware.h"

void queue_system_check_for_orders(bool** order_state);

bool check_above(bool **order_state, floor_enum current_floor);

bool check_below(bool **order_state, floor_enum current_floor);

/**
 * @brief Updates the queue list
 */

void queue_system_update_outside(int* floor_states[], floor_enum floor, direction dir);

void queue_system_update_inside(int* floor_states[]);
/**
 * @brief Check if the elevator should stop at a floor
 * @return 1 if the elevator should stop at a floor
 */

bool queue_system_check_if_stop(elevator_state_machine* state, floor_enum current_floor, int** order_state);

/**
 * @brief Clears all orders if stop button is pressed.
 * @return void
 */

void queue_system_clear_all_orders();

/**
 * @brief Gets the last visited floor.
 * @return The last floor number.
 */

floor_enum queue_system_return_floor(floor_enum current_floor);

/**
 * @brief Updates the floor light when the elevator reaches a new floor
 *
 */

void queue_system_update_floor_ligths(floor_enum current_floor);

/**
 * @brief Updates the floor light when the elevator reaches a new floor
 * @return Floor light pushed
 */

/**
 * @brief Set order light at floor on or off.
 * @param floor Selected floor.
 * @param dir Sets the direction of the light.
 * @param on_off Sets the light state on or off.
 */


void queue_system_set_queue_and_light();

/**
 * @brief Sets the floor lights insde the elevator
 */

void queue_system_set_queue_and_light_inside_elevator();

#endif

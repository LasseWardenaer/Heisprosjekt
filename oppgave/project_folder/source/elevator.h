/**
 * @file
 * @brief This is the elevator module
 */
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "enums.h"
#include "hardware.h"
#include <unistd.h>

/**
 * @brief Initilaizes the elvator during start up sequence.
 */

void elevator_init();

/**
 * @brief Checks if the stop button is pressed.
 * @return void
 */

void elevator_stop_pressed();

/**
 * @brief Sets the movement of the elevator which is decided by the state. 
 * @return void
 */

void elevator_move();

/**
 * @brief Clears all the order lights, both at the floor and in the elevator.
 * @return void
 */

void elevator_clear_all_order_lights();

/**
 * @brief Opens and closes the door, while checking for obstructions and waiting 3 seconds.
 * @return void
 */

void elevator_door_handler();

/**
 * @brief Handles emergency stop.
 * @return void
 */

void elevator_emergency_stop_handler();

/**
 * @brief Runs the elevator.
 * @return void
 */

void elevator_run();

#endif
/**
 * @file
 * @brief This is an elevator module
 */
#pragma once
#include "enums.h"
#include "hardware.h"
#include <unistd.h>

#define NUMBER_OF_FLOORS 4
#define NUMBER_OF_BUTTONS 3

/**
 * @brief Initilizes the elvator during start up sequence.
 */

void elevator_init();

/**
 * @brief Checks if the stop button is pressed.
 * @return void
 */

void elevator_stop_pressed();

/**
 * @brief Sets the movement of the elevator which is decided by the state. 
 */

void elevator_move();

/**
 * @brief Clears all the lights, both at the floor and in the elevator.
 */

void clear_all_order_lights();

/**
 * @brief Opens and closes the door, while checking for obstructions.
 */

void elevator_door_handler();

/**
 * @brief Handles emergency stop.
 */

void elevator_emergency_stop_handler();
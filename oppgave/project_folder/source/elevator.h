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
 * @brief Elevator struct that holds variables
 */

struct Elevator{
    floor_enum next_floor;
    int door_closed;
    direction movement_dir;
    int stop_pushed;
    int light_on[5];
};

/**
 * @brief Initilizes the elvator during start up sequence.
 */

void elevator_init();

/**
 * @brief Moves the elevator to selected floor of type floor.
 * @param floor_variable Input variable of type floor.
 * @return void
 */

// void elevator_go_to_floor(floor_enum floor_variable, floor_enum current_floor, HardwareOrder order_type);

/**
 * @brief Closes door.
 * @return void
 */

void elevator_close_door();

/**
 * @brief Opens door.
 * @return void
 */

void elevator_open_door();

// /**
//  * @brief Turns the selected light off.
//  * @param light_variable Input variable og type floor.
//  * @return void
//  */

// void elevator_light_off(light ligth_variable);

// /**
//  * @brief Turns the selected light off.
//  * @param light_variable Input variable og type floor.
//  * @return void
//  */

// void elevator_light_on(light light_variable);

/**
 * @brief Checks if the stop button is pressed.
 * @return void
 */

void elevator_if_stop_pressed();

void elevator_move();

void clear_all_order_lights();

int elevator_order_in_current_floor();
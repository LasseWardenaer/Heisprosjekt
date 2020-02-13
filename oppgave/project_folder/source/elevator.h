/**
 * @file
 * @brief This is an elevator module
 */
#pragma once
#include "enums.h"
#include "hardware.h"
#include <unistd.h>



/**
 * @brief Elevator struct that holds variables
 */

struct Elevator{
    floor_enum next_floor;
    bool door_closed;
    direction movement_dir;
    bool stop_pushed;
    bool light_on[5];
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

void elevator_go_to_floor(floor_enum floor_variable, floor_enum current_floor, HardwareOrder order_type);

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

/**
 * @brief Turns the selected light off.
 * @param light_variable Input variable og type floor.
 * @return void
 */

void elevator_light_off(light ligth_variable);

/**
 * @brief Turns the selected light off.
 * @param light_variable Input variable og type floor.
 * @return void
 */

void elevator_light_on(light light_variable);

/**
 * @brief Checks if there are any obstacles blocking the door.
<<<<<<< HEAD
 * @return bool 
 */

bool elevator_check_obstacle();
=======
 * @return bool
 */

bool elevator_check_obstacle();

/**
 * @brief Checks if the stop button is pressed.
 * @return void
 */

void elevator_stop_movement();

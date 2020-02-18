#ifndef TEST_FILE_H
#define TEST_FILE_H

#include "enums.h"
#include <stdbool.h>

void test_lights(floor_enum current_floor);

void test_go_to_floor();

void test_init();

void test_move_and_queue(bool **order_state, floor_enum current_floor, elevator_state_machine state);

#endif
#ifndef ENUMS_H
#define ENUMS_H

/**
 * @file
 * @brief Enums used to describe floors, orders and states.
 */

/**
 * @brief Floor type used to enumerate floors.
 */

typedef enum {
    floor_1 = 0,
    floor_2 = 1,
    floor_3 = 2,
    floor_4 = 3,
    undefined_floor = 4
} floor_enum;

/**
 * @brief Order type used to enumerate orders
 */

typedef enum {
        ORDER_UP,
        ORDER_INSIDE,
        ORDER_DOWN
} order_button;

/**
 * @brief Enum for the state machine.
 */

typedef enum {
    idle,
    move_up,
    move_down,
    emergency_stop
} elevator_state_machine;

#endif
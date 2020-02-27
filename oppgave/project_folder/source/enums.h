#ifndef ENUM
#define ENUM


typedef enum {
    floor_1 = 0,
    floor_2 = 1,
    floor_3 = 2,
    floor_4 = 3,
    undefined_floor = 4
} floor_enum;

typedef enum {
        ORDER_UP,
        ORDER_INSIDE,
        ORDER_DOWN
} order_button;

typedef enum {
    idle,
    move_up,
    move_down,
    emergency_stop
} elevator_state_machine;

#endif
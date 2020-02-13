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
    up,
    down
} direction;

typedef enum {
    initilize,
    idle,
    move,
    door_open,
    emergency_stop
} elevator_state;

typedef enum {
    floor_up_light,
    floor_down_light,
    elev_floor_1_light,
    elev_floor_2_light,
    elev_floor_3_light,
    elev_floor_4_light,
    floor_1_light,
    floor_2_light,
    floor_3_light,
    floor_4_light,
    stop_light
} light;

#endif
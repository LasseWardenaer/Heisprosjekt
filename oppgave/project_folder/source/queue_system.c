
#include "queue_system.h"
#include "enums.h"
#include "elevator.h"
#include "driver/channels.h"
#include "driver/io.h"
#include <stdio.h>
#include "timer.h"



extern int order_state[4][3];
extern floor_enum current_floor;
extern elevator_state_machine state;

void queue_system_check_for_orders(){
    for (int floor=floor_1; floor<=floor_4;floor++){
        for (order_button button=ORDER_UP; button<=ORDER_DOWN; button++){
            if (hardware_read_order(floor, button)){
                    order_state[floor][button]=1;
                    hardware_command_order_light(floor,button,1);
            }
        }
    }
}

int queue_system_check_above(){
    for(int floor = (current_floor + 1); floor < 4; floor++){
        for(int state = 0; state < 3; state++){
            if(order_state[floor][state] == 1){
                return 1;
            }
        }
    }
    return 0;
}

int queue_system_check_below(){
    for(int floor = (current_floor - 1); floor > -1; floor--){
        for(int state = 0; state < 3; state ++){
            if(order_state[floor][state] == 1){
                return 1;
            }
        }
    }
    return 0;
}



void queue_system_check_if_stop(){
    current_floor = queue_system_return_floor();
    switch (state)
    {
    case (move_up):
    {
        if((order_state[current_floor][ORDER_INSIDE] || order_state[current_floor][ORDER_UP]) && !queue_system_is_between_floor()){
            order_state[current_floor][ORDER_INSIDE] = 0; 
            order_state[current_floor][ORDER_UP] = 0;
            hardware_command_order_light(current_floor, HARDWARE_ORDER_UP, 0);
            hardware_command_order_light(current_floor, HARDWARE_ORDER_INSIDE, 0);
            elevator_door_handler();
            if(!queue_system_check_above()){
                state=idle;
            }
        }
        break;
    }
    case (move_down):
    {
        if((order_state[current_floor][ORDER_INSIDE] || order_state[current_floor][ORDER_DOWN]) && !queue_system_is_between_floor()){
            order_state[current_floor][ORDER_INSIDE] = 0; 
            order_state[current_floor][ORDER_DOWN] = 0;
            hardware_command_order_light(current_floor, HARDWARE_ORDER_DOWN, 0);
            hardware_command_order_light(current_floor, HARDWARE_ORDER_INSIDE, 0);
            elevator_door_handler();
            if(!queue_system_check_below()){
                state=idle;
            }
        }
        break;
    }
    case (idle):
        queue_system_set_state();
        break;
    
    case (emergency_stop):
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
        break;
    }
}

void queue_system_clear_all_orders(){
    for(int floor = 0; floor <= floor_4; floor++){
        for(int state = 0; state < 3; state++){
            order_state[floor][state] = 0;
        }
    }
    clear_all_order_lights();
}

floor_enum queue_system_return_floor(){
    for (floor_enum floor =floor_1; floor<=floor_4;floor++){
        if (hardware_read_floor_sensor(floor)){
            return floor;
        }
    }
    return current_floor;
}

int queue_system_is_between_floor(){
    for (floor_enum floor=floor_1; floor<=floor_4;floor++){
        if (hardware_read_floor_sensor(floor)){
            return 0;
        }
    }
    return 1;
}


void queue_system_update_floor_ligths(){
    hardware_command_floor_indicator_on(current_floor);
}


void queue_system_set_state(){
    switch (state){
        case (move_up):{
            if (queue_system_check_above() || order_state[current_floor][ORDER_UP]){
                state=move_up;
            }
            else if (order_state[current_floor][ORDER_DOWN]){
                state=move_down;
            }
            break;
        }
        case (move_down):{
            if (queue_system_check_below() || order_state[current_floor][ORDER_DOWN]){
                state=move_down;
            }
            else if (order_state[current_floor][ORDER_UP]){
                state=move_up;
            }
            break;
        }
        case (idle):
            if((queue_system_check_above()||order_state[current_floor][ORDER_UP])){
                state = move_up;
                hardware_command_order_light(current_floor,HARDWARE_ORDER_INSIDE,0);
                if (order_state[current_floor][ORDER_UP]&&!queue_system_is_between_floor()){
                    elevator_door_handler();
                    hardware_command_order_light(current_floor, HARDWARE_ORDER_UP, 0);
                    order_state[current_floor][ORDER_UP]=0;
                    order_state[current_floor][ORDER_INSIDE]=0;                
                    }
                    if (!queue_system_check_above()){
                        state=idle;
                    }
            }
            else if((queue_system_check_below()||order_state[current_floor][ORDER_DOWN])){
                state = move_down;
                hardware_command_order_light(current_floor, HARDWARE_ORDER_INSIDE, 0);
                  if (order_state[current_floor][ORDER_DOWN]&&!queue_system_is_between_floor()){
                    elevator_door_handler();
                    hardware_command_order_light(current_floor, HARDWARE_ORDER_DOWN, 0);
                    order_state[current_floor][ORDER_DOWN]=0;
                    order_state[current_floor][ORDER_DOWN]=0;
                    if (!queue_system_check_below()){
                        state=idle;
                    }
                }
            }
            else if (order_state[current_floor][ORDER_INSIDE]&&!queue_system_is_between_floor()){
                    elevator_door_handler();
                    hardware_command_order_light(current_floor, HARDWARE_ORDER_INSIDE, 0);
                    order_state[current_floor][ORDER_INSIDE]=0; 
            }
            break;
        case (emergency_stop):
            break;
    }
}
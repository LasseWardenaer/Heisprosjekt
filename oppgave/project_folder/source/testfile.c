#include "hardware.h"
#include "testfile.h"
#include "elevator.h"
#include "timer.h"
#include "queue_system.h"
#include <stdio.h>

extern elevator_state_machine state;

// void test_lights(floor_enum* current_floor){
//     while(1){
//     *current_floor = queue_system_return_floor(current_floor); 
//         queue_system_update_floor_ligths(*current_floor);

//         queue_system_set_queue_and_light();
//         queue_system_set_queue_and_light_inside_elevator();

//         if(hardware_read_stop_signal()){
//             hardware_command_stop_light(on);
//             hardware_command_movement(HARDWARE_MOVEMENT_STOP);
//             break;
//         }

//         if(hardware_read_floor_sensor(0)){
//             hardware_command_movement(HARDWARE_MOVEMENT_UP);
//         }

//         if(hardware_read_floor_sensor(3)){
//             hardware_command_movement(HARDWARE_MOVEMENT_DOWN);     
//         }
//     }
// }

void test_go_to_floor(){
    //timer_set_wait_time(3);
    //floor_enum current_floor = floor_1;
    //elevator_go_to_floor(floor_3, current_floor, HARDWARE_ORDER_INSIDE);
    //current_floor = queue_system_return_floor(current_floor);
    //elevator_go_to_floor(floor_2, current_floor, HARDWARE_ORDER_INSIDE);
}

void test_move_and_queue(){
    while(1){
        queue_system_check_for_orders();
        queue_system_update_floor_ligths();
        queue_system_set_state();
        elevator_move();
    }
}


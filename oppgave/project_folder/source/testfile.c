#include "hardware.h"
#include "testfile.h"
#include "elevator.h"
#include "timer.h"

void test_lights(floor_enum current_floor){
    while(1){
    current_floor = hardware_return_floor(current_floor); 
        hardware_update_floor_ligths(current_floor);

        hardware_set_up_down_light_at_floor_on();
        hardware_set_floor_lights_inside_elevator();

        if(hardware_read_stop_signal()){
            hardware_command_stop_light(on);
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            break;
        }

        if(hardware_read_floor_sensor(0)){
            hardware_command_movement(HARDWARE_MOVEMENT_UP);
        }

        if(hardware_read_floor_sensor(3)){
            hardware_command_movement(HARDWARE_MOVEMENT_DOWN);     
        }
    }
}

void test_go_to_floor(){
    elevator_init();
    timer_set_wait_time(3);
    floor_enum current_floor = floor_1;
    elevator_go_to_floor(floor_3, current_floor, HARDWARE_ORDER_INSIDE);
    current_floor = hardware_return_floor(current_floor);
    elevator_go_to_floor(floor_2, current_floor, HARDWARE_ORDER_INSIDE);
}

void test_init(){
    elevator_init();
}
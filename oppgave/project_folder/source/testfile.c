#include "hardware.h"
#include "testfile.h"

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

void go_to_floor(){
    
}
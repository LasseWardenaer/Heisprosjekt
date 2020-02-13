#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "enums.h"

int main(){
    floor_enum current_floor = undefined_floor;
    elevator_state_machine elevator_state = initilize;
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    printf("Program started\n");
    printf("Press the stop button on the elevator panel to exit\n");

    hardware_command_movement(HARDWARE_MOVEMENT_UP);
    
    printf("%d", current_floor);

    while(1){
        current_floor = hardware_return_floor(current_floor); 
        hardware_update_floor_ligths(current_floor);

        if(hardware_read_stop_signal()){
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

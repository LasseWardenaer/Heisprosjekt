#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "enums.h"
#include "testfile.h"

int main(){
    floor_enum current_floor = undefined_floor;

    //0 indicates no order, 1 = order down, 2 = order up, 3 = up/down, inside
    //int floor_state = [0,0,0,0];
    //*elevator_state_machine elevator_state = initilize;
    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    printf("Program started\n");
    printf("Press the stop button on the elevator panel to exit\n");

    hardware_command_movement(HARDWARE_MOVEMENT_UP);

    printf("%d", current_floor);

    //test_lights(current_floor);
    //test_init();
    test_go_to_floor();
}

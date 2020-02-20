#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "enums.h"
#include "testfile.h"
#include "queue_system.h"
#include "elevator.h"



int main(){

    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    elevator_init();



    //printf("%d", *current_floor);

    //test_lights(current_floor);
    //test_go_to_floor();
    test_move_and_queue();
}

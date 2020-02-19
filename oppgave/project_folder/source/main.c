#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "enums.h"
#include "testfile.h"
#include "queue_system.h"
#include "elevator.h"

int main(){
    floor_enum* current_floor;
    current_floor = malloc(sizeof(floor_enum));
    int (**order_state) = malloc(sizeof(int[5][3]));  //{{0,0,0},{0,0,0},{0,0,0}, {0,0,0}}; //floor 1-4, {inside, up, down}
    elevator_state_machine *state;
    state = malloc(sizeof(elevator_state_machine));
    *state = idle;

    int error = hardware_init();
    if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }

    elevator_init(state, current_floor);

    printf("Program started\n");
    printf("Press the stop button on the elevator panel to exit\n");

    printf("%d", *current_floor);

    //test_lights(current_floor);
    //test_go_to_floor();
    test_move_and_queue(order_state, current_floor, state);
    free(order_state);
    free(state);
    free(current_floor);
}

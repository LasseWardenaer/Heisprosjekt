
#include "queue_system.h"
#include "enums.h"
#include "elevator.h"
#include "channels.h"




int check_orders_for_elevator[NUMBER_OF_FLOORS][NUMBER_OF_BUTTONS]={
    {BUTTON_COMMAND1, BUTTON_UP1, BUTTON_DOWN1},
    {BUTTON_COMMAND2, BUTTON_UP2, BUTTON_DOWN2},
    {BUTTON_COMMAND3, BUTTON_UP3, BUTTON_DOWN3},
    {BUTTON_COMMAND4, BUTTON_UP4, BUTTON_DOWN4}
}

int lights_for_order[NUMBER_OF_FLOORS][NUMBER_OF_BUTTONS]={
    {LIGHT_COMMAND1, LIGHT_UP1, LIGHT_DOWN1},
    {LIGHT_COMMAND2, LIGHT_UP2, LIGHT_DOWN2},
    {LIGHT_COMMAND3, LIGHT_UP3, LIGHT_DOWN3},
    {LIGHT_COMMAND4, LIGHT_UP4, LIGHT_DOWN4}
}

int orders_inside_elevator[4] = {0,0,0,0};

int orders_outside_elevator[NUMBER_OF_FLOORS][2]; //{floor, direction}, 0=up, 1=down

void check_for_orders(){
    for (int i=0; i<NUMBER_OF_FLOORS;i++){
        for (int j=0; j<NUMBER_OF_BUTTONS){
            if (io_read_bit(check_orders_for_elevator[i][j])){
                if (j=0){
                    orders_inside_elevator[i]=1;
                }
                else if (j=1){
                    orders_outside_elevator[i][up];
                }
                else if (j=2){
                    orders_outside_elevator[i][down];
                }
            }
        }
    }
}

void queue_system_update(int* floor_states[]){

}



bool queue_system_check_if_stop(){
    return 0;
}

void queue_system_clear_all_orders(){

}
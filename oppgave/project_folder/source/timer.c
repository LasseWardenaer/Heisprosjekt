#include "timer.h"
#include "hardware.h"
#include <time.h>
#include "queue_system.h"
#include "elevator.h"

extern int order_state[4][3];
extern floor_enum current_floor;

void timer_set_wait_time(int seconds){
    clock_t start_time=clock();
    while (((clock()-start_time)/CLOCKS_PER_SEC)<seconds){
        queue_system_check_for_orders();
        queue_system_update_floor_ligths();
        elevator_if_stop_pressed();
        hardware_command_order_light(current_floor,HARDWARE_ORDER_INSIDE,0);
        if(!(hardware_read_obstruction_signal())||hardware_read_stop_signal()){
             start_time=clock();
        }
    }
}
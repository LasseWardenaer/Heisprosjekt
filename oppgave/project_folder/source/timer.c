#include "timer.h"
#include "hardware.h"
#include <time.h>
#include "queue_system.h"

extern int order_state[4][3];

void timer_set_wait_time(int seconds){
    clock_t start_time=clock();
    while (((clock()-start_time)/CLOCKS_PER_SEC)<seconds){
        queue_system_check_for_orders(order_state);
        if(!(hardware_read_obstruction_signal())||hardware_read_stop_signal()){
             start_time=clock();
        }
    }
}
#include "timer.h"
#include "hardware.h"
#include <time.h>
#include "queue_system.h"


void timer_set_wait_time(int seconds, int **order_state){
    clock_t start_time=clock();
    while (((clock()-start_time)/CLOCKS_PER_SEC)<seconds){
        queue_system_check_for_orders(order_state);
        if(!(hardware_read_obstruction_signal())||hardware_read_stop_signal()){
             start_time=clock();
        }
    }
}
#include "timer.h"
#include "hardware.h"
#include <time.h>

void timer_set_wait_time(int seconds){
    clock_t start_time=clock();
    while (((clock()-start_time)/CLOCKS_PER_SEC)<seconds){
        //Må sjekke for bestillinger osv
        if(!(hardware_read_obstruction_signal())||hardware_read_stop_signal()){
             start_time=clock();
        }
    }
}
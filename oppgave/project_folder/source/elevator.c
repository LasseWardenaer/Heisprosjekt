#include "elevator.h"

void elevator_init(){
  elevator_go_to_floor(floor_1);
}

void elevator_go_to_floor(floor floor_variable){
  while ((hardware_read_floor_sensor(floor_variable)!=floor_variable)&&){
    int diff = (floor_variable-hardware_read_floor_sensor(floor_variable);
    if (!hardware_read_stop_signal()){
      if (diff>0){
        hardware_command_movement(HARDWARE_MOVEMENT_UP);
      }
      else if (diff<0){
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
      }
    }
    else{
      while (hardware_read_stop_signal()){
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      }
      sleep(3);
      }
    }
  }
}


void elevator_close_door(){

}


void elevator_open_door(){

}


void elevator_light_off(light ligth_variable){

}


void elevator_light_on(light light_variable){

}


bool elevator_check_obstacle(){

}


void elevator_stop_movement(){

}

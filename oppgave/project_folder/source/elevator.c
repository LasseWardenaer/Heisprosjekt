#include "elevator.h"
#include "hardware.h"

void elevator_init(){
  floor_enum current_floor = undefined_floor;
  hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
  while(current_floor != floor_1){
    current_floor = hardware_return_floor(current_floor);
  }
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
}

void elevator_go_to_floor(floor_enum floor_variable, floor_enum current_floor, HardwareOrder order_type){
  bool keep_going = true;
  int diff = (floor_variable-current_floor);
  while (keep_going){
    diff = (floor_variable-current_floor);
    current_floor = hardware_return_floor(current_floor);
    
    if (diff>0){
      hardware_command_movement(HARDWARE_MOVEMENT_UP);
    }
    else if (diff<0){
      hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
    }
    else {
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      break;
    }
  }
  hardware_command_order_light(floor_variable, order_type, 0);
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
  return 1;
}


void elevator_stop_movement(){

}

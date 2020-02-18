#include "elevator.h"
#include "hardware.h"
#include "timer.h"
#include "queue_system.h"

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
    elevator_stop_movement();
    
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
  hardware_command_order_light(floor_variable, order_type, 0); //må slukke både lyset inni og utenpå heisen
  elevator_open_door();
  timer_set_wait_time(3);
  elevator_close_door();
}


void elevator_close_door(){
  hardware_command_door_open(0);
}


void elevator_open_door(){
  hardware_command_door_open(1);

}


void elevator_light_off(light ligth_variable){

}


void elevator_light_on(light light_variable){

}


void elevator_stop_movement(){
  while(hardware_read_stop_signal()){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    hardware_command_stop_light(1);
    queue_system_clear_all_orders(); //må implementeres
  }
  hardware_command_stop_light(0);
}

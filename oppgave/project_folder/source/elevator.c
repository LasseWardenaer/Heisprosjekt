#include "elevator.h"
#include "hardware.h"
#include "timer.h"
#include "queue_system.h"

int order_state[4][3] = {{0,0,0},{0,0,0},{0,0,0}, {0,0,0}};
floor_enum current_floor=undefined_floor;
elevator_state_machine state;


void elevator_init(){
  current_floor = undefined_floor;
  hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
  while(current_floor != floor_1){
    current_floor = queue_system_return_floor(current_floor);
  }
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  state = idle;
}


void elevator_move(){
  switch(state){
    case(idle):
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      break;
    case(move_down):
      hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
      break;
    case(move_up):
      hardware_command_movement(HARDWARE_MOVEMENT_UP);
      break;
    case(emergency_stop):
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      break;
  }
  elevator_stop_pressed();
  queue_system_check_if_stop();
}

void elevator_stop_pressed(){
  elevator_state_machine last_dir = state;
  floor_enum last_floor = queue_system_return_floor(); 
  while(hardware_read_stop_signal()){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    hardware_command_stop_light(1);
    queue_system_clear_all_orders();
    clear_all_order_lights();
    state = emergency_stop;
    if (!queue_system_is_between_floor()){
      hardware_command_door_open(1);
    }
  }
  hardware_command_stop_light(0);
  if (state==emergency_stop){
    if (!queue_system_is_between_floor()){
      elevator_door_handler();
    }
    state=idle;
    elevator_emergency_stop_handler(last_floor, last_dir);
  }
}

void clear_all_order_lights(){
  for(floor_enum floor = floor_1; floor <= floor_4; floor++){
    for(order_button button = ORDER_UP; button <= ORDER_DOWN; button++){
        hardware_command_order_light(floor, button, 0);
    }
  }
}

void elevator_door_handler(){
  if(!queue_system_is_between_floor()){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    hardware_command_door_open(1);
    timer_set_wait_time(3);
    hardware_command_door_open(0);
  }
}

void elevator_emergency_stop_handler(floor_enum last_floor, elevator_state_machine last_dir){
  while (queue_system_is_between_floor()){
    queue_system_check_for_orders();
    if(order_state[current_floor][ORDER_INSIDE] || order_state[current_floor][ORDER_UP] || order_state[current_floor][ORDER_DOWN]){
      if(last_dir==move_down){
        hardware_command_door_open(0);
        hardware_command_movement(HARDWARE_MOVEMENT_UP);
        while (!hardware_read_floor_sensor(current_floor)){
            state = last_dir;
            elevator_stop_pressed();
            queue_system_check_for_orders();
        } 
        hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      }
      else if (last_dir==move_up){
        hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
        hardware_command_door_open(0);
          while (!hardware_read_floor_sensor(current_floor)){
            state = last_dir;
            elevator_stop_pressed();
            queue_system_check_for_orders();
          } 
          hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      }
    }
    else{
      queue_system_update_floor_ligths();
      elevator_move();
    }
  }
}
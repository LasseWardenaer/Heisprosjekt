#include "elevator.h"
#include "hardware.h"
#include "timer.h"
#include "queue_system.h"

int order_state[4][3] = {{0,0,0},{0,0,0},{0,0,0}, {0,0,0}};
floor_enum current_floor=undefined_floor;
elevator_state_machine state=idle;


void elevator_init(){
  current_floor = undefined_floor;
  hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
  while(current_floor != floor_1){
    current_floor = queue_system_return_floor(current_floor);
  }
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  state = idle;
}

// void elevator_go_to_floor(floor_enum floor_variable, floor_enum current_floor, HardwareOrder order_type){
//   int keep_going = 1;
//   int diff = (floor_variable-current_floor);
//   while (keep_going){
//     diff = (floor_variable-current_floor);
//     current_floor = queue_system_return_floor(current_floor);
//     elevator_stop_movement();
    
//     if (diff>0){
//       hardware_command_movement(HARDWARE_MOVEMENT_UP);
//     }
//     else if (diff<0){
//       hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
//     }
//     else {
//       hardware_command_movement(HARDWARE_MOVEMENT_STOP);
//       break;
//     }
//   }
//   hardware_command_order_light(floor_variable, order_type, 0);
//   elevator_open_door();
//   timer_set_wait_time(3);
//   elevator_close_door();
// }

void elevator_move(){
  current_floor = queue_system_return_floor();
  int order_current_floor = 0;
  switch(state){
    case(idle):
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      order_current_floor = elevator_order_in_current_floor();
      break;
    case(move_down):
      hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
      break;
    case(move_up):
      hardware_command_movement(HARDWARE_MOVEMENT_UP);
      break;
    case(door_open):
      break;
    case(emergency_stop):
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
      break;
  }
  elevator_if_stop_pressed();
  if(queue_system_check_if_stop() && !order_current_floor){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    elevator_open_door();
    timer_set_wait_time(3);
    elevator_close_door();
  }
}


void elevator_close_door(){
  hardware_command_door_open(0);
}


void elevator_open_door(){
  hardware_command_door_open(1);
}


void elevator_if_stop_pressed(){
  //elevator_state_machine last_dir = state;
  //floor_enum last_floor = queue_system_return_floor(); 
  while(hardware_read_stop_signal()){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    hardware_command_stop_light(1);
    queue_system_clear_all_orders();
    clear_all_order_lights();
    state = emergency_stop;
  }
  hardware_command_stop_light(0);
  //current_floor = undefined_floor;
}

void clear_all_order_lights(){
    HardwareOrder order_types[3] = {
        HARDWARE_ORDER_UP,
        HARDWARE_ORDER_INSIDE,
        HARDWARE_ORDER_DOWN
    };

    for(int f = 0; f < HARDWARE_NUMBER_OF_FLOORS; f++){
        for(int i = 0; i < 3; i++){
            HardwareOrder type = order_types[i];
            hardware_command_order_light(f, type, 0);
        }
    }
}

int elevator_order_in_current_floor(){
  if(order_state[current_floor][ORDER_INSIDE]==1){
      hardware_command_order_light(current_floor,HARDWARE_ORDER_INSIDE,0);
      elevator_open_door();
      timer_set_wait_time(3);
      elevator_close_door();
      order_state[current_floor][ORDER_INSIDE]=0;
      return 1;
  }
  return 0;
}

#include "elevator.h"
#include "hardware.h"
#include "timer.h"
#include "queue_system.h"


void elevator_init(elevator_state_machine state, floor_enum current_floor){
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

void elevator_move(int** order_state,floor_enum* current_floor, elevator_state_machine *current_state){
  switch(*current_state){
    case(idle):
      hardware_command_movement(HARDWARE_MOVEMENT_STOP);
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
      break;
  }  
  if(queue_system_check_if_stop(current_state, *current_floor, order_state)){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    elevator_open_door(order_state);
    elevator_close_door();
  }
}


void elevator_close_door(){
  hardware_command_door_open(0);

}


void elevator_open_door(int **order_state){
  hardware_command_door_open(1);
  timer_set_wait_time(3, order_state);
}


void elevator_stop_movement(){
  while(hardware_read_stop_signal()){
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    hardware_command_stop_light(1);
    queue_system_clear_all_orders(); //må implementeres
  }
  hardware_command_stop_light(0);
}

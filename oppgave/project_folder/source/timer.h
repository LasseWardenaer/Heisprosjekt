#ifndef TIMER_H
#define TIMER_H

/**
 * @file
 * @brief Timer module, only makes the system wait for a given time.
 */

/**
 * @brief Makes the system wait with the door open for a given time, while still updating orders and checking obstruction and stop button.
 * @return void
 */
void timer_set_wait_time(int seconds);

#endif
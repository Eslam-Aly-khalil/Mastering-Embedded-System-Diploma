/*
 * state.h
 *
 *  Created on: Dec 23, 2023
 *      Author: Eslam Aly
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_


//States connection
void updatePressureVal();
void highpressure_detected();


#endif /* STATE_H_ */

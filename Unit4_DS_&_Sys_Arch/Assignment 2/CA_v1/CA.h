/*
 * CA.h
 *
 *  Created on: Dec 23, 2023
 *      Author: Ahmed Ali
 */

#ifndef CA_H_
#define CA_H_

#include "stdio.h"
#include "state.h"

enum {
	CA_waiting,
	CA_driving
}CA_state_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);
int US_GetDistanceRandom(int l , int r , int count);

/* STATE pointer to function */
extern void (*CA_state) ();

#endif /* CA_H_ */

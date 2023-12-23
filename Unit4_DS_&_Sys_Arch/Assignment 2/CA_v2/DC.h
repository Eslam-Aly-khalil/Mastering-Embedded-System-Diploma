/*
 * DC.h
 *
 *  Created on: Dec 23, 2023
 *      Author: Ahmed Ali
 */

#ifndef DC_H_
#define DC_H_


#include "stdio.h"
#include "state.h"

enum {
	DC_start,
	DC_stop
}DC_state_id;

STATE_define(DC_start);
STATE_define(DC_stop);
void DC_init();


/* STATE pointer to function */
extern void (*DC_state) ();

#endif /* DC_H_ */

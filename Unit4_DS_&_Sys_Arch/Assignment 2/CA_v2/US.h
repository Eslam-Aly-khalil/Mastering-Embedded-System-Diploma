/*
 * US.h
 *
 *  Created on: Dec 23, 2023
 *      Author: Ahmed Ali
 */

#ifndef US_H_
#define US_H_

#include "stdio.h"
#include "state.h"

enum {
	US_busy,
}US_state_id;

STATE_define(US_busy);
void US_init();

/* STATE pointer to function */
extern void (*US_state) ();

#endif /* US_H_ */

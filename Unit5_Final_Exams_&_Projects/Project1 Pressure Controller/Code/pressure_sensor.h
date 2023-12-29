/*
*  pressure_sensorh.h 
*  
*  created by: Eslam Aly
*  created on: 25th Dec, 2023
*
*/

#ifndef  PRESSURE_SENSOR_H_
#define  PRESSURE_SENSOR_H_

#include "state.h"
#include "driver.h"

extern void (*ptr_PS_state)(); //pointer to a function

typedef enum {
	PS_reading,
	PS_waiting
	
}PS_state;

extern PS_state PS_current_state;

void PS_init();  //function to initialize pressure sensor driver

STATE_define(PS_reading);
STATE_define(PS_waiting);
#endif
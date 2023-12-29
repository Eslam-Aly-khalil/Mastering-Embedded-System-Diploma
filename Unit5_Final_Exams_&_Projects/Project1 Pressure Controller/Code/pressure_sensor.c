/*
*  pressure_sensorh.c
*  
*  created by: Eslam Aly
*  created on: 25th Dec, 2023
*
*/

#include "pressure_sensor.h"

void (*ptr_PS_state)();
static int pVal;
PS_state PS_current_state;

void PS_init()
{
	GPIO_INITIALIZATION ();
	ptr_PS_state = STATE(PS_reading);
}

STATE_define(PS_reading)
{
	PS_current_state = PS_reading;         //Initializing the current state
	pVal = getPressureVal();               // read pressure value
	Delay(6000);
	ptr_PS_state = STATE(PS_waiting);      //turn to new state
}

STATE_define(PS_waiting)
{
	PS_current_state = PS_waiting;  	//Initializing the current state
	set_pressure_val(pVal);             //send new pressure to main
	Delay(6000);
	ptr_PS_state = STATE(PS_reading);   //turn to new state
}
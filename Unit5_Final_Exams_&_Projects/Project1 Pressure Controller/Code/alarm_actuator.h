/*
*  alarm_actuator.h 
*  
*  created by: Eslam Aly
*  created on: 25th Dec, 2023
*
*/

#ifndef  ALARM_ACTUATOR_H_
#define  ALARM_ACTUATOR_H_


#include "state.h"
#include "driver.h"

extern void (*ptr_alarm_actuator_state)(); //pointer to a function


typedef enum {
	ALARMON,
	ALARMOFF,
	WAITING
}alarm_actuator_state;

extern alarm_actuator_state alarm_current_state;

void alarm_actuator_init();  //function to initialize alarm actuator driver
void startalarm();
void stopalarm();

STATE_define(ALARMON);
STATE_define(ALARMOFF);
STATE_define(WAITING);

#endif
/*
*  alarm_actuator.c
*  
*  created by: Eslam Aly
*  created on: 25th Dec, 2023
*
*/

#include "alarm_actuator.h"

void (*ptr_alarm_actuator_state)();
alarm_actuator_state alarm_current_state;

void alarm_actuator_init()
{
	GPIO_INITIALIZATION ();
	ptr_alarm_actuator_state = STATE(WAITING);
}
void startalarm()
{
	ptr_alarm_actuator_state = STATE(ALARMON);
	ptr_alarm_actuator_state();
}
STATE_define(ALARMON)
{
	alarm_current_state = ALARMON;
	Set_Alarm_actuator(0);
	ptr_alarm_actuator_state = STATE(WAITING);
}

void stopalarm()
{
	ptr_alarm_actuator_state = STATE(ALARMOFF);
	ptr_alarm_actuator_state();
}
STATE_define(ALARMOFF)
{
	alarm_current_state = ALARMOFF;
	Set_Alarm_actuator(1);
	ptr_alarm_actuator_state = STATE(WAITING);
}

STATE_define(WAITING)
{
	alarm_current_state = WAITING;
}
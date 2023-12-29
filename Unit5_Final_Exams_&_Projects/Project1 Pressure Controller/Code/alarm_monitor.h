/*
*  alarm_monitor.h 
*  
*  created by: Eslam Aly
*  created on: 25th Dec, 2023
*
*/


#ifndef  ALARM_MONITOR_H_
#define  ALARM_MONITOR_H_


#include "state.h"
#include "driver.h"

extern void (* ptr_alarm_monitor_state)(); //pointer to function

typedef enum {
	AM_alarmOFF,
	AM_alarmON,
	AM_waiting
}alarm_monitor_status;

extern alarm_monitor_status AM_current_state;

void alarm_monitor_init();

STATE_define(AM_alarmOFF);
STATE_define(AM_alarmON);
STATE_define(AM_waiting);


#endif

#include "alarm_monitor.h"

void (* ptr_alarm_monitor_state)();
alarm_monitor_status AM_current_state;

void alarm_monitor_init()
{
	GPIO_INITIALIZATION ();
	stopalarm();	
	ptr_alarm_monitor_state = STATE(AM_alarmOFF);
}

void highpressure_detected()
{
	ptr_alarm_monitor_state = STATE(AM_alarmON);
}

STATE_define(AM_alarmOFF)
{
	AM_current_state = AM_alarmOFF;
	/*stopalarm();
	ptr_alarm_monitor_state = STATE(AM_alarmOFF);*/
}
STATE_define(AM_alarmON)
{
	AM_current_state = AM_alarmON;
	startalarm();
	Delay(60000);
	ptr_alarm_monitor_state = STATE(AM_waiting);
}
STATE_define(AM_waiting)
{
	AM_current_state = AM_waiting;
	//Delay(2000);
	stopalarm();
	ptr_alarm_monitor_state = STATE(AM_alarmOFF);
}
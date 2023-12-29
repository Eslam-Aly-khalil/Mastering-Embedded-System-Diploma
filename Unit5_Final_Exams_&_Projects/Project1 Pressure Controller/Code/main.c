#include <stdint.h>
#include <stdio.h>

#include "pressure_sensor.h"
#include "alarm_monitor.h"
#include "alarm_actuator.h"

static int local_pVal;

void setup()
{
	PS_init();
	alarm_actuator_init();
	alarm_monitor_init();
}
int main ()
{	
	setup();
	
	while (1)
	{
		ptr_PS_state();
		if(local_pVal > 20)
		{
			highpressure_detected();
		}
		ptr_alarm_actuator_state();
		ptr_alarm_monitor_state();
	}

}

void set_pressure_val(int pVal)
{
	local_pVal = pVal;
}
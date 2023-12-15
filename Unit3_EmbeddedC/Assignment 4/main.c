/**
main for assignment4 project
 */

#include <stdint.h>

#define  SYSCTL_RCGC2_R       (*((volatile unsigned long*)0x400FE108))
#define  GPIO_PORTF_DIR_R     (*((volatile unsigned long*)0x40025400))
#define  GPIO_PORTF_DEN_R     (*((volatile unsigned long*)0x4002551C))
#define  GPIO_PORTF_DATA_R    (*((volatile unsigned long*)0x400253FC))

void main()
{
	volatile unsigned long delay_counter;
	SYSCTL_RCGC2_R = 0x00000020;     
	for(delay_counter=0;delay_counter<200;delay_counter++); //Delay for make sure that PORTF is activated
	GPIO_PORTF_DIR_R |= 1<<3;  //Pin 3 is set Output
	GPIO_PORTF_DEN_R |= 1<<3;  //Pin 3 is enabled
	
    while(1)
    {
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_counter=0;delay_counter<20000;delay_counter++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_counter=0;delay_counter<20000;delay_counter++);
    }
}

#include "uart.h"

#define UART0DR   	*(volatile unsigned int*)((unsigned int*)0x101f1000)

void uart_sendString(unsigned char * tx_string)
{
	while (* tx_string != '\0')
	{
		UART0DR = (unsigned int)* tx_string;
		* tx_string++;
	}
}

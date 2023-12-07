#include "uart.h"

unsigned char string_buffer[100] = "Learn-In-Depth : Eslam";

void main()
{
	uart_sendString(string_buffer);
}
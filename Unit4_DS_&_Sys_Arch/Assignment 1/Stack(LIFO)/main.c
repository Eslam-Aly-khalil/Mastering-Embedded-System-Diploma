/*
 * main.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Ahmed Ali
 */


#include "LIFO.h"

unsigned int buffer_1[5];

int main()
{
	int i, temp=0;
	LIFO_buff_t uart_LIFO, spi_LIFO;
	LIFO_init(&uart_LIFO, buffer_1, 5);

	unsigned int * buffer_2 = (unsigned int *) malloc(5 * sizeof(unsigned int));
	LIFO_init(&spi_LIFO, buffer_2, 5);

	for(i=0;i<5;i++)
	{
		if ((LIFO_add(&uart_LIFO,i)) == LIFO_noError)
		{
			printf("UART LIFO Add: %d\n",i);
		}
	}

	for(i=0;i<5;i++)
	{
		if ((LIFO_get(&uart_LIFO,&temp))== LIFO_noError)
		{
			printf("UART LIFO get: %d\n",temp);
		}
	}

	return 0;
}

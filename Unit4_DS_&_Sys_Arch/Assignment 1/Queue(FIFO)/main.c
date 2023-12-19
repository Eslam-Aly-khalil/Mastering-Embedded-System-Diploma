/*
 * main.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Ahmed Ali
 */


#include "FIFO.h"

void main()
{
	element_type i, temp=0;
	FIFO_Buffer_t uart_FIFO;

	if(FIFO_init(&uart_FIFO, uart_Buffer, 5))
		printf("FIFO Init -----> Done \n");

	for(i=0;i<7;i++)
	{
		printf("FIFO enqueue (%x) \n",i);

		if(FIFO_enqueue(&uart_FIFO, i) == FIFO_noError)
			printf("\t FIFO Enqueue -------> Done \n");
		else
			printf("\t FIFO Enqueue -------> Failed \n");
	}

	FIFO_print(&uart_FIFO);

	if(FIFO_dequeue(&uart_FIFO, &temp) == FIFO_noError)
		printf("\t FIFO Dequeue (%X) ------>Done \n",temp);
	if(FIFO_dequeue(&uart_FIFO, &temp) == FIFO_noError)
		printf("\t FIFO Dequeue (%X) ------>Done \n",temp);

	FIFO_print(&uart_FIFO);
}

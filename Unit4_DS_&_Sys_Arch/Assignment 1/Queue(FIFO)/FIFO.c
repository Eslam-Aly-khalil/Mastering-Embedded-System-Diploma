/*
 * FIFO.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Ahmed Ali
 */

#include "FIFO.h"

FIFO_status FIFO_init(FIFO_Buffer_t* FIFO_Buf, element_type* buffer, uint32_t length)
{
	//Checking if Data is correct
	if (buffer == NULL)
		return FIFO_NULL;

	//Initializing FIFO
	FIFO_Buf->base = buffer;
	FIFO_Buf->head = buffer;
	FIFO_Buf->tail = buffer;
	FIFO_Buf->length = length;
	FIFO_Buf->count = 0;

	return FIFO_noError ;
}

FIFO_status FIFO_enqueue(FIFO_Buffer_t* FIFO_Buf, element_type item)
{
	//Checking if all pointers exist or not
	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;

	//Checking If FIFO is full
	if (FIFO_IsFull(FIFO_Buf) == FIFO_full)
		return FIFO_full;

	*(FIFO_Buf->head) = item;
	FIFO_Buf->count++;
	//Circular Queue(FIFO)
	if(FIFO_Buf->tail == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(element_type))))
		FIFO_Buf->head = FIFO_Buf->base;
	else
		FIFO_Buf->head++;

	return FIFO_noError;
}

FIFO_status FIFO_dequeue(FIFO_Buffer_t* FIFO_Buf, element_type * item)
{
	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;

	if(FIFO_Buf->count == 0)
		return FIFO_empty;

	*item = *(FIFO_Buf->tail);
	FIFO_Buf->count--;
	//Circular Queue(FIFO)
	if(FIFO_Buf->tail == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(element_type))))
		FIFO_Buf->tail = FIFO_Buf->base;
	else
		FIFO_Buf->tail++;

	return FIFO_noError;
}

FIFO_status FIFO_IsFull(FIFO_Buffer_t* FIFO_Buf)
{
	//Checking if all pointers exist or not
	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;

	//Checking If FIFO Full
	if (FIFO_Buf->count == FIFO_Buf->length)
		return FIFO_full;

	return FIFO_noError;

}

void FIFO_print(FIFO_Buffer_t* FIFO_Buf)
{
	element_type* temp;
	int i;
	if (FIFO_Buf->count == 0)
	{
		printf("FIFO is empty");
	}
	else
	{
		temp = FIFO_Buf->tail;
	}
	printf("\n------------QUEUE PRINT-------------\n");
	for(i=0;i<FIFO_Buf->count;i++)
	{
		printf("\t %X \n",*temp);
		temp++;
	}
	printf("-------------------------\n");
}

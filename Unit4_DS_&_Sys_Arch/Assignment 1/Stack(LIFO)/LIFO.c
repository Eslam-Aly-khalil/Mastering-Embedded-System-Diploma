/*
 * LIFO.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Ahmed Ali
 */

#include "LIFO.h"

LIFO_status LIFO_init(LIFO_buff_t* LIFO_buff, unsigned int* Buff, unsigned int length)
{
	if (Buff == NULL)
	{
		return LIFO_Full;
	}
	LIFO_buff->base = Buff;
	LIFO_buff->head = Buff;
	LIFO_buff->lenght = length;
	LIFO_buff->count = 0;

	return LIFO_noError;
}

LIFO_status LIFO_add(LIFO_buff_t* LIFO_Buff, unsigned int buff)
{
	//Check if LIFO is valid
	if (! LIFO_Buff->base )
		return LIFO_NULL ;

	//	buffer is full
	if((LIFO_Buff->head) == (LIFO_Buff->lenght))
		return LIFO_Full;

	// Adding Value to the Stack(LIFO)
	*(LIFO_Buff->head) = buff;
	LIFO_Buff->head++;
	LIFO_Buff->count++;

	return LIFO_noError;
}

LIFO_status LIFO_get(LIFO_buff_t* LIFO_Buff, unsigned int* buff)
{
	//Check if LIFO is empty
	if (!LIFO_Buff->base || !LIFO_Buff->head)
		return LIFO_NULL;

	//	buffer is empty
	if(LIFO_Buff->count == 0)
		return LIFO_empty;

	//Getting Value from the Stack(LIFO)
	(LIFO_Buff->head)--;
	*buff = *(LIFO_Buff->head) ;
	LIFO_Buff->count--;

	return LIFO_noError;
}

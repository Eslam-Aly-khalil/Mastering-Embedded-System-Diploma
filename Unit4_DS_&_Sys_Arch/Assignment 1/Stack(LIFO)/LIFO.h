/*
 * LIFO.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Ahmed Ali
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

/*           Define a struct with LIFO specs              */
typedef struct
{
	unsigned int lenght;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_buff_t;

/*              Define enumeration for LIFO status         */
typedef enum
{
	LIFO_Full,
	LIFO_empty,
	LIFO_noError,
	LIFO_NULL
}LIFO_status;

/*      APIs' Headers     */
LIFO_status LIFO_init(LIFO_buff_t* LIFO_buff, unsigned int* Buff, unsigned int length);  //Create
LIFO_status LIFO_add(LIFO_buff_t* LIFO_buff, unsigned int buff);   //Push
LIFO_status LIFO_get(LIFO_buff_t* LIFO_buff, unsigned int* buff);  //Pop

#endif /* LIFO_H_ */

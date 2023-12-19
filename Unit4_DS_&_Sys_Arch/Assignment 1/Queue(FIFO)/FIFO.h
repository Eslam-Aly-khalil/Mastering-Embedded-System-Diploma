/*
 * FIFO.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Ahmed Ali
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

//Configure Element Type (uint8 - uint16 - uint32 - ......)
#define element_type   uint8_t

//Create Space in Memory to store data in it  (Buffer)
#define width  5
element_type uart_Buffer [width];

//FIFO Data types
typedef struct {
	uint32_t  count;
	uint32_t  length;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buffer_t;

//Status of the Queue(FIFO)
typedef enum {
	FIFO_full,
	FIFO_empty,
	FIFO_noError,
	FIFO_NULL
}FIFO_status;

// APIs
FIFO_status FIFO_init(FIFO_Buffer_t* FIFO_Buf, element_type* buffer, uint32_t length);
FIFO_status FIFO_enqueue(FIFO_Buffer_t* FIFO_Buf, element_type item);
FIFO_status FIFO_dequeue(FIFO_Buffer_t* FIFO_Buf, element_type* item);
FIFO_status FIFO_IsFull(FIFO_Buffer_t* FIFO_Buf);
void FIFO_print(FIFO_Buffer_t* FIFO_Buf);


#endif /* FIFO_H_ */

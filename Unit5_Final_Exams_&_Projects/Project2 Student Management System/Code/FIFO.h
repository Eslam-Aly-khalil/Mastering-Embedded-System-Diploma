/*
 * FIFO.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Aly
 */

#ifndef FIFO_H_
#define FIFO_H_


#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

#define DPRINTF(...)     {fflush(stdout); \
							fflush(stdin); \
							printf(__VA_ARGS__);  \
							fflush(stdout);  \
							fflush(stdin); }





//Configure Element Type (uint8 - uint16 - uint32 - ......)
#define element_type   uint8_t

//Create Space in Memory to store data in it  (Buffer)
#define width  5
element_type uart_Buffer [width];

//Student's info
typedef struct {
	char firstName[20];
	char lastName[20];
	int  ID;
	float gpa;
	int courseNum[4];
}Sstudent;

Sstudent buffer[50];
//FIFO Configurations
typedef struct {
	uint32_t  count;
	uint32_t  length;
	Sstudent* base;
	Sstudent* head;
	Sstudent* tail;
}FIFO_Buffer_t;

//Status of the Queue(FIFO)
typedef enum {
	FIFO_full,
	FIFO_empty,
	FIFO_noError,
	FIFO_NULL
}FIFO_status;

// APIs
FIFO_status FIFO_init(FIFO_Buffer_t* FIFO_Buf, Sstudent* buffer, uint32_t length);
FIFO_status FIFO_IsFull(FIFO_Buffer_t* FIFO_Buf);
void FIFO_print(FIFO_Buffer_t* FIFO_Buf);


FIFO_status add_Students(FIFO_Buffer_t* FIFO_Buf);
int check_unique(FIFO_Buffer_t* FIFO_Buf, int num);
FIFO_status find_ID(FIFO_Buffer_t* FIFO_Buf);
FIFO_status find_firstName(FIFO_Buffer_t* FIFO_Buf);
FIFO_status num_Students_Enrolled(FIFO_Buffer_t* FIFO_Buf);
FIFO_status countStudents(FIFO_Buffer_t* FIFO_Buf);
FIFO_status deleteStudent(FIFO_Buffer_t* FIFO_Buf);
FIFO_status updateStudent(FIFO_Buffer_t* FIFO_Buf);
FIFO_status add_Students_file(FIFO_Buffer_t* FIFO_Buf);
#endif /* FIFO_H_ */

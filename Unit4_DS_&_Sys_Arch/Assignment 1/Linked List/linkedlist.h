/*
 * linkedlist.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Ahmed Ali
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)     {fflush(stdout); \
							fflush(stdin); \
							printf(__VA_ARGS__);  \
							fflush(stdout);  \
							fflush(stdin); }


struct Sdata {
	int ID;
	char name[40];
	int age;
};

struct Sstudent {
	struct Sdata student;
	struct Sstudent* p_next;
};

void addStudent();
int deleteStudent();
void printList();
void deleteAll();
void reverse();
int rec_Length(struct Sstudent* p_check);
void itr_length();

#endif /* LINKEDLIST_H_ */

/*
 * linkedlist.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Ahmed Ali
 */

#include "linkedlist.h"

struct Sstudent* gp_firstStudent = NULL;

void addStudent()
{
	struct Sstudent* p_newStudet;
	struct Sstudent* p_lastStudet;
	char temp[40];

	//check if the list is empty
	if(gp_firstStudent == NULL)
	{
		p_newStudet = (struct Sstudent*)malloc(sizeof(struct Sstudent)); //dynamically allocate a new node
		gp_firstStudent = p_newStudet;
	}
	else  //the list is not empty
	{
		p_lastStudet = gp_firstStudent;
		while(p_lastStudet->p_next != NULL) //Trying to search for the last node to add the new one
		{
			p_lastStudet = p_lastStudet->p_next;
		}
		p_newStudet = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		p_lastStudet->p_next = p_newStudet;
		p_newStudet->p_next = NULL;
	}
	DPRINTF("Enter Student ID: ");
	gets(temp);
	p_newStudet->student.ID = atoi(temp);

	DPRINTF("Enter Student Name: ");
	gets(p_newStudet->student.name);

	DPRINTF("Enter Student Age: ");
	gets(temp);
	p_newStudet->student.age = atoi(temp);

	p_newStudet->p_next = NULL;
}

int deleteStudent()
{
	char temp[40];
	int ID_wanted;
	DPRINTF("Enter Student's ID to be deleted: ");
	gets(temp);
	ID_wanted = atoi(temp);
	struct Sstudent* p_selectStudent = gp_firstStudent;
	struct Sstudent* p_prevStudent = NULL;

	while (p_selectStudent)
	{
		if(p_selectStudent->student.ID == ID_wanted) //check if current ID is the requested ID
		{
			if (p_prevStudent) // if selected ID is not in the first node
			{
				p_prevStudent->p_next = p_selectStudent->p_next;
			}
			else {            // Selected ID is the first node
				gp_firstStudent = p_prevStudent->p_next;
			}
			free(p_selectStudent);
			return 1;
		}
		//If ID is not found in this node >>> Switch to the next one
		p_prevStudent=p_selectStudent;
		p_selectStudent=p_selectStudent->p_next;
	}
	DPRINTF("Student ID is not in the List");
	return 0;
}

void printList()
{
	int counter =0;
	struct Sstudent* p_currentstudent = gp_firstStudent;

	if(p_currentstudent == NULL){
		printf("List is empty");
	}
	else{
		while(p_currentstudent)
		{
			DPRINTF("\n-------------Record Number: %d-------------",counter+1);
			DPRINTF("\n Student's ID: %d",p_currentstudent->student.ID);
			DPRINTF("\n Student's Name: %s",p_currentstudent->student.name);
			DPRINTF("\n Student's Age: %d",p_currentstudent->student.age);
			DPRINTF("\n-------------------------------------------");
			counter++;
			p_currentstudent = p_currentstudent->p_next;
		}
	}
}

void deleteAll()
{
	struct Sstudent* p_currentStudent = gp_firstStudent;
	struct Sstudent* p_temp;
	if(gp_firstStudent == NULL)
	{
		printf("List is Empty");
	}
	else{
		while (p_currentStudent)
		{
			p_temp = p_currentStudent;
			p_currentStudent = p_currentStudent->p_next;
			free(p_temp);
		}
		gp_firstStudent=NULL;
	}

}

void reverse()
{
	struct Sstudent* p_currentStudent = gp_firstStudent->p_next;
	struct Sstudent* p_prevStudent = gp_firstStudent;
	struct Sstudent* p_nextStudent = NULL;

	if (gp_firstStudent == NULL)
	{
		DPRINTF("List is Empty");
	}
	else
	{
		while(p_currentStudent)
		{
			p_nextStudent = p_currentStudent->p_next;
			p_currentStudent->p_next = p_prevStudent;
			p_prevStudent = p_currentStudent;
			p_currentStudent = p_nextStudent;
		}
		gp_firstStudent->p_next = NULL;
		gp_firstStudent = p_prevStudent;
	}
}

int rec_Length(struct Sstudent* p_counter)
{
	if(p_counter)
		return 1+ rec_Length(p_counter->p_next);
	else
		return 0;
}

void itr_length()
{
	struct Sstudent* p_counter = gp_firstStudent;
	int counter = 0;
	if (gp_firstStudent == NULL)
	{
		DPRINTF("List is Empty");
	}
	else
	{
		while(p_counter)
		{
			counter++;
			p_counter = p_counter->p_next;
		}
		DPRINTF("-----Length = %d-----",counter);
	}

}

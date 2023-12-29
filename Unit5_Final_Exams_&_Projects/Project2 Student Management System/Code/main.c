/*
 * main.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Aly
 */


#include "FIFO.h"

int main()
{
	int temp=0;
	FIFO_Buffer_t FIFO_Buf;
	FIFO_init(&FIFO_Buf, buffer, 50);

	DPRINTF("Hello! \nWelcome to our 'Student Management System'");

	while(1)
	{
		DPRINTF("\n--0. Exit");
		DPRINTF("\n--1. Add a student");
		DPRINTF("\n--2. Print Students' List");
		DPRINTF("\n--3. Enter ID to search for");
		DPRINTF("\n--4. Enter Student's First name to search for");
		DPRINTF("\n--5. Enter Course ID to search students enrolled in it");
		DPRINTF("\n--6. Print Total Number of students in the List");
		DPRINTF("\n--7. Delete a student from the list");
		DPRINTF("\n--8. Update a student in the list");
		DPRINTF("\n--9. ADD Students from an external File");
		DPRINTF("\n-------------------------------------------------------");
		DPRINTF("\nEnter a number from the list:");

		scanf("%d",&temp);
		switch(temp)
		{
		case 0: printf("GOODBYE");  return 0; break;
		case 1:
			add_Students(&FIFO_Buf); break;
		case 2:
			FIFO_print(&FIFO_Buf); break;
		case 3:
			find_ID(&FIFO_Buf); break;
		case 4:
			find_firstName(&FIFO_Buf); break;
		case 5:
			num_Students_Enrolled(&FIFO_Buf); break;
		case 6:
			countStudents(&FIFO_Buf); break;
		case 7:
			deleteStudent(&FIFO_Buf); break;
		case 8:
			updateStudent(&FIFO_Buf); break;
		case 9:
			add_Students_file(&FIFO_Buf); break;
		}
	}
}

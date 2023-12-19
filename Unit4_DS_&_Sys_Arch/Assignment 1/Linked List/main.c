/*
 * main.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Ahmed Ali
 */

#include "linkedlist.h"


int main()
{
	char temp[10];
	DPRINTF("\n----------Hello, this is a Data record for students ");

	while(1)
	{
		DPRINTF("\nChoose one of the following options");
		DPRINTF("\n0: Close List");
		DPRINTF("\n1: Add a Student");
		DPRINTF("\n2: Delete a Student");
		DPRINTF("\n3: Print Students");
		DPRINTF("\n4: Delete All Students");
		DPRINTF("\n5: Reverse the List");
		DPRINTF("\n6: Length of the List");


		gets(temp);

		switch(atoi(temp))
		{
		case 0:
			printf("GOODBYE"); return 0;
			break ;
		case 1:
			addStudent();
			break ;
		case 2:
			deleteStudent();
			break ;
		case 3:
			printList();
			break ;
		case 4:
			deleteAll();
			break ;
		case 5:
			reverse();
			break ;
		case 6:
			itr_length();
			break ;
		default :
			printf("INVALID");
		}
	}
}

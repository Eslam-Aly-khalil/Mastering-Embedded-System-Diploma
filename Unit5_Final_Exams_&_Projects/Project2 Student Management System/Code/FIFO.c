/*
 * FIFO.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Aly
 */


#include "FIFO.h"

FIFO_status FIFO_init(FIFO_Buffer_t* FIFO_Buf, Sstudent* buffer, uint32_t length)
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
	Sstudent* ptr_temp =FIFO_Buf->base;
	int i,j;
	if (FIFO_Buf->count == 0)
	{
		printf("FIFO is empty");
	}

	DPRINTF("\n------------QUEUE PRINT-------------\n");
	for(i=0;i<FIFO_Buf->count;i++)
	{
		DPRINTF("\n-----------------------------------\n");
		DPRINTF("\n-------Info Student's ID:%d --------",ptr_temp->ID);
		DPRINTF("\nStudent's First Name:%s",ptr_temp->firstName);
		DPRINTF("\nStudent's Last Name:%s",ptr_temp->lastName);
		DPRINTF("\nStudent's GPA:%.2f",ptr_temp->gpa);

		for(j=0;j<3;j++)
		{
			DPRINTF("\nCourse Num:%d -->%d ",j+1,ptr_temp->courseNum[j]);
		}
		ptr_temp++;
	}
	printf("\n-------ENDED------------------\n");
}

FIFO_status add_Students(FIFO_Buffer_t* FIFO_Buf)
{
	int temp =0,i;

	//Checking if all pointers exist or not
	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;

	DPRINTF("Enter Student's ID number: ");
	scanf("%d",&temp);

	if(check_unique(FIFO_Buf,temp))
	{
		DPRINTF("\nID is already exist. please, Enter unique ID");
		return FIFO_NULL;
	}
	FIFO_Buf->head->ID =temp;

	DPRINTF("Enter Student's First Name: ");
	gets(FIFO_Buf->head->firstName);
	DPRINTF("Enter Student's Last Name: ");
	gets(FIFO_Buf->head->lastName);
	DPRINTF("Enter Student's GPA: ");
	scanf("%f",&FIFO_Buf->head->gpa);

	for(i=0;i<3;i++)
	{
		DPRINTF("Enter Student's %d Course: ",i+1);
		scanf("%d",&FIFO_Buf->head->courseNum[i]);
	}

	//Checking Circular Queue
	if(FIFO_Buf->head==(FIFO_Buf->base+(FIFO_Buf->length * sizeof(Sstudent))))
		FIFO_Buf->head=FIFO_Buf->base;
	else
		FIFO_Buf->head++;
	FIFO_Buf->count++;
	DPRINTF("Added Successfully ");

	return FIFO_noError;
}

int check_unique(FIFO_Buffer_t* FIFO_Buf, int num)
{
	int i;
	Sstudent* ptr_temp = FIFO_Buf->base;
	for(i=0;i<FIFO_Buf->count;i++)
	{
		if(ptr_temp->ID == num)
		{
			return 1;
		}
		ptr_temp++;
	}
	return 0;
}

FIFO_status find_ID(FIFO_Buffer_t* FIFO_Buf)
{
	Sstudent* ptr_temp = FIFO_Buf->base;
	int temp=0,i,j,flag=0;

	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;

	DPRINTF("--------------------------");
	DPRINTF("\nEnter Required ID: ");
	scanf("%d",&temp);

	for(i=0;i<FIFO_Buf->count;i++)
	{
		if(temp == ptr_temp->ID)
		{
			//FIFO_print(ptr_temp);
			DPRINTF("\n-------Info Student's ID:%d --------",ptr_temp->ID);
			DPRINTF("\nStudent's First Name:%s",ptr_temp->firstName);
			DPRINTF("\nStudent's Last Name:%s",ptr_temp->lastName);
			DPRINTF("\nStudent's GPA:%.2f",ptr_temp->gpa);

			for(j=0;j<3;j++)
			{
				DPRINTF("\nCourse Num:%d -->%d ",j+1,ptr_temp->courseNum[j]);
			}
			ptr_temp++;
			flag=1;

		}
	}
	if(flag)
		return FIFO_noError;
	else
		DPRINTF("Name '%s' is not exist",temp);
	return FIFO_NULL;
}

FIFO_status find_firstName(FIFO_Buffer_t* FIFO_Buf)
{

	Sstudent* ptr_temp = FIFO_Buf->base;
	int i,j,flag=0;
	char temp[50];

	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;

	DPRINTF("--------------------------");
	DPRINTF("\nEnter Required Name: ");
	gets(temp);

	for(i=0;i<FIFO_Buf->count;i++)
	{
		if(strcmp(temp,ptr_temp->firstName) == 0) //comparing strings using strcmp function
		{
			DPRINTF("\n-------Info Student's First Name:%s --------",ptr_temp->firstName);
			DPRINTF("\nStudent's ID:%d",ptr_temp->ID);
			DPRINTF("\nStudent's Last Name:%s",ptr_temp->lastName);
			DPRINTF("\nStudent's GPA:%.2f",ptr_temp->gpa);

			for(j=0;j<3;j++)
			{
				DPRINTF("\nCourse Num:%d -->%d ",j+1,ptr_temp->courseNum[j]);
			}
			ptr_temp++;
			flag = 1;
		}
	}
	if(flag)
		return FIFO_noError;
	else
		DPRINTF("Name '%s' is not exist",temp);
	return FIFO_NULL;
}

FIFO_status num_Students_Enrolled(FIFO_Buffer_t* FIFO_Buf)
{
	Sstudent* ptr_temp = FIFO_Buf->base;
	int temp=0,i,j,flag=0;

	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;

	DPRINTF("--------------------------");
	DPRINTF("\nEnter Course ID to search for students enrolled in it: ");
	scanf("%d",&temp);

	for(i=0;i<FIFO_Buf->count;i++)
	{
		for(j=0;j<3;j++)
		{
			if(temp == ptr_temp->courseNum[j])
			{

				DPRINTF("\n-------Student Enrolled in Course NO:%d --------",temp);
				DPRINTF("\nStudent's ID:%d",ptr_temp->ID);
				DPRINTF("\nStudent's Name:%s %s",ptr_temp->firstName,ptr_temp->lastName);
				flag=1;
			}
		}
		ptr_temp++;
	}
	if(flag)
		return FIFO_noError;
	else
		DPRINTF("Name '%s' is not exist",temp);
	return FIFO_NULL;
}

FIFO_status countStudents(FIFO_Buffer_t* FIFO_Buf)
{
	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;
	if(FIFO_Buf->count == 0)
		return FIFO_empty;

	DPRINTF("Total Numbers of students in the list=%d",FIFO_Buf->count);
	return FIFO_noError;
}

FIFO_status deleteStudent(FIFO_Buffer_t* FIFO_Buf)
{
	int i,j,temp=0,pos=0;
	Sstudent* ptr_temp = FIFO_Buf->base;

	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;
	DPRINTF("--------------------------");
	DPRINTF("\nEnter Student's ID: ");
	scanf("%d",&temp);

	for(i=0;i<FIFO_Buf->count;i++)
	{
		if(ptr_temp->ID == temp)
		{
			for(j=pos;j<FIFO_Buf->count;j++)
			{
				buffer[j] = buffer [j+1];
			}
			if(FIFO_Buf->tail == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(element_type))))
				FIFO_Buf->tail = FIFO_Buf->base;
			else
				FIFO_Buf->tail++;
			FIFO_Buf->count--;
			DPRINTF("====DELETED====");
			return FIFO_noError;
		}
		ptr_temp++;
		pos++;
	}

}

FIFO_status updateStudent(FIFO_Buffer_t* FIFO_Buf)
{
	int i,j,temp=0,flag=0;
	Sstudent* ptr_temp = FIFO_Buf->base;

	if (! FIFO_Buf->base || ! FIFO_Buf->head || ! FIFO_Buf->tail)
		return FIFO_NULL;

	DPRINTF("--------------------------");
	DPRINTF("\nEnter Student's ID: ");
	scanf("%d",&temp);

	for(i=0;i<FIFO_Buf->count;i++)
	{
		if(ptr_temp->ID == temp)
		{
			DPRINTF("----EDIT info in ID:%d----",ptr_temp->ID);
			DPRINTF("Enter Student's ID");
			scanf("%d",&ptr_temp->ID);
			DPRINTF("Enter Student's First Name");
			scanf("%s",ptr_temp->firstName);
			DPRINTF("Enter Student's Last Name");
			scanf("%s",ptr_temp->lastName);
			DPRINTF("Enter Student's GPA");
			scanf("%f",&ptr_temp->gpa);

			for(i=0;i<3;i++)
			{
				DPRINTF("Enter Student's %d Course: ",i+1);
				scanf("%d",&FIFO_Buf->head->courseNum[i]);
			}
			flag=1;
		}
		ptr_temp++;
	}
	if(flag)
		return FIFO_noError;
	else
		DPRINTF("ID '%d' is not exist",temp);
	return FIFO_NULL;
}

FIFO_status add_Students_file(FIFO_Buffer_t* FIFO_Buf)
{
	int temp=0;
		FILE* ptr_file = fopen("students.txt","r");        //Calling from "stdio.h"
		if(ptr_file == NULL)
		{
			printf("File not Found");
			return FIFO_NULL;
		}

		while (fscanf(ptr_file,"%d %s %s %f %d %d %d",&FIFO_Buf->head->ID,FIFO_Buf->head->firstName,FIFO_Buf->head->lastName,&FIFO_Buf->head->gpa,&FIFO_Buf->head->courseNum[0],&FIFO_Buf->head->courseNum[1],&FIFO_Buf->head->courseNum[2]) != EOF)
		{
			if(check_unique(FIFO_Buf,FIFO_Buf->head->ID))
			{
				DPRINTF("\nThere is an ID is already exist. please, make sure that all IDs are unique\n");
				continue;
			}
			if(FIFO_Buf->tail == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(Sstudent))))
				FIFO_Buf->head = FIFO_Buf->base;
			else
				FIFO_Buf->head++;
			FIFO_Buf->count++;
		}
		fclose(ptr_file);
		DPRINTF("ADDED SUCCESSUFULY");
		return FIFO_noError;

}

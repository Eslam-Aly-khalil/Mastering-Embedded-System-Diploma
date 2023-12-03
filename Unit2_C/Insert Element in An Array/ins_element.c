/*
 * main.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Eslam ALY
 */

#include "stdio.h"

int main()
{
	int num, i, element, real_pos;
	int arr[10];

	printf("Enter Number of Elements in Array:");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&num);

	printf("Enter Array Elements :");
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Enter the Element to be inserted :");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&element);

	printf("Enter the Position of the Element to be inserted :");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&real_pos);

	//Shifting Elements to make space in the required location
	for(i=num;i>=real_pos;i--)
	{
		arr[i] = arr[i-1];
	}

	arr[real_pos - 1] = element;
	num++;

	//Printing the array after insert the new element
	printf("Array After Insert The New Element: ");
	for(i=0;i<num;i++)
	{
		printf("%d",arr[i]);
	}
}

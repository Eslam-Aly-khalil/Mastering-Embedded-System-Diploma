/*
 * main.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Eslam ALY
 */
 
//This Program needs edit

#include "stdio.h"

int main()
{
	int rows, columns, i, j;
	int arr[5][5], trans[5][5];

	printf("Please Enter Rows and Columns of a matrix :");
	fflush(stdin);    fflush(stdout);
	scanf("%d %d",&rows,&columns);

	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("Enter Element of %d%d :",i+1,j+1);
			fflush(stdin);    fflush(stdout);
			scanf("%d",&arr[i][j]);
		}
	}

	//Printing the entered Matrix
	printf("The Matrix was entered: \n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("%d   ",arr[i][j]);
			if(j==(columns-1))
			{
				printf("\n\n");
			}

		}
	}

	//Transposing the entered array
	for(i=0;i<rows;++i)
	{
		for(j=0;j<columns;++j)
		{
			trans[j][i] = arr[i][j];
		}
	}

	//Printing the Transposed Array
	printf("The Matrix was transposed: \n");
	for(i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
			{
			    printf("%d   ",trans[i][j]);
				if(j==(rows-1))
				{
					printf("\n\n");
				}
			}
		}

}
#include "stdio.h"

int main()
{
	float arr1[2][2], arr2[2][2], arr3[2][2];
	int i,j;
	printf("Hello this is a sum of 2 dimensional arrays\n");

	printf("Enter the 1st matrix's elements :\n");

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter arr1[%d][%d]",i+1,j+1);
			fflush(stdin);     fflush(stdout);
			scanf("%f",&arr1[i][j]);
		}
	}

	printf("Enter the 2nd matrix's elements :\n");

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter arr2[%d][%d]",i+1,j+1);
			fflush(stdin);     fflush(stdout);
			scanf("%f",&arr2[i][j]);
		}
	}

	// Sum the two arrays that the user entered
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		arr3[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	
	// Printing the new array after sum
	printf("Sum of Matrices :\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%.1f ",arr3[i][j]);
			if(j==1)
			{
				printf("\n");
			}
		}
	}


}

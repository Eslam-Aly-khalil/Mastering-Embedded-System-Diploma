#include "stdio.h"

int main()
{
	int num_of_elements,i;
	float sum=0, avg=0;
	int arr[100];

	//Asking user to enter number of elements of an array
	printf("Enter the number of data:");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&num_of_elements);

	//Asking user to enter the elements in the array
	for(i=0;i<num_of_elements;i++)
	{
		fflush(stdin);   fflush(stdout);
		printf("Enter Number %d:",i+1);
		fflush(stdin);   fflush(stdout);
		scanf("%d",&arr[i]);
		sum += arr[i];
	}

	//Getting the average of the data entered
	avg = sum / num_of_elements;
	printf("%f",avg);
	return 0;
}

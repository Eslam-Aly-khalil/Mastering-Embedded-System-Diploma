#include "stdio.h"

int main()
{
	int arr[15];
	int n=0,i;
	int* ptr;

	printf("Input the number of elements to store in the array (max 15):");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&n);
	ptr = &arr[0];
	printf("Input %d number of elements in the array\n",n);

	for(i=0;i<n;i++)
	{
		printf("Element-%d =",i+1);
		scanf("%d",ptr);
		ptr++;
	}
	printf("\nThe elements of array in reverse order are :\n");
	ptr =&arr[n-1];
	for(i=n;i>0;i--)
	{
		printf("Element-%d = %d \n",i,*ptr);
		ptr--;
	}
	return 0;
}

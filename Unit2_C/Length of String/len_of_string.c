#include "stdio.h"

int main()
{
	char str[200];
	int i, counter=0;

	printf("Enter a String: ");
	fflush(stdin);    fflush(stdout);
	scanf("%s",str);

	for(i=0;str[i] != '\0';i++)
	{
		counter++;
	}
	printf("You entered string of %d char",counter);
	return 0;
}

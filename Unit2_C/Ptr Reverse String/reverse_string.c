#include "stdio.h"

int main()
{
	char str[50];
	char* ptr_str = str;
	int i=-1;

	printf("Enter a string:");
	fflush(stdin);   fflush(stdout);
	scanf("%s",str);

	while(*ptr_str != NULL)
	{
		printf("%c",*ptr_str);
		ptr_str++;
		i++;
	}
	printf("\n");
	while(i>=0)
	{
		i--;
		ptr_str--;
		printf("%c",*ptr_str);
	}

	return 0;
}

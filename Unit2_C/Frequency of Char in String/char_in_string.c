#include "stdio.h"

int main()
{
	char str[1000], x;
	int i, counter=0;

	printf("Enter String :");
	gets(str);
	printf("Enter a character to find in sequence:");
	scanf("%c",&x);

	for(i=0;str[i] != '\0';i++)
	{
		if(str[i] == x)
		{
			counter++;
		}
	}
	printf("%c is repeated %d times",x,counter);

}

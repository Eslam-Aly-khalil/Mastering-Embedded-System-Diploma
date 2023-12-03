#include "stdio.h"

int main()
{
	char str[200];
	int i, counter=0, str_begin, str_end, temp=0;

	printf("Enter a String: ");
	fflush(stdin);    fflush(stdout);
	scanf("%s",str);

	for(i=0;str[i] != '\0';i++)
	{
		counter++;
	}
	printf("You entered string of %d char\n",counter);

	str_begin =0;
	str_end = counter-1;

	while(str_begin < str_end)
	{
		temp = str[str_begin];
		str[str_begin] = str[str_end];
		str[str_end] = temp;
		str_begin++;
		str_end--;
	}
	printf("Reverse String : %s", str);
	return 0;
}

#include "stdio.h"

int main()
{
	int i;
	char alphabets[27];
	char* ptr_alpha = alphabets;

	for(i=0;i<26;i++)
	{
		*ptr_alpha = i+'A';
		printf("%c  ",*ptr_alpha);
		ptr_alpha++;
	}
	return 0;
}

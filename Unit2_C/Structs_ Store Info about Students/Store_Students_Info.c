#include "stdio.h"

struct student {
	char name[50];
	int roll;
	float marks;
}s;

int main()
{
	printf("Enter Student's Name:");
	fflush(stdin);       fflush(stdout);
	scanf("%s",s.name);
	printf("Enter Student's roll:");
	fflush(stdin);       fflush(stdout);
	scanf("%d",&s.roll);
	printf("Enter Student's marks:");
	fflush(stdin);       fflush(stdout);
	scanf("%f",&s.marks);

	printf("You entered --> \n\n");
	printf("Student's Name : %s\n",s.name);
	printf("Student's Roll : %d\n",s.roll);
	printf("Student's Marks: %f\n",s.marks);
}

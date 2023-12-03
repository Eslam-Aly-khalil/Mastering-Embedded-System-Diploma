#include "stdio.h"

struct Sstudent {
	char   name[20];
	int    roll;
	float  marks;
}student[10];


int main()
{
	int i;
	printf("Enter Information of Students \n");
	for(i=0;i<3;i++)
	{
		student[i].roll = i+1;
		printf("For Roll no.%d\n",student[i].roll);
		printf("Enter Name:");
		fflush(stdin);       fflush(stdout);
		scanf("%s",student[i].name);
		printf("Enter marks:");
		fflush(stdin);       fflush(stdout);
		scanf("%f",&student[i].marks);
		printf("\n");
	}

	printf("\n Display Students List\n");

	for(i=0;i<3;i++)
	{
		printf("Roll no.%d\n",student[i].roll);
		printf("Name: %s\n",student[i].name);
		printf("Marks: %.2f\n",student[i].marks);
		printf("\n");
	}
}

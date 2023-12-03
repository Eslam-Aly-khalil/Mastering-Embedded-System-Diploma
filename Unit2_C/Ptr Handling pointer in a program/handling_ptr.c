#include "stdio.h"

int main()
{
	int m = 29;    //Declaring a variable m and assign a value to it
	int* ab;       //Initializing a pointer

	printf("Address of m: %p \nValue of m: %d",&m,m); //Printing address of Variable m and it's value

	ab = &m;
	printf("\nNow Pointer ab is pointing to m and having its address\n");
	printf("Address of pointer ab: %p \nContent of pointer ab: %d",ab,*ab);  //Printing address of Pointer ab and it's value

	m = 34;
	printf("\nNow The value of m is equal 34\n");
	printf("Address of pointer ab: %p \nContent of pointer ab: %d",ab,*ab);  //Printing address of Pointer ab and it's value

	*ab = 7;
	printf("\nNow Pointer ab is pointing to a value of 7\n");
	printf("Address of m: %p \nValue of m: %d",&m,m); //Printing address of Variable m and it's value

	return 0;
}

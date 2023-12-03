#include "stdio.h"

typedef struct Scomplex {
	float real;
	float imag;
}complex;

complex x1,x2,sum;

complex add_complex(complex x1, complex x2);

int main()
{
	printf("First Complex Number \n");
	printf("Enter The real number :");
	fflush(stdin);       fflush(stdout);
	scanf("%f",&x1.real);
	printf("Enter The imaginary number :");
	fflush(stdin);       fflush(stdout);
	scanf("%f",&x1.imag);

	printf("Second Complex Number \n");
	printf("Enter The real number :");
	fflush(stdin);       fflush(stdout);
	scanf("%f",&x2.real);
	printf("Enter The imaginary number :");
	fflush(stdin);       fflush(stdout);
	scanf("%f",&x2.imag);

	sum = add_complex(x1,x2);
	printf("Sum of 2 complex numbers %.1f+%.1fi",sum.real,sum.imag);
}

complex add_complex(complex x1, complex x2)
{
	complex sum;
	sum.real = x1.real + x2.real;
	sum.imag = x1.imag + x2.imag;
	return sum;
}

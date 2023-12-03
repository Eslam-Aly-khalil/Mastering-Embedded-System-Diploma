#include "stdio.h"

struct Sdistance {
	int feet;
	float inch;
}dis1,dis2,sum;

int main()
{
	printf("Enter First Distance in Feet and Inch \n");
	printf("Enter Feet :");
	fflush(stdin);       fflush(stdout);
	scanf("%d",&dis1.feet);
	printf("Enter Inch :");
	fflush(stdin);       fflush(stdout);
	scanf("%f",&dis1.inch);

	printf("Enter Second Distance in Feet and Inch \n");
	printf("Enter Feet :");
	fflush(stdin);       fflush(stdout);
	scanf("%d",&dis2.feet);
	printf("Enter Inch :");
	fflush(stdin);       fflush(stdout);
	scanf("%f",&dis2.inch);

	sum.feet = dis1.feet + dis2.feet;
	sum.inch = dis1.inch + dis2.inch;

	printf("Feet of Distance 1 = %d \n", dis1.feet);
	printf("Inch of Distance 1 = %f \n", dis1.inch);

	printf("Feet of Distance 2 = %d \n", dis2.feet);
	printf("Inch of Distance 2 = %f \n", dis2.inch);

	printf("Sum of Feet = %d \n",sum.feet);
	printf("Sum of Inch = %f \n",sum.inch);

	/*
	 * 1 foot --> 12 inches
	 * so if the sum of inches >= 12 --> foot will increase by 1
	 */

	if(sum.inch >= 12)
	{
		sum.inch -= 12;
		sum.feet++;
	}
	printf("Total Distance in Feet and Inches = %dft %fin",sum.feet,sum.inch);
	return 0;
}

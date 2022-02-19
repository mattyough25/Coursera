/*
Print Sine and Cosine Between 0 and 1
November 15, 2021
*/

#include <stdio.h> // include standard library
#include <math.h> // include math library

int main(void)
{
	double interval;
	int i; 				// declare variables

	printf("\nValues of Sine and Cosine (in radians) from 0-1:\n"); // Introduce computations
	
	for(i = 0; i <11; i++)
	{
		interval = i/10.0; // set interval from 0-1
		printf("sin(%f)=%f \t cos(%f)=%f\n", interval, sin(interval),interval, cos(interval)); // print sin and cos value between 0 and 1
	}
	return 0;
}
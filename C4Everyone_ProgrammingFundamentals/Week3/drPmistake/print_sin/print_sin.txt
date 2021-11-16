/*
Fix Dr. P's Mistake
Print Sine Over an Interval
November 15, 2021
*/

#include <stdio.h> // include standard library
#include <math.h> // include math library

int main(void)
{
	double interval;
	int i; 				// initialized variables
	for(i = 0; i <60; i++)
	{
		interval = i/10.0;
		printf("sin( %lf ) = %lf \t", interval, fabs(sin(interval))); // print sin value over an interval
	}

	printf("\n++++++++++++++\n"); // indicate end of sin computations
	return 0;
}
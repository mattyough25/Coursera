/*
Compute Average and Max
of an Array Read from File
December 7, 2021
*/

#include <stdio.h>
#include <stdlib.h>

double average(int d[], int size)
{
	int i;
	double avg = 0.0;

	for(i = 0; i < size; i++)
	{
		avg += d[i];
	}
	return(avg/size);
}
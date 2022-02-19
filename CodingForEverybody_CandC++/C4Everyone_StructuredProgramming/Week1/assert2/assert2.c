/*
Use assers within a trivial program
Matthew Yough
November 23, 2021
*/

#define NDEBUG // goes before assert.h

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
	assert(0);
	printf("My program runs\n");
	return 0;
}
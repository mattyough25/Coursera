/*
Expression Evaluation
Matthew Yough
Nov. 8, 2021
*/

#include <stdio.h>

int main(void)
{
int a = 5, b = 7, c = 0, d = 0; //initialize
c = a - b; // c = -2
printf("a = %d, b = %d, c = %d, d = %d\n",
	a, b, c, d);
c = b - a; // c = 2
printf("a = %d, b = %d, c = %d, d = %d\n",
	a, b, c, d);
c = a / b ; d = b / a; // c = 0 d = 1
printf("a = %d, b = %d, c = %d, d = %d\n",
	a, b, c, d);
c = a % b ; d = b % a; // c = 5 d = 2
printf("a = %d, b = %d, c = %d, d = %d\n",
	a, b, c, d);
c = -a - b ; d = -b - a; // c = -12 d = -12
printf("a = %d, b = %d, c = %d, d = %d\n",
	a, b, c, d);
c = ++a + b++ ; d +=5; // a = 6 c = 13 b = 8 d = -7 
printf("a = %d, b = %d, c = %d, d = %d\n",
	a, b, c, d);
return 0;
}
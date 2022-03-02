// Swap C Function
// Matthew Yough
// 20 December 2021

#include<stdio.h>

void swap_int(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

void swap_double(double* i, double* j)
{
	double temp = *i;
	*i = *j;
	*j = temp;
}

int main()
{
	int m = 5, n = 10;
	double x = 5.3, y = 10.6;
	printf("int inputs: %d, %d\n", m, n);
	swap_int(&m, &n);
	printf("int outputs: %d, %d\n", m, n);

	printf("double inputs: %lf, %lf\n", x, y);
	swap_double(&x, &y);
	printf("int outputs: %lf, %lf\n", x, y);

	system("pause");
	return(0);
}
/*
Merge Sort -size is a power of 2
Matthew Yough
November 19, 2021
*/

#include <stdio.h>

void print_array(int how_many, int data[], char *str)
{
	int i;
	printf("%s", str);

	for (i = 0; i < how_many; i++)
	{
		printf("%d\t", data[i]);
	}
}

void merge(int a[], int b[], int c[], int how_many_a, int how_many_b)
{
	int i = 0, j = 0, k = 0;

	while ( i < how_many_a && j < how_many_b)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while (i < how_many_a)
	{
		c[k++] = a[i++];
	}
	while (j < how_many_b)
	{
		c[k++] = b[j++];
	}
}

void mergesort( int key[], int how_many_a, int how_many_b) // a power of 2
{
	int j, k;

	int *w = (int*) malloc (how_many_a * sizeof(int));
	free(w);
	// int w[how_many_a]; The previous two lines is how you accomplish this line without an error

	for (k = 1; k < how_many_a; k *= 2)
	{
		for ( j = 0; j < how_many_b - k; j += 2 *k)
		{
			merge(key + j, key + j + k, w + j, k, k);
		}
		for ( j = 0; j < how_many_b; j++)
			key[j] = w[j];
	}
}

int main(void)
{
	const int SIZE = 8;
	int a[] = {99, 82, 74, 85, 92, 67, 76, 49};

	print_array(SIZE, a, "My grades\n");
	printf("\n\n");

	mergesort(a, SIZE, SIZE);
	print_array(SIZE, a, "My sorted grades\n");
	printf("\n\n");

	system("pause");
	return 0;
}
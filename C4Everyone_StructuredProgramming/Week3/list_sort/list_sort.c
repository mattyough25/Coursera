/*
Creating List and Bubble Sorting
December 2, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble(int data[], int how_many)
{
	int i, j;

	for (i = 0; i < how_many; i++)
	{
		for (j = how_many - 1; j > i; j--)
		{
			if (data[j-1] > data[j])
			{
				swap(&data[j-1], &data[j]);
			}
		}
	}
}

typedef struct list{ int data; struct list *next;} list;

int is_empty(const list *l)
{ 
	return (l == NULL);
}

list* create_list(int d)
{
	list* head = malloc(sizeof(list));
	head -> data = d;
	head -> next = NULL;
	return head;
}

list* add_to_front(int d, list* h)
{
	list* head = create_list(d);
	head -> next = h;
	return head;
}

list* array_to_list(int d[], int size)
{
	list* head = create_list(d[0]);
	int i;
	for(i = 1; i < size; i++)
	{
		head = add_to_front(d[i], head);
	}
	return head;
}

void print_list(list *h, char *title)
{
	int i;
	
	printf("%s\n", title);
	while (h != NULL)
	{
		for (i = 0; i < 100; i++)
		{
			if (i % 5 == 0)
				printf("\n%d : ", h -> data);
				//h = h -> next;
			else
				printf("%d : ", h -> data);
				h = h -> next;
		}
	}
}

int main()
{
	int i, size;

	list list_of_int;
	list* head = NULL;

	printf("How many random numbers do you want to generate?\n");
	scanf("%d", &size);

	int *data = (int*) malloc (size * sizeof(int)); // initialize data array

   /* Print random numbers */
   for( i = 0 ; i < size ; i++ ) 
   {
   	data[i] = rand() % 100;
   }

	head = array_to_list(data, size);
	print_list(head, "List of 100 Sorted Random Numbers from 0-100");
	printf("\n\n"); 

	system("pause");
	return 0;	
}
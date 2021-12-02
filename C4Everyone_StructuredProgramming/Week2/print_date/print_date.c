/*
Enumerated and Structure Types Homework
Print Data
November 24, 2021
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month; // define enum type "month"
typedef struct date { month m; int d;} date; // initialize date struct

void print_date(date d)
{
	switch(d.m) // switch that prints off the correct data given in the date structure "d"
	{
		case jan: printf(" January %d", d.d); break;
		case feb: printf(" February %d", d.d); break;
		case mar: printf(" March %d", d.d); break;
		case apr: printf(" April %d", d.d); break;
		case may: printf(" May %d", d.d); break;
		case jun: printf(" June %d", d.d); break;
		case jul: printf(" July %d", d.d); break;
		case aug: printf(" August %d", d.d); break;
		case sep: printf(" September %d", d.d); break;
		case oct: printf(" October %d", d.d); break;
		case nov: printf(" November %d", d.d); break;
		case dec: printf(" December %d", d.d); break;
		default: printf("Date is not Valid");
	}
}

struct date next_day(date d) // function to return the next day from the one given in date struct "d"
{

	if (d.m == 0 || d.m == 2 || d.m == 4 || d.m == 6 || d.m == 7 || d.m == 9) // months with 31 days excluding december
	{
		if (d.d < 31)
		{
			d.d++;
		}
		else if (d.d == 31) // evaluates if date is last day of the month
		{
			d.m++;
			d.d = 1;
		}
		else
		{
			printf("\nError: Not a Valid Date");
		}
		
	}
	else if (d.m == 3 || d.m == 5 || d.m == 7 || d.m == 10) // months with 30 days
	{
		if (d.d < 30)
		{
			d.d++;
		}
		else if (d.d == 30) // evaluates if date is last day of the month
		{
			d.m++;
			d.d = 1;
		}
		else
		{
			printf("\nError: Not a Valid Date");
		}
	}	
	else if (d.m ==11) // case for month of december
		if (d.d < 31)
		{
			d.d++;
		}
		else if (d.d == 31) // evaluates if date is last day of the month
		{
			d.m = 0;
			d.d = 1;
		}
		else
		{
			printf("\nError: Not a Valid Date");
		}
	else // case for month of february
	{
		if (d.d < 28)
		{
			d.d++;
		}
		else if (d.d == 28) // evaluates if date is last day of the month
		{
			d.m++;
			d.d = 1;
		}
		else
		{
			printf("\nError: Not a Valid Date");
		}
		
	}
	

	return (d);
}

int main(void)
{
	struct date date1; // define date structs
	struct date date2;
	struct date date3;
	struct date date4;
	struct date date5;
	
	date1.m = jan;
	date1.d = 1;

	date2.m = feb;
	date2.d = 28;

	date3.m = mar;
	date3.d = 14;

	date4.m = oct;
	date4.d = 31;

	date5.m = dec;
	date5.d = 31;

/* print the date and the date of the next day */ 
	print_date(date1);
	printf("\t");
	print_date(next_day(date1));
	printf("\n\n");

	print_date(date2);
	printf("\t");
	print_date(next_day(date2));
	printf("\n\n");

	print_date(date3);
	printf("\t");
	print_date(next_day(date3));
	printf("\n\n");

	print_date(date4);
	printf("\t");
	print_date(next_day(date4));
	printf("\n\n");

	print_date(date5);
	printf("\t");
	print_date(next_day(date5));
	printf("\n\n");
	
	system("pause");
	return 0;
}
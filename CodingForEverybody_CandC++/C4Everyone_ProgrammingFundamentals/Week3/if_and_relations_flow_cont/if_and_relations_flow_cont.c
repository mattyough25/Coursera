/*
Matthew Yough
if and relations and flow of control
November 15, 2021
*/

#include <stdio.h>
int main()
{
	int speed;
	printf("\nEnter your speed as an integer:");
	scanf("%d", &speed);
	if (speed < 65)
		printf("\nNo Speeding Ticket\n\n");
	else
		printf("\nSpeeding Ticket\n\n");
	return 0;
}
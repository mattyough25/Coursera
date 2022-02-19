/*
Matthew Yough
November 16, 2021
*/

#include <stdio.h>

void wrt_very(int count)
{
	while (count > 0)
	{
		printf("\nvery");
		count--;
	};
	printf("\nmuch.\n\n");
}

int main(void)
{
	int repeat = 0;
	printf("How strong is your love 1-10? : ");
	scanf("%d", &repeat);
	printf("\nI love you");
	wrt_very(repeat);
	return 0;
};
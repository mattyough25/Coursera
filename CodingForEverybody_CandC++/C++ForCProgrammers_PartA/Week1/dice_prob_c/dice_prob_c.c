// Dice Probability C Program
// Matthew Yough
// 18 December 2021

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define R_SIDE (rand() % SIDES + 1)

int main(void)
{
	int j, n_dice, trials, d1, d2;
	double outcomes;

	srand(clock());
	printf("\nEnter number of trials: ");
	scanf("%d", &trials);
	printf("\nEnter number of dice: ");
	scanf("%d", &n_dice);
	for(j = 0; j < trials; ++j)
	{
		outcomes[(d1 = R_SIDE)+(d2 = R_SIDE)]++;
	}
	printf("probability\n");
	for(j = 2; j < n_dice*SIDES+1; ++j)
	{
		printf("j=%d p=%lf\n", j, (double)(outcomes[j])/trials);
	}
}
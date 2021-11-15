/*
Print the value of sine between 0 and 1
November 12, 2021
*/

#include<stdio.h>
#include<math.h>

int main()
{

double input; // declare input type
printf("Enter a value between 0 and 1 (radians): "); // ask user for a value btwn 0 and 1
scanf("%lf", &input); // set input to the specified value by user

double sin_input = sin(input); //compute sine for input value
printf("\nsin of %lf is: \n", input); // print input value
printf("%lf", sin_input); // print sin of input value
return 0;

}
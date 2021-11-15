/*
Fix Dr. P's Mistake: Volume of a Sphere
November 12, 2021
*/

#include<stdio.h>

#define PI 3.14159

int main()
{ 
 double radius;
 printf("Enter radius: ");
 scanf("%lf", &radius);
 printf("volume is : %lf \n\n", (4/3.0)*PI*(radius*radius*radius) );
 return 0;
}
/*
Fix Dr. P's Mistake: Volume of a Sphere
November 12, 2021
*/

#include<stdio.h>

#define PI 3.14159

int main()
{ 
 int radius;
 printf("Enter radius: ");
 scanf("%d", &radius);
 printf("volume is : %lf \n\n", 4*PI*radius*radius*radius/3.0 );
 return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double a ;
    printf("Enter number: ");
    scanf("%lf" , &a);
    printf("%f" , sin(a));
}
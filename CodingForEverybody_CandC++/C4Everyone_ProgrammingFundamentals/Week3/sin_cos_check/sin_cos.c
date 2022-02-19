#include <stdio.h>
#include <math.h>
int main()
{

  double interval, i = 0;
  printf("Enter the interval of repetion  (eg. 0.1):\n");
  scanf("%lf", &interval);
  for (; i <= 1; i += interval) {
    printf("sin(%f)=%f \t cos(%f)=%f\n", i, sin(i),i, cos(i));


  }
  return 0;
}
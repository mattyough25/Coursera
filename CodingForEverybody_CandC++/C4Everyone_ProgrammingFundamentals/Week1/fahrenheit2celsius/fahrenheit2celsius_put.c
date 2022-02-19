/* C for Everyone
Conversion of Fahrenheit to Celsius

C = (F - 32)/1.8
Matthew Yough
November 1, 2021
*/

#include <stdio.h>
#include <mex.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

mxArray   *new_number, *str;
double fahrenheit, celsius;

str = mxCreateString("Enter Temperature in Fahrenheit:  ");
mexCallMATLAB(1,&new_number,1,&str,"input");
fahrenheit = mxGetScalar(new_number);

celsius = (fahrenheit - 32)/1.8; //note conversion
mexPrintf("\n %lf fahrenheit is %lf celsius.\n",fahrenheit,celsius);
return 0;
}
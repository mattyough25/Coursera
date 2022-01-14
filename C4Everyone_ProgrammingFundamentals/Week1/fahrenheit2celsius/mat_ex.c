#include "mex.h"
#include "string.h"

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
  mxArray   *new_number, *str;
  double out;

  str = mxCreateString("Enter extension:  ");
  mexCallMATLAB(1,&new_number,1,&str,"input");
  out = mxGetScalar(new_number);
  mexPrintf("You entered: %.0f ", out);
  mxDestroyArray(new_number);
  mxDestroyArray(str);
  return;
 }
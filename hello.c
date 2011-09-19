#include "mex.h" 
// Hello world example
// http://www.mathworks.com/support/tech-notes/1600/1605.html#example1
void mexFunction(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[]) {
  mexPrintf("Hello, world!\n"); 
}
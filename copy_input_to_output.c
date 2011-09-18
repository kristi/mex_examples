/*=================================================================
 * arrayFillSetData.c - example used to illustrate how to fill an mxArray
 *
 * Same functionality as arrayFillSetPr.c, except the function
 * mxSetData operates on data types other than double.
 *
 * UINT16_T declares appropriate uint16 type for platform
 *
 * Input:   none
 * Output:  mxArray
 *
 * Copyright 2008 The MathWorks, Inc.
 * $Revision: 1.1.6.1 $ 
 *	
 *=================================================================*/
#include "mex.h"

#define DEBUG 1

//#define input prhs
//#define output plhs
//#define nargin nrhs
//#define nargout nlhs

void mexFunction(int nargout, mxArray *output[], int nargin, const mxArray *input[]) {
    mwSize ndim;
    mwSize m;
    mwSize n;
    mwSize numEl;
    const mwSize* dim;
    double *inData;
    double *outData;
    
    int i,j;
    
    if(DEBUG){
        mexPrintf("There are %d input argument(s).\n", nargin);
        for (i=0; i<nargin; i++)  {
            mexPrintf("\tInput arg %i is of type:\t%s \n",i,mxGetClassName(input[i]));
        }
        mexPrintf("There are %d output argument(s).\n", nargout);
    }

	// Check for proper number of arguments.
    if ( nargin < 1 ) {
        mexErrMsgIdAndTxt("MATLAB:randg_:rhs","Requires at least one input argument.");
    }
    // First argument must be real matrix
    if (!mxIsDouble(input[0]) || mxIsComplex(input[0])) {
        mexErrMsgTxt("First input argument must be real numbers.");
    }
    if(mxIsSparse(input[0])){
        mexErrMsgTxt("Sparse input not allowed.");
    }
    
    numEl = mxGetNumberOfElements(input[0]);
    ndim = mxGetNumberOfDimensions(input[0]);
    dim = mxGetDimensions(input[0]);
    m = mxGetM(input[0]);
    n = mxGetN(input[0]);
    inData = mxGetPr(input[0]);
    
    if(DEBUG){
        mexPrintf("numEl = %i\n", (int)numEl);
        mexPrintf("ndim = %i\n", ndim);
        mexPrintf("m = %i\n", m);
        mexPrintf("n = %i\n", n);
        mexPrintf("dim = [ ", n);
        for(i=0; i<ndim; ++i){
            mexPrintf("%i ", dim[i]);
        }
        mexPrintf("]\n");
    }
    
    // Allocate the output the same size as the input
    output[0] = mxCreateNumericArray(ndim, dim, mxDOUBLE_CLASS, mxREAL);
    outData = mxGetPr(output[0]);
    
    // Copy input to output
    for(i=0; i<numEl; ++i){
        outData[i] = inData[i];
    }
    
    return;
}


//
// File: str2double1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

#ifndef STR2DOUBLE1_H
#define STR2DOUBLE1_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
boolean_T b_copydigits(char s1[3], int *idx, char s, int *k,
                       boolean_T allowpoint);

void b_readfloat(::coder::array<char, 2U> &s1, int *idx,
                 const ::coder::array<char, 2U> &s, int *k, int n,
                 boolean_T allowimag, boolean_T *isimag, boolean_T *b_finite,
                 double *nfv, boolean_T *foundsign, boolean_T *success);

boolean_T copyexponent(char s1[3], int *idx, char s, int *k);

void readNonFinite(char s, int *k, boolean_T *b_finite, double *fv);

void readfloat(char s1[3], int *idx, char s, int *k, boolean_T allowimag,
               boolean_T *isimag, boolean_T *b_finite, double *nfv,
               boolean_T *foundsign, boolean_T *success);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for str2double1.h
//
// [EOF]
//

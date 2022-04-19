//
// File: mtimes.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

// Include Files
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 2U> &B
//                ::coder::array<double, 2U> &C
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void mtimes(const ::coder::array<double, 2U> &A,
            const ::coder::array<double, 2U> &B, ::coder::array<double, 2U> &C)
{
  int inner;
  int mc;
  int nc;
  mc = A.size(0) - 1;
  inner = A.size(1);
  nc = B.size(1);
  C.set_size(A.size(0), B.size(1));
  for (int j{0}; j < nc; j++) {
    int i;
    for (i = 0; i <= mc; i++) {
      C[i] = 0.0;
    }
    for (int k{0}; k < inner; k++) {
      int aoffset;
      aoffset = k * A.size(0);
      for (i = 0; i <= mc; i++) {
        C[i] = C[i] + A[aoffset + i] * B[k];
      }
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for mtimes.cpp
//
// [EOF]
//

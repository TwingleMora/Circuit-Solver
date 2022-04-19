//
// File: sum.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 01:10:06
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<double, 2U> &y
// Return Type  : void
//
namespace coder {
void sum(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y)
{
  if (x.size(1) == 0) {
    y.set_size(1, 0);
  } else {
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    int npages;
    npages = x.size(1);
    y.set_size(1, x.size(1));
    if (x.size(0) <= 1024) {
      firstBlockLength = x.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = x.size(0) / 1024;
      lastBlockLength = x.size(0) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    for (int xi{0}; xi < npages; xi++) {
      int k;
      int xpageoffset;
      xpageoffset = xi * x.size(0);
      y[xi] = x[xpageoffset];
      for (k = 2; k <= firstBlockLength; k++) {
        y[xi] = y[xi] + x[(xpageoffset + k) - 1];
      }
      for (int ib{2}; ib <= nblocks; ib++) {
        double bsum;
        int hi;
        int xblockoffset;
        xblockoffset = xpageoffset + ((ib - 1) << 10);
        bsum = x[xblockoffset];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (k = 2; k <= hi; k++) {
          bsum += x[(xblockoffset + k) - 1];
        }
        y[xi] = y[xi] + bsum;
      }
    }
  }
}

} // namespace coder

//
// File trailer for sum.cpp
//
// [EOF]
//

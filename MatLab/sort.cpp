//
// File: sort.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

// Include Files
#include "sort.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<double, 1U> &x
// Return Type  : void
//
namespace coder {
namespace internal {
void sort(::coder::array<double, 1U> &x)
{
  array<double, 1U> b_xwork;
  array<double, 1U> vwork;
  array<double, 1U> xwork;
  array<int, 1U> b_iwork;
  array<int, 1U> iidx;
  array<int, 1U> iwork;
  double c_xwork[256];
  double x4[4];
  int c_iwork[256];
  int idx4[4];
  int bLen;
  int b_n;
  int i1;
  int i3;
  int i4;
  int ib;
  int iidx_tmp;
  int k;
  int n;
  int nNonNaN;
  int quartetOffset;
  int vlen;
  signed char perm[4];
  vlen = x.size(0) - 1;
  vwork.set_size(x.size(0));
  for (k = 0; k <= vlen; k++) {
    vwork[k] = x[k];
  }
  iidx.set_size(vwork.size(0));
  ib = vwork.size(0);
  for (i1 = 0; i1 < ib; i1++) {
    iidx[i1] = 0;
  }
  n = vwork.size(0);
  b_n = vwork.size(0);
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  iwork.set_size(vwork.size(0));
  ib = vwork.size(0);
  for (i1 = 0; i1 < ib; i1++) {
    iwork[i1] = 0;
  }
  xwork.set_size(vwork.size(0));
  ib = vwork.size(0);
  for (i1 = 0; i1 < ib; i1++) {
    xwork[i1] = 0.0;
  }
  bLen = 0;
  ib = -1;
  for (k = 0; k < b_n; k++) {
    if (std::isnan(vwork[k])) {
      iidx_tmp = (b_n - bLen) - 1;
      iidx[iidx_tmp] = k + 1;
      xwork[iidx_tmp] = vwork[k];
      bLen++;
    } else {
      ib++;
      idx4[ib] = k + 1;
      x4[ib] = vwork[k];
      if (ib + 1 == 4) {
        double d;
        double d1;
        quartetOffset = k - bLen;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          ib = 2;
        } else {
          i1 = 2;
          ib = 1;
        }
        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }
        d = x4[i1 - 1];
        d1 = x4[i3 - 1];
        if (d <= d1) {
          d = x4[ib - 1];
          if (d <= d1) {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(ib);
            perm[2] = static_cast<signed char>(i3);
            perm[3] = static_cast<signed char>(i4);
          } else if (d <= x4[i4 - 1]) {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i3);
            perm[2] = static_cast<signed char>(ib);
            perm[3] = static_cast<signed char>(i4);
          } else {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i3);
            perm[2] = static_cast<signed char>(i4);
            perm[3] = static_cast<signed char>(ib);
          }
        } else {
          d1 = x4[i4 - 1];
          if (d <= d1) {
            if (x4[ib - 1] <= d1) {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i1);
              perm[2] = static_cast<signed char>(ib);
              perm[3] = static_cast<signed char>(i4);
            } else {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i1);
              perm[2] = static_cast<signed char>(i4);
              perm[3] = static_cast<signed char>(ib);
            }
          } else {
            perm[0] = static_cast<signed char>(i3);
            perm[1] = static_cast<signed char>(i4);
            perm[2] = static_cast<signed char>(i1);
            perm[3] = static_cast<signed char>(ib);
          }
        }
        iidx[quartetOffset - 3] = idx4[perm[0] - 1];
        iidx[quartetOffset - 2] = idx4[perm[1] - 1];
        iidx[quartetOffset - 1] = idx4[perm[2] - 1];
        iidx[quartetOffset] = idx4[perm[3] - 1];
        vwork[quartetOffset - 3] = x4[perm[0] - 1];
        vwork[quartetOffset - 2] = x4[perm[1] - 1];
        vwork[quartetOffset - 1] = x4[perm[2] - 1];
        vwork[quartetOffset] = x4[perm[3] - 1];
        ib = -1;
      }
    }
  }
  i3 = (b_n - bLen) - 1;
  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib + 1 == 1) {
      perm[0] = 1;
    } else if (ib + 1 == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }
    for (k = 0; k <= ib; k++) {
      iidx_tmp = perm[k] - 1;
      quartetOffset = (i3 - ib) + k;
      iidx[quartetOffset] = idx4[iidx_tmp];
      vwork[quartetOffset] = x4[iidx_tmp];
    }
  }
  ib = (bLen >> 1) + 1;
  for (k = 0; k <= ib - 2; k++) {
    quartetOffset = (i3 + k) + 1;
    i1 = iidx[quartetOffset];
    iidx_tmp = (b_n - k) - 1;
    iidx[quartetOffset] = iidx[iidx_tmp];
    iidx[iidx_tmp] = i1;
    vwork[quartetOffset] = xwork[iidx_tmp];
    vwork[iidx_tmp] = xwork[quartetOffset];
  }
  if ((bLen & 1) != 0) {
    ib += i3;
    vwork[ib] = xwork[ib];
  }
  nNonNaN = n - bLen;
  quartetOffset = 2;
  if (nNonNaN > 1) {
    if (n >= 256) {
      int nBlocks;
      nBlocks = nNonNaN >> 8;
      if (nBlocks > 0) {
        for (int b{0}; b < nBlocks; b++) {
          i4 = (b << 8) - 1;
          for (int b_b{0}; b_b < 6; b_b++) {
            bLen = 1 << (b_b + 2);
            b_n = bLen << 1;
            n = 256 >> (b_b + 3);
            for (k = 0; k < n; k++) {
              i1 = (i4 + k * b_n) + 1;
              for (quartetOffset = 0; quartetOffset < b_n; quartetOffset++) {
                ib = i1 + quartetOffset;
                c_iwork[quartetOffset] = iidx[ib];
                c_xwork[quartetOffset] = vwork[ib];
              }
              i3 = 0;
              quartetOffset = bLen;
              ib = i1 - 1;
              int exitg1;
              do {
                exitg1 = 0;
                ib++;
                if (c_xwork[i3] <= c_xwork[quartetOffset]) {
                  iidx[ib] = c_iwork[i3];
                  vwork[ib] = c_xwork[i3];
                  if (i3 + 1 < bLen) {
                    i3++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  iidx[ib] = c_iwork[quartetOffset];
                  vwork[ib] = c_xwork[quartetOffset];
                  if (quartetOffset + 1 < b_n) {
                    quartetOffset++;
                  } else {
                    ib -= i3;
                    for (quartetOffset = i3 + 1; quartetOffset <= bLen;
                         quartetOffset++) {
                      iidx_tmp = ib + quartetOffset;
                      iidx[iidx_tmp] = c_iwork[quartetOffset - 1];
                      vwork[iidx_tmp] = c_xwork[quartetOffset - 1];
                    }
                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }
        ib = nBlocks << 8;
        quartetOffset = nNonNaN - ib;
        if (quartetOffset > 0) {
          merge_block(iidx, vwork, ib, quartetOffset, 2, iwork, xwork);
        }
        quartetOffset = 8;
      }
    }
    ib = iwork.size(0);
    b_iwork.set_size(iwork.size(0));
    for (i1 = 0; i1 < ib; i1++) {
      b_iwork[i1] = iwork[i1];
    }
    b_xwork.set_size(xwork.size(0));
    ib = xwork.size(0);
    for (i1 = 0; i1 < ib; i1++) {
      b_xwork[i1] = xwork[i1];
    }
    merge_block(iidx, vwork, 0, nNonNaN, quartetOffset, b_iwork, b_xwork);
  }
  for (k = 0; k <= vlen; k++) {
    x[k] = vwork[k];
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for sort.cpp
//
// [EOF]
//

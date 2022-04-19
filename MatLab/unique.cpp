//
// File: unique.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

// Include Files
#include "unique.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &a
//                ::coder::array<double, 2U> &b
// Return Type  : void
//
namespace coder {
void unique_vector(const ::coder::array<double, 2U> &a,
                   ::coder::array<double, 2U> &b)
{
  array<int, 2U> idx;
  array<int, 1U> iwork;
  double absx;
  int b_i;
  int exponent;
  int i;
  int i2;
  int j;
  int k;
  int n;
  int na;
  int nb;
  int p;
  int qEnd;
  na = a.size(1);
  n = a.size(1) + 1;
  idx.set_size(1, a.size(1));
  i = a.size(1);
  for (b_i = 0; b_i < i; b_i++) {
    idx[b_i] = 0;
  }
  if (a.size(1) != 0) {
    iwork.set_size(a.size(1));
    b_i = a.size(1) - 1;
    for (k = 1; k <= b_i; k += 2) {
      absx = a[k];
      if ((a[k - 1] <= absx) || std::isnan(absx)) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
    }
    if ((a.size(1) & 1) != 0) {
      idx[a.size(1) - 1] = a.size(1);
    }
    i = 2;
    while (i < n - 1) {
      i2 = i << 1;
      j = 1;
      for (nb = i + 1; nb < n; nb = qEnd + i) {
        int kEnd;
        int q;
        p = j;
        q = nb - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          absx = a[idx[q] - 1];
          b_i = idx[p - 1];
          if ((a[b_i - 1] <= absx) || std::isnan(absx)) {
            iwork[k] = b_i;
            p++;
            if (p == nb) {
              while (q + 1 < qEnd) {
                k++;
                iwork[k] = idx[q];
                q++;
              }
            }
          } else {
            iwork[k] = idx[q];
            q++;
            if (q + 1 == qEnd) {
              while (p < nb) {
                k++;
                iwork[k] = idx[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }
        j = qEnd;
      }
      i = i2;
    }
  }
  b.set_size(1, a.size(1));
  for (k = 0; k < na; k++) {
    b[k] = a[idx[k] - 1];
  }
  k = a.size(1);
  while ((k >= 1) && std::isnan(b[k - 1])) {
    k--;
  }
  i2 = a.size(1) - k;
  while ((k >= 1) && std::isinf(b[k - 1])) {
    k--;
  }
  i = (a.size(1) - k) - i2;
  nb = -1;
  p = 0;
  while (p + 1 <= k) {
    double x;
    x = b[p];
    int exitg1;
    do {
      exitg1 = 0;
      p++;
      if (p + 1 > k) {
        exitg1 = 1;
      } else {
        absx = std::abs(x / 2.0);
        if ((!std::isinf(absx)) && (!std::isnan(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &exponent);
            absx = std::ldexp(1.0, exponent - 53);
          }
        } else {
          absx = rtNaN;
        }
        if ((!(std::abs(x - b[p]) < absx)) &&
            ((!std::isinf(b[p])) || (!std::isinf(x)) ||
             ((b[p] > 0.0) != (x > 0.0)))) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
    nb++;
    b[nb] = x;
  }
  if (i > 0) {
    nb++;
    b[nb] = b[k];
  }
  p = k + i;
  for (j = 0; j < i2; j++) {
    b[(nb + j) + 1] = b[p + j];
  }
  nb += i2;
  if (1 > nb + 1) {
    b_i = 0;
  } else {
    b_i = nb + 1;
  }
  b.set_size(b.size(0), b_i);
}

} // namespace coder

//
// File trailer for unique.cpp
//
// [EOF]
//

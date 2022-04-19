//
// File: eml_setop.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

// Include Files
#include "eml_setop.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Declarations
namespace coder {
static double skip_to_last_equal_value(int *k,
                                       const ::coder::array<double, 2U> &x);

}

// Function Definitions
//
// Arguments    : int *k
//                const ::coder::array<double, 2U> &x
// Return Type  : double
//
namespace coder {
static double skip_to_last_equal_value(int *k,
                                       const ::coder::array<double, 2U> &x)
{
  double xk;
  int exponent;
  boolean_T exitg1;
  xk = x[*k - 1];
  exitg1 = false;
  while ((!exitg1) && (*k < x.size(1))) {
    double absx;
    absx = std::abs(xk / 2.0);
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
    if ((std::abs(xk - x[*k]) < absx) || (std::isinf(x[*k]) && std::isinf(xk) &&
                                          ((x[*k] > 0.0) == (xk > 0.0)))) {
      (*k)++;
    } else {
      exitg1 = true;
    }
  }
  return xk;
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 1U> &b
//                ::coder::array<double, 2U> &c
//                ::coder::array<int, 1U> &ia
//                int *ib_size
// Return Type  : void
//
void do_vectors(const ::coder::array<double, 2U> &a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                int *ib_size)
{
  double ak;
  int b_exponent;
  int b_ialast;
  int exponent;
  int iafirst;
  int ialast;
  int iblast;
  int na;
  int nc;
  int nia;
  na = a.size(1);
  c.set_size(1, a.size(1));
  ia.set_size(a.size(1));
  *ib_size = 0;
  nc = 0;
  nia = 0;
  iafirst = 0;
  ialast = 1;
  iblast = 1;
  while ((ialast <= na) && (iblast <= b.size(0))) {
    double absx;
    double bk;
    boolean_T exitg1;
    b_ialast = ialast;
    ak = skip_to_last_equal_value(&b_ialast, a);
    ialast = b_ialast;
    bk = b[iblast - 1];
    exitg1 = false;
    while ((!exitg1) && (iblast < b.size(0))) {
      absx = std::abs(bk / 2.0);
      if ((!std::isinf(absx)) && (!std::isnan(absx))) {
        if (absx <= 2.2250738585072014E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &b_exponent);
          absx = std::ldexp(1.0, b_exponent - 53);
        }
      } else {
        absx = rtNaN;
      }
      if ((std::abs(bk - b[iblast]) < absx) ||
          (std::isinf(b[iblast]) && std::isinf(bk) &&
           ((b[iblast] > 0.0) == (bk > 0.0)))) {
        iblast++;
      } else {
        exitg1 = true;
      }
    }
    absx = std::abs(bk / 2.0);
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
    if ((std::abs(bk - ak) < absx) ||
        (std::isinf(ak) && std::isinf(bk) && ((ak > 0.0) == (bk > 0.0)))) {
      ialast = b_ialast + 1;
      iafirst = b_ialast;
      iblast++;
    } else {
      boolean_T p;
      if (std::isnan(bk)) {
        p = !std::isnan(ak);
      } else if (std::isnan(ak)) {
        p = false;
      } else {
        p = (ak < bk);
      }
      if (p) {
        nc++;
        nia++;
        c[nc - 1] = ak;
        ia[nia - 1] = iafirst + 1;
        ialast = b_ialast + 1;
        iafirst = b_ialast;
      } else {
        iblast++;
      }
    }
  }
  while (ialast <= na) {
    iblast = ialast;
    ak = skip_to_last_equal_value(&iblast, a);
    nc++;
    nia++;
    c[nc - 1] = ak;
    ia[nia - 1] = iafirst + 1;
    ialast = iblast + 1;
    iafirst = iblast;
  }
  if (a.size(1) > 0) {
    if (1 > nia) {
      nia = 0;
    }
    ia.set_size(nia);
    if (1 > nc) {
      nc = 0;
    }
    c.set_size(c.size(0), nc);
  }
}

} // namespace coder

//
// File trailer for eml_setop.cpp
//
// [EOF]
//

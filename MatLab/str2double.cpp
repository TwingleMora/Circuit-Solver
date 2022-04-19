//
// File: str2double.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

// Include Files
#include "str2double.h"
#include "rt_nonfinite.h"
#include "solver1_data.h"
#include "str2double1.h"
#include "coder_array.h"
#include <stdio.h>

// Function Definitions
//
// Arguments    : char s
// Return Type  : creal_T
//
namespace coder {
creal_T str2double(char s)
{
  creal_T x;
  double b_scanned1;
  double scanned1;
  double scanned2;
  int i;
  int idx;
  int k;
  int ntoread;
  char s1[3];
  boolean_T b_finite;
  boolean_T exitg1;
  boolean_T foundsign;
  boolean_T isfinite2;
  boolean_T isimag1;
  boolean_T isneg;
  boolean_T success;
  x.re = rtNaN;
  x.im = 0.0;
  ntoread = 0;
  k = 1;
  i = static_cast<unsigned char>(s) & 127;
  if (bv[i] || (s == '\x00')) {
    k = 2;
  }
  isimag1 = false;
  b_finite = true;
  scanned1 = 0.0;
  idx = 1;
  s1[0] = '\x00';
  s1[1] = '\x00';
  s1[2] = '\x00';
  isneg = false;
  exitg1 = false;
  while ((!exitg1) && (k <= 1)) {
    if (s == '-') {
      isneg = !isneg;
      k = 2;
    } else if ((s == ',') || (s == '+') || bv[i]) {
      k = 2;
    } else {
      exitg1 = true;
    }
  }
  success = (k <= 1);
  if (success && isneg) {
    s1[0] = '-';
    idx = 2;
  }
  if (success) {
    isneg = false;
    if (k <= 1) {
      isneg = ((s == 'j') || (s == 'i'));
    }
    if (isneg) {
      isimag1 = true;
      k++;
      s1[idx - 1] = '1';
      idx++;
    } else {
      internal::readNonFinite(s, &k, &b_finite, &scanned1);
      if (b_finite) {
        success = internal::b_copydigits(s1, &idx, s, &k, true);
        if (success) {
          success = internal::copyexponent(s1, &idx, s, &k);
        }
      } else if ((idx >= 2) && (s1[0] == '-')) {
        idx = 1;
        s1[0] = ' ';
        scanned1 = -scanned1;
      }
      while ((k <= 1) && (bv[i] || (s == '\x00') || (s == ','))) {
        k = 2;
      }
      if ((k <= 1) && (s == '*')) {
        k = 2;
      }
      if ((k <= 1) && ((s == 'i') || (s == 'j'))) {
        k = 2;
        isimag1 = true;
      }
    }
    while ((k <= 1) && (bv[i] || (s == '\x00') || (s == ','))) {
      k = 2;
    }
  }
  if (b_finite) {
    ntoread = 1;
  }
  if (success && (k <= 1)) {
    s1[idx - 1] = ' ';
    idx++;
    k = 1;
    internal::readfloat(s1, &idx, s, &k, true, &isneg, &isfinite2, &scanned2,
                        &foundsign, &success);
    if (isfinite2) {
      ntoread++;
    }
    if (success && (k > 1) && (isimag1 != isneg) && foundsign) {
      success = true;
    } else {
      success = false;
    }
  } else {
    scanned2 = 0.0;
  }
  if (success) {
    s1[idx - 1] = '\x00';
    if (ntoread == 2) {
      ntoread = sscanf(&s1[0], "%lf %lf", &scanned1, &scanned2);
      if (ntoread != 2) {
        scanned1 = rtNaN;
        scanned2 = rtNaN;
      }
    } else if (ntoread == 1) {
      ntoread = sscanf(&s1[0], "%lf", &b_scanned1);
      if (ntoread != 1) {
        b_scanned1 = rtNaN;
      }
      if (b_finite) {
        scanned1 = b_scanned1;
      } else {
        scanned2 = b_scanned1;
      }
    }
    if (isimag1) {
      x.re = scanned2;
      x.im = scanned1;
    } else {
      x.re = scanned1;
      x.im = scanned2;
    }
  }
  return x;
}

//
// Arguments    : const ::coder::array<char, 2U> &s
// Return Type  : creal_T
//
creal_T str2double(const ::coder::array<char, 2U> &s)
{
  array<char, 2U> s1;
  creal_T x;
  double b_scanned1;
  double scanned1;
  double scanned2;
  int idx;
  int k;
  boolean_T a__1;
  boolean_T foundsign;
  boolean_T isfinite1;
  boolean_T isfinite2;
  boolean_T isimag1;
  boolean_T success;
  x.re = rtNaN;
  x.im = 0.0;
  if (s.size(1) >= 1) {
    int ntoread;
    boolean_T exitg1;
    ntoread = 0;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k <= s.size(1))) {
      char c;
      c = s[k - 1];
      if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00')) {
        k++;
      } else {
        exitg1 = true;
      }
    }
    s1.set_size(1, s.size(1) + 2);
    idx = s.size(1) + 2;
    for (int i{0}; i < idx; i++) {
      s1[i] = '\x00';
    }
    idx = 1;
    internal::b_readfloat(s1, &idx, s, &k, s.size(1), true, &isimag1,
                          &isfinite1, &scanned1, &a__1, &success);
    if (isfinite1) {
      ntoread = 1;
    }
    if (success && (k <= s.size(1))) {
      s1[idx - 1] = ' ';
      idx++;
      internal::b_readfloat(s1, &idx, s, &k, s.size(1), true, &a__1, &isfinite2,
                            &scanned2, &foundsign, &success);
      if (isfinite2) {
        ntoread++;
      }
      if (success && (k > s.size(1)) && (isimag1 != a__1) && foundsign) {
        success = true;
      } else {
        success = false;
      }
    } else {
      scanned2 = 0.0;
    }
    if (success) {
      s1[idx - 1] = '\x00';
      if (ntoread == 2) {
        idx = sscanf(&s1[0], "%lf %lf", &scanned1, &scanned2);
        if (idx != 2) {
          scanned1 = rtNaN;
          scanned2 = rtNaN;
        }
      } else if (ntoread == 1) {
        idx = sscanf(&s1[0], "%lf", &b_scanned1);
        if (idx != 1) {
          b_scanned1 = rtNaN;
        }
        if (isfinite1) {
          scanned1 = b_scanned1;
        } else {
          scanned2 = b_scanned1;
        }
      }
      if (isimag1) {
        x.re = scanned2;
        x.im = scanned1;
      } else {
        x.re = scanned1;
        x.im = scanned2;
      }
    }
  }
  return x;
}

} // namespace coder

//
// File trailer for str2double.cpp
//
// [EOF]
//

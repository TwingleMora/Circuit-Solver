//
// File: string1.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

// Include Files
#include "string1.h"
#include "rt_nonfinite.h"
#include "solver1_internal_types.h"
#include "solver1_types.h"
#include <algorithm>
#include <cmath>
#include <stdio.h>

// Function Definitions
//
// Arguments    : const char Value_data[]
//                const int Value_size[2]
// Return Type  : void
//
namespace coder {
void rtString::init(const char Value_data[], const int Value_size[2])
{
  int loop_ub;
  Value.size[0] = 1;
  Value.size[1] = Value_size[1];
  loop_ub = Value_size[1];
  if (0 <= loop_ub - 1) {
    std::copy(&Value_data[0], &Value_data[loop_ub], &Value.data[0]);
  }
}

//
// Arguments    : double val
// Return Type  : void
//
void b_rtString::init(double val)
{
  double obj;
  int resCount;
  char st[24];
  char str_data[23];
  obj = std::round(val);
  if (std::isinf(obj)) {
    resCount = 3;
    str_data[0] = 'I';
    str_data[1] = 'n';
    str_data[2] = 'f';
  } else if (std::isnan(obj)) {
    resCount = 3;
    str_data[0] = 'N';
    str_data[1] = 'a';
    str_data[2] = 'N';
  } else {
    resCount = sprintf(&st[0], "%.16g", obj);
    if (0 <= resCount - 1) {
      std::copy(&st[0], &st[resCount], &str_data[0]);
    }
  }
  Value.size[0] = 1;
  Value.size[1] = resCount;
  if (0 <= resCount - 1) {
    std::copy(&str_data[0], &str_data[resCount], &Value.data[0]);
  }
}

//
// Arguments    : b_rtString *replaced_str
// Return Type  : void
//
void b_rtString::replace(b_rtString *replaced_str) const
{
  static const char cv1[15]{'-', '0', '.', '0', '0', '0', '0', '0',
                            '0', '0', '0', '0', '0', '9', ' '};
  static const char cv[3]{'-', '0', ' '};
  int i;
  int j;
  int k;
  int nbMatches;
  short matches_data[667];
  nbMatches = -1;
  i = 1;
  while (i <= Value.size[1] - 2) {
    j = 1;
    while ((j <= 3) && (Value.data[(i + j) - 2] == cv[j - 1])) {
      j++;
    }
    if (j > 3) {
      nbMatches++;
      matches_data[nbMatches] = static_cast<short>(i);
      i += 3;
    } else {
      i++;
    }
  }
  replaced_str->Value.size[0] = 1;
  replaced_str->Value.size[1] = Value.size[1] + (nbMatches + 1) * 12;
  k = 0;
  i = 1;
  for (int n{0}; n <= nbMatches; n++) {
    while (i < matches_data[n]) {
      replaced_str->Value.data[k] = Value.data[i - 1];
      k++;
      i++;
    }
    for (j = 0; j < 15; j++) {
      replaced_str->Value.data[k + j] = cv1[j];
    }
    k += 15;
    i += 3;
  }
  while (i <= Value.size[1]) {
    replaced_str->Value.data[k] = Value.data[i - 1];
    k++;
    i++;
  }
}

//
// Arguments    : void
// Return Type  : rtString
//
rtString::rtString()
{
}

//
// Arguments    : void
// Return Type  : void
//
rtString::~rtString()
{
}

} // namespace coder

//
// File trailer for string1.cpp
//
// [EOF]
//

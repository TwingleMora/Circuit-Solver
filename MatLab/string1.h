//
// File: string1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

#ifndef STRING1_H
#define STRING1_H

// Include Files
#include "rtwtypes.h"
#include "solver1_internal_types.h"
#include "solver1_types.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class rtString {
public:
  void init(const char Value_data[], const int Value_size[2]);
  rtString();
  ~rtString();
  emxArray_char_T_1x2000 Value;
};

class b_rtString {
public:
  void replace(b_rtString *replaced_str) const;
  void init(double val);
  emxArray_char_T_1x10004 Value;
};

} // namespace coder

#endif
//
// File trailer for string1.h
//
// [EOF]
//

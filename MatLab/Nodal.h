//
// File: Nodal.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

#ifndef NODAL_H
#define NODAL_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
class b_Nodal;

// Type Definitions
class Nodal {
public:
  static void FindInNodalsIds(const coder::array<b_Nodal, 2U> &Nodals,
                              const b_Nodal *TheNodal,
                              coder::array<double, 2U> &indexInNodals,
                              double *lengthY);
  static void FindInNodalsIds(const coder::array<b_Nodal, 2U> &Nodals,
                              const b_Nodal *TheNodal,
                              coder::array<double, 2U> &indexInNodals);
  static void GetRValue(const b_Nodal *orginal, const b_Nodal *n2,
                        coder::array<double, 2U> &R);
  static void b_FindInNodalsIds(const coder::array<b_Nodal, 2U> &Nodals,
                                const b_Nodal *TheNodal,
                                coder::array<double, 2U> &indexInNodals,
                                double *lengthY);
  static void b_FindInNodalsIds(const coder::array<b_Nodal, 2U> &Nodals,
                                const b_Nodal *TheNodal,
                                coder::array<double, 2U> &indexInNodals);
  double V;
};

class b_Nodal {
public:
  void setConnections(coder::array<b_Nodal, 2U> &nodals,
                      const b_Nodal *n2) const;
  void setConnections(coder::array<b_Nodal, 2U> &nodals, const b_Nodal *n2,
                      double R) const;
  double V;
  double Id;
  coder::array<double, 2U> Nodal_Ids;
};

#endif
//
// File trailer for Nodal.h
//
// [EOF]
//

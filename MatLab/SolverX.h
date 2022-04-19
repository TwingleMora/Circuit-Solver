//
// File: SolverX.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

#ifndef SOLVERX_H
#define SOLVERX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class rtString;

}

// Type Definitions
class SolverX {
public:
  SolverX();
  ~SolverX();
  void solver1(const coder::rtString *strTypeInput,
               coder::array<double, 2U> &arrayOfNodesIds,
               coder::array<double, 2U> &arrayOfPotentialVs, double *succeed);
};

#endif
//
// File trailer for SolverX.h
//
// [EOF]
//

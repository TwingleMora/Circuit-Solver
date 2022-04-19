//
// File: Nodal.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

// Include Files
#include "Nodal.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<b_Nodal, 2U> &Nodals
//                const b_Nodal *TheNodal
//                coder::array<double, 2U> &indexInNodals
//                double *lengthY
// Return Type  : void
//
void Nodal::FindInNodalsIds(const coder::array<b_Nodal, 2U> &Nodals,
                            const b_Nodal *TheNodal,
                            coder::array<double, 2U> &indexInNodals,
                            double *lengthY)
{
  double counter;
  int i;
  indexInNodals.set_size(1, 0);
  counter = 0.0;
  i = TheNodal->Nodal_Ids.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    double obj_Id;
    int Idx;
    int n;
    obj_Id = TheNodal->Nodal_Ids[b_i];
    //  getting the nodal Id for each Connected nodal to the orginal
    //  one(TheNodal)
    Idx = 0;
    if (Nodals.size(1) == 0) {
      n = 0;
    } else {
      n = Nodals.size(1);
    }
    for (int c_i{0}; c_i < n; c_i++) {
      if (Nodals[c_i].Id == obj_Id) {
        Idx = c_i;
      }
    }
    if (!std::isnan(Nodals[Idx].V)) {
      n = indexInNodals.size(1);
      indexInNodals.set_size(indexInNodals.size(0), indexInNodals.size(1) + 1);
      indexInNodals[n] = Idx + 1;
      counter++;
    }
  }
  *lengthY = counter;
}

//
// Arguments    : const coder::array<b_Nodal, 2U> &Nodals
//                const b_Nodal *TheNodal
//                coder::array<double, 2U> &indexInNodals
// Return Type  : void
//
void Nodal::FindInNodalsIds(const coder::array<b_Nodal, 2U> &Nodals,
                            const b_Nodal *TheNodal,
                            coder::array<double, 2U> &indexInNodals)
{
  int i;
  indexInNodals.set_size(1, 0);
  i = TheNodal->Nodal_Ids.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    double obj_Id;
    int Idx;
    int n;
    obj_Id = TheNodal->Nodal_Ids[b_i];
    //  getting the nodal Id for each Connected nodal to the orginal
    //  one(TheNodal)
    Idx = 0;
    if (Nodals.size(1) == 0) {
      n = 0;
    } else {
      n = Nodals.size(1);
    }
    for (int c_i{0}; c_i < n; c_i++) {
      if (Nodals[c_i].Id == obj_Id) {
        Idx = c_i;
      }
    }
    if (!std::isnan(Nodals[Idx].V)) {
      n = indexInNodals.size(1);
      indexInNodals.set_size(indexInNodals.size(0), indexInNodals.size(1) + 1);
      indexInNodals[n] = Idx + 1;
    }
  }
}

//
// R =0; %in case u choosed n2 the same as orginal
//
// Arguments    : const b_Nodal *orginal
//                const b_Nodal *n2
//                coder::array<double, 2U> &R
// Return Type  : void
//
void Nodal::GetRValue(const b_Nodal *orginal, const b_Nodal *n2,
                      coder::array<double, 2U> &R)
{
  double counter;
  int b_i;
  int i;
  counter = 0.0;
  i = orginal->Nodal_Ids.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    // number of row
    if (orginal->Nodal_Ids[b_i] == n2->Id) {
      // Lw Fyh Connection Mbynhm 5sh
      counter++;
    }
  }
  b_i = static_cast<int>(counter);
  R.set_size(1, b_i);
  for (i = 0; i < b_i; i++) {
    R[i] = 0.0;
  }
  counter = 1.0;
  i = orginal->Nodal_Ids.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    // number of row
    if (orginal->Nodal_Ids[b_i] == n2->Id) {
      // Lw Fyh Connection Mbynhm 5sh
      R[static_cast<int>(counter) - 1] =
          orginal->Nodal_Ids[b_i + orginal->Nodal_Ids.size(0)];
      // remember i used union in order to double to value
      counter++;
    }
  }
}

//
// Arguments    : const coder::array<b_Nodal, 2U> &Nodals
//                const b_Nodal *TheNodal
//                coder::array<double, 2U> &indexInNodals
//                double *lengthY
// Return Type  : void
//
void Nodal::b_FindInNodalsIds(const coder::array<b_Nodal, 2U> &Nodals,
                              const b_Nodal *TheNodal,
                              coder::array<double, 2U> &indexInNodals,
                              double *lengthY)
{
  double counter;
  int i;
  indexInNodals.set_size(1, 0);
  counter = 0.0;
  i = TheNodal->Nodal_Ids.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    double obj_Id;
    int Idx;
    int n;
    obj_Id = TheNodal->Nodal_Ids[b_i];
    //  getting the nodal Id for each Connected nodal to the orginal
    //  one(TheNodal)
    Idx = 0;
    if (Nodals.size(1) == 0) {
      n = 0;
    } else {
      n = Nodals.size(1);
    }
    for (int c_i{0}; c_i < n; c_i++) {
      if (Nodals[c_i].Id == obj_Id) {
        Idx = c_i;
      }
    }
    if (std::isnan(Nodals[Idx].V)) {
      n = indexInNodals.size(1);
      indexInNodals.set_size(indexInNodals.size(0), indexInNodals.size(1) + 1);
      indexInNodals[n] = Idx + 1;
      counter++;
    }
  }
  *lengthY = counter;
}

//
// Arguments    : const coder::array<b_Nodal, 2U> &Nodals
//                const b_Nodal *TheNodal
//                coder::array<double, 2U> &indexInNodals
// Return Type  : void
//
void Nodal::b_FindInNodalsIds(const coder::array<b_Nodal, 2U> &Nodals,
                              const b_Nodal *TheNodal,
                              coder::array<double, 2U> &indexInNodals)
{
  int i;
  indexInNodals.set_size(1, 0);
  i = TheNodal->Nodal_Ids.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    double obj_Id;
    int Idx;
    int n;
    obj_Id = TheNodal->Nodal_Ids[b_i];
    //  getting the nodal Id for each Connected nodal to the orginal
    //  one(TheNodal)
    Idx = 0;
    if (Nodals.size(1) == 0) {
      n = 0;
    } else {
      n = Nodals.size(1);
    }
    for (int c_i{0}; c_i < n; c_i++) {
      if (Nodals[c_i].Id == obj_Id) {
        Idx = c_i;
      }
    }
    if (std::isnan(Nodals[Idx].V)) {
      n = indexInNodals.size(1);
      indexInNodals.set_size(indexInNodals.size(0), indexInNodals.size(1) + 1);
      indexInNodals[n] = Idx + 1;
    }
  }
}

//
// determine if the nodel out of the postive or negative 1 => rise the voltage /
// -1 drop the voltage
//
// Arguments    : coder::array<b_Nodal, 2U> &nodals
//                const b_Nodal *n2
//                double R
// Return Type  : void
//
void b_Nodal::setConnections(coder::array<b_Nodal, 2U> &nodals,
                             const b_Nodal *n2, double R) const
{
  coder::array<int, 1U> indexesOfNotFilledRowsById;
  coder::array<boolean_T, 1U> b_nodals;
  int i;
  int indx1;
  int indx2;
  int u1;
  //         %% dddddddddddddddddddddddddddddddd
  indx1 = 0;
  u1 = nodals.size(1);
  if (1 >= u1) {
    u1 = 1;
  }
  if (nodals.size(1) == 0) {
    u1 = 0;
  }
  for (i = 0; i < u1; i++) {
    if (nodals[i].Id == Id) {
      indx1 = i;
    }
  }
  //  first terminal
  indx2 = 0;
  u1 = nodals.size(1);
  if (1 >= u1) {
    u1 = 1;
  }
  if (nodals.size(1) == 0) {
    u1 = 0;
  }
  for (i = 0; i < u1; i++) {
    if (nodals[i].Id == n2->Id) {
      indx2 = i;
    }
  }
  //  second terminal which can be pos or neg
  if (std::isnan(R) && (!std::isnan(nodals[indx1].V))) {
    nodals[indx2].V = nodals[indx1].V + nodals[indx2].V;
  }
  //                  finalProduct = [];
  //         rows = zeros(1,2);
  //         rows2 = zeros(1,2);
  //         if length(nodals(indx1).Nodal_Ids)~= 0
  //         rows =
  //         zeros(length(nodals(indx1).Nodal_Ids),length(nodals(indx1).Nodal_Ids));
  //         else
  //           rows = [];
  //         end
  //         rows =  nodals(indx1).Nodal_Ids;
  //         rows2 = [ n2.Id R_Value];
  //         rows = [rows;rows2];
  // nodals(indx1).Nodal_Ids = rows;
  // nodals(indx1).Nodal_Ids=  [ nodals(indx1).Nodal_Ids;row];
  u1 = nodals[indx1].Nodal_Ids.size(0);
  b_nodals.set_size(u1);
  for (i = 0; i < u1; i++) {
    b_nodals[i] = (nodals[indx1].Nodal_Ids[i] == 0.0);
  }
  coder::eml_find(b_nodals, indexesOfNotFilledRowsById);
  nodals[indx1].Nodal_Ids[indexesOfNotFilledRowsById[0] - 1] = n2->Id;
  nodals[indx1].Nodal_Ids[(indexesOfNotFilledRowsById[0] +
                           nodals[indx1].Nodal_Ids.size(0)) -
                          1] = R;
  //  nodals(indx1) =  AddConnection(nodals(indx1),n2.Id ,R_Value);
  //      %% xxxxxxxxxxxxxxxxxxxxxxxx
  //              if length(nodals(indx2).Nodal_Ids)~= 0
  //         rows =
  //         zeros(length(nodals(indx2).Nodal_Ids),length(nodals(indx2).Nodal_Ids));
  //         else
  //           rows = [];
  //         end
  //         rows =  nodals(indx2).Nodal_Ids;
  //         rows2 = [ n1.Id R_Value];
  //         rows = [rows;rows2];
  // nodals(indx2).Nodal_Ids = rows;
  // nodals(indx2).Nodal_Ids = [ nodals(indx2).Nodal_Ids;row];
  u1 = nodals[indx2].Nodal_Ids.size(0);
  b_nodals.set_size(u1);
  for (i = 0; i < u1; i++) {
    b_nodals[i] = (nodals[indx2].Nodal_Ids[i] == 0.0);
  }
  coder::eml_find(b_nodals, indexesOfNotFilledRowsById);
  nodals[indx2].Nodal_Ids[indexesOfNotFilledRowsById[0] - 1] = Id;
  nodals[indx2].Nodal_Ids[(indexesOfNotFilledRowsById[0] +
                           nodals[indx2].Nodal_Ids.size(0)) -
                          1] = R;
}

//
// determine if the nodel out of the postive or negative 1 => rise the voltage /
// -1 drop the voltage
//
// Arguments    : coder::array<b_Nodal, 2U> &nodals
//                const b_Nodal *n2
// Return Type  : void
//
void b_Nodal::setConnections(coder::array<b_Nodal, 2U> &nodals,
                             const b_Nodal *n2) const
{
  coder::array<int, 1U> indexesOfNotFilledRowsById;
  coder::array<boolean_T, 1U> b_nodals;
  int i;
  int indx1;
  int indx2;
  int u1;
  //         %% dddddddddddddddddddddddddddddddd
  indx1 = 0;
  u1 = nodals.size(1);
  if (1 >= u1) {
    u1 = 1;
  }
  if (nodals.size(1) == 0) {
    u1 = 0;
  }
  for (i = 0; i < u1; i++) {
    if (nodals[i].Id == Id) {
      indx1 = i;
    }
  }
  //  first terminal
  indx2 = 0;
  u1 = nodals.size(1);
  if (1 >= u1) {
    u1 = 1;
  }
  if (nodals.size(1) == 0) {
    u1 = 0;
  }
  for (i = 0; i < u1; i++) {
    if (nodals[i].Id == n2->Id) {
      indx2 = i;
    }
  }
  //  second terminal which can be pos or neg
  if (!std::isnan(nodals[indx1].V)) {
    nodals[indx2].V = nodals[indx1].V + nodals[indx2].V;
  }
  //                  finalProduct = [];
  //         rows = zeros(1,2);
  //         rows2 = zeros(1,2);
  //         if length(nodals(indx1).Nodal_Ids)~= 0
  //         rows =
  //         zeros(length(nodals(indx1).Nodal_Ids),length(nodals(indx1).Nodal_Ids));
  //         else
  //           rows = [];
  //         end
  //         rows =  nodals(indx1).Nodal_Ids;
  //         rows2 = [ n2.Id R_Value];
  //         rows = [rows;rows2];
  // nodals(indx1).Nodal_Ids = rows;
  // nodals(indx1).Nodal_Ids=  [ nodals(indx1).Nodal_Ids;row];
  u1 = nodals[indx1].Nodal_Ids.size(0);
  b_nodals.set_size(u1);
  for (i = 0; i < u1; i++) {
    b_nodals[i] = (nodals[indx1].Nodal_Ids[i] == 0.0);
  }
  coder::eml_find(b_nodals, indexesOfNotFilledRowsById);
  nodals[indx1].Nodal_Ids[indexesOfNotFilledRowsById[0] - 1] = n2->Id;
  nodals[indx1].Nodal_Ids[(indexesOfNotFilledRowsById[0] +
                           nodals[indx1].Nodal_Ids.size(0)) -
                          1] = rtNaN;
  //  nodals(indx1) =  AddConnection(nodals(indx1),n2.Id ,R_Value);
  //      %% xxxxxxxxxxxxxxxxxxxxxxxx
  //              if length(nodals(indx2).Nodal_Ids)~= 0
  //         rows =
  //         zeros(length(nodals(indx2).Nodal_Ids),length(nodals(indx2).Nodal_Ids));
  //         else
  //           rows = [];
  //         end
  //         rows =  nodals(indx2).Nodal_Ids;
  //         rows2 = [ n1.Id R_Value];
  //         rows = [rows;rows2];
  // nodals(indx2).Nodal_Ids = rows;
  // nodals(indx2).Nodal_Ids = [ nodals(indx2).Nodal_Ids;row];
  u1 = nodals[indx2].Nodal_Ids.size(0);
  b_nodals.set_size(u1);
  for (i = 0; i < u1; i++) {
    b_nodals[i] = (nodals[indx2].Nodal_Ids[i] == 0.0);
  }
  coder::eml_find(b_nodals, indexesOfNotFilledRowsById);
  nodals[indx2].Nodal_Ids[indexesOfNotFilledRowsById[0] - 1] = Id;
  nodals[indx2].Nodal_Ids[(indexesOfNotFilledRowsById[0] +
                           nodals[indx2].Nodal_Ids.size(0)) -
                          1] = rtNaN;
}

//
// File trailer for Nodal.cpp
//
// [EOF]
//

//
// File: SolverX.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Mar-2022 23:59:02
//

// Include Files
#include "SolverX.h"
#include "Nodal.h"
#include "eml_setop.h"
#include "find.h"
#include "mpower.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "solver1_data.h"
#include "solver1_internal_types.h"
#include "solver1_types.h"
#include "sort.h"
#include "str2double.h"
#include "string1.h"
#include "unique.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <stdio.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
SolverX::SolverX()
{
}

//
// Arguments    : void
// Return Type  : void
//
SolverX::~SolverX()
{
  // (no terminate code required)
}

//
// Input System
//
// Arguments    : const coder::rtString *strTypeInput
//                coder::array<double, 2U> &arrayOfNodesIds
//                coder::array<double, 2U> &arrayOfPotentialVs
//                double *succeed
// Return Type  : void
//
void SolverX::solver1(const coder::rtString *strTypeInput,
                      coder::array<double, 2U> &arrayOfNodesIds,
                      coder::array<double, 2U> &arrayOfPotentialVs,
                      double *succeed)
{
  Nodal N;
  b_Nodal NNN;
  coder::b_rtString b_str;
  coder::b_rtString str;
  coder::array<Nodal, 2U> nodals2;
  coder::array<b_Nodal, 2U> nodals;
  coder::array<b_Nodal, 2U> r8;
  coder::array<double, 2U> RowsToBeSum;
  coder::array<double, 2U> SupportiveEquation;
  coder::array<double, 2U> UnknownNodalsIndexes;
  coder::array<double, 2U> alternativeSolution;
  coder::array<double, 2U> b_coffecients;
  coder::array<double, 2U> b_nanV_NodalsIndexes;
  coder::array<double, 2U> b_solution;
  coder::array<double, 2U> c_nanV_NodalsIndexes;
  coder::array<double, 2U> coffecients;
  coder::array<double, 2U> knownV_NodalsIndexes;
  coder::array<double, 2U> mapOfConnections;
  coder::array<double, 2U> nanV_NodalsIndexes;
  coder::array<double, 2U> results;
  coder::array<double, 2U> results_data;
  coder::array<double, 1U> SupportiveResults;
  coder::array<double, 1U> solution;
  coder::array<int, 1U> ia;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r1;
  coder::array<int, 1U> r10;
  coder::array<int, 1U> r11;
  coder::array<int, 1U> r12;
  coder::array<int, 1U> r2;
  coder::array<int, 1U> r3;
  coder::array<int, 1U> r4;
  coder::array<int, 1U> r5;
  coder::array<int, 1U> r6;
  coder::array<int, 1U> r7;
  coder::array<int, 1U> r9;
  coder::array<char, 2U> str_from2;
  coder::array<char, 2U> str_to2;
  coder::array<char, 2U> str_value2;
  coder::array<boolean_T, 1U> b_mapOfConnections;
  double b_results_data[2];
  double tRow_data[2];
  double counter3;
  double max_s_matrix_cols;
  double max_s_matrix_rows;
  double numberOfNodes;
  int StrCounter2;
  int b_succeed;
  int width;
  char varargin_1_data[24];
  char type2;
  boolean_T from2;
  boolean_T readyForValue2;
  boolean_T to2;
  boolean_T typeB2;
  //  Example : 1,v,2-10 2,r,3-10 3,r,4-5 4,v,5-1 5,r,1-5 ;
  //  from,type,to-value(space);
  // InputStr=' ';
  //  while InputStr ~= ';'
  //  InputStr = input('Enter Ur Command : ','s');
  //  end
  //
  b_succeed = 0;
  arrayOfNodesIds.set_size(0, 0);
  arrayOfPotentialVs.set_size(0, 0);
  // lastNodalIndex=1;
  //
  //  if(type=='r')
  //      if str_value ==0
  //
  //      end
  //  end
  //  AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
  // nodals2 = {Nodal(0,1)};
  //  Map Of Connection (nodel -- number of connections)
  // mapOfConnections = [];
  // length_of_nodes_array =0;
  from2 = false;
  //  false not written yet / true : done
  to2 = false;
  typeB2 = false;
  readyForValue2 = false;
  StrCounter2 = 0;
  str_from2.set_size(1, 0);
  str_to2.set_size(1, 0);
  str_value2.set_size(1, 0);
  type2 = ' ';
  counter3 = 1.0;
  max_s_matrix_rows = 0.0;
  max_s_matrix_cols = 0.0;
  // Map Of Connection Navigator
  numberOfNodes = 0.0;
  while (strTypeInput->Value.data[StrCounter2] != ';') {
    if (bv[static_cast<unsigned char>(strTypeInput->Value.data[StrCounter2]) &
           127]) {
      numberOfNodes++;
    }
    StrCounter2++;
  }
  if (!(numberOfNodes == 0.0)) {
    creal_T dc;
    creal_T dc1;
    creal_T x;
    double FirstMatrixIndex2=0;
    double d;
    double nodals2Iterator;
    double nodalsIterator;
    int StrCounter;
    unsigned int SuperNodelCounter;
    int b_i;
    unsigned int counter;
    int i;
    int i1;
    int i2;
    int loop_ub;
    int n;
    int npages;
    int trueCount;
    boolean_T exitg1;
    //   %% zz=@(~)numberOfNodes; i wanted to use it as constant but it wasnt
    //   recognized by matlab as a constant
    i = static_cast<int>(numberOfNodes);
    mapOfConnections.set_size(i, 2);
    loop_ub = static_cast<int>(numberOfNodes) << 1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      mapOfConnections[i1] = 0.0;
    }
    // UNTITLED Construct an instance of this class
    //    Detailed explanation goes here
    N.V = 0.0;
    //  nodals2 = repmat(N,[1,numberOfNodes]);
    //  [nodals2{1:end}]=deal(N);
    nodals2.set_size(1, i);
    for (width = 0; width < i; width++) {
      nodals2[width] = N;
    }
    //  else
    //      %%  mapOfConnections = zeros(1,2);
    //  end
    StrCounter2 = 0;
    nodals2Iterator = 1.0;
    FirstMatrixIndex2 = 0.0;
    //  AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    while (strTypeInput->Value.data[StrCounter2] != ';') {
      x = coder::str2double(strTypeInput->Value.data[StrCounter2]);
      if (((!std::isnan(x.re)) && (!std::isnan(x.im))) ||
          (strTypeInput->Value.data[StrCounter2] == '.')) {
        if (!from2) {
          i1 = str_from2.size(1);
          str_from2.set_size(str_from2.size(0), str_from2.size(1) + 1);
          str_from2[i1] = strTypeInput->Value.data[StrCounter2];
          //  str_from3= str_from3(1,1);
        } else if (!to2) {
          i1 = str_to2.size(1);
          str_to2.set_size(str_to2.size(0), str_to2.size(1) + 1);
          str_to2[i1] = strTypeInput->Value.data[StrCounter2];
        }
        if (readyForValue2) {
          i1 = str_value2.size(1);
          str_value2.set_size(str_value2.size(0), str_value2.size(1) + 1);
          str_value2[i1] = strTypeInput->Value.data[StrCounter2];
        }
      } else if (strTypeInput->Value.data[StrCounter2] == ',') {
        if (!from2) {
          from2 = true;
          //  elseif to == false
          //      to = ~to;
        }
      } else if (strTypeInput->Value.data[StrCounter2] == '-') {
        readyForValue2 = true;
        to2 = true;
      } else if (bv[static_cast<unsigned char>(
                        strTypeInput->Value.data[StrCounter2]) &
                    127]) {
        x = coder::str2double(str_from2);
        numberOfNodes = x.re;
        dc = coder::str2double(str_to2);
        nodalsIterator = dc.re;
        dc1 = coder::str2double(str_value2);
        //  type2
        if (type2 == 'r') {
          //  if(Tvalue2 == 0)
          //      if(Tfrom2~=Tto2)
          //
          //  lowest_node = min(Tfrom2,Tto2);
          //  heighest_node=max(Tfrom2,Tto2);
          //
          //  string_input = string(InputStr2);
          //  % temp = [","+string(lowest_node) ,string(lowest_node)+","];
          //  % temp2 = [","+string(heighest_node) ,string(heighest_node)+","];
          //  % string_input = replace(string_input,temp2(1),temp(1));
          //  % string_input = replace(string_input,temp2(2),temp(2));
          //  % InputStr2 = char(string_input);
          //  % InputStr2 = reformat(InputStr2,heighest_node,lowest_node);
          //  temp = [","+string(lowest_node) ,string(lowest_node)+","];
          //  temp2 = [","+string(heighest_node) ,string(heighest_node)+","];
          //  string_input = replace(string_input,temp2(1),temp(1));
          //  InputStr2 = char(string_input);
          //  %%StrCounter2=0;
          //  length_of_nodes_array=0;
          //  add = false;
          //      end
          //  end
          if (dc.re > nodals2Iterator) {
            //          if (Tto-length(nodals))>1
            //          nodals(length(nodals)+1:Tto-1)=Nodal(nan,nan);
            //          end
            // UNTITLED Construct an instance of this class
            //    Detailed explanation goes here
            nodals2[static_cast<int>(dc.re) - 1].V = rtNaN;
            // nan y3ny m3rfsh el V el 3la el Nodel bkam
            nodals2Iterator++;
          } else {
            //          if isnan(nodals{Tto}.Id)
            //               nodals{Tto}=Nodal(nan,Tto);%%nan y3ny m3rfsh el V
            //               el 3la el Nodel bkam
            //          end
            //         %% Nothing I Think..
          }
          if (x.re != dc.re) {
            //    %% nodals2 =
            //    setConnections(nodals2,nodals2(Tfrom2),nodals2(Tto2),Tvalue2);
            //    %% FirRRRRRRRRRst  RRRrRRR
            loop_ub = mapOfConnections.size(0);
            b_mapOfConnections.set_size(mapOfConnections.size(0));
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_mapOfConnections[i1] = (mapOfConnections[i1] != 0.0);
            }
            npages = b_mapOfConnections.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                trueCount++;
              }
            }
            r5.set_size(trueCount);
            width = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                r5[width] = b_i + 1;
                width++;
              }
            }
            if (x.re > r5.size(0)) {
              //  %% indexx2_ = find(mapOfConnections(:,1)==0);
              width = 0;
              StrCounter = 0;
              exitg1 = false;
              while ((!exitg1) &&
                     (StrCounter <= mapOfConnections.size(0) - 1)) {
                if (mapOfConnections[StrCounter] == 0.0) {
                  width = StrCounter;
                  exitg1 = true;
                } else {
                  StrCounter++;
                }
              }
              mapOfConnections[width] = x.re;
              mapOfConnections[width + mapOfConnections.size(0)] = 1.0;
            } else {
              loop_ub = mapOfConnections.size(0);
              b_mapOfConnections.set_size(mapOfConnections.size(0));
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_mapOfConnections[i1] =
                    (mapOfConnections[i1] == numberOfNodes);
              }
              coder::eml_find(b_mapOfConnections, r3);
              solution.set_size(r3.size(0));
              loop_ub = r3.size(0);
              for (i1 = 0; i1 < loop_ub; i1++) {
                solution[i1] = r3[i1];
              }
              mapOfConnections[(static_cast<int>(solution[0]) +
                                mapOfConnections.size(0)) -
                               1] =
                  mapOfConnections[(static_cast<int>(solution[0]) +
                                    mapOfConnections.size(0)) -
                                   1] +
                  1.0;
            }
            loop_ub = mapOfConnections.size(0);
            b_mapOfConnections.set_size(mapOfConnections.size(0));
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_mapOfConnections[i1] = (mapOfConnections[i1] != 0.0);
            }
            npages = b_mapOfConnections.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                trueCount++;
              }
            }
            r9.set_size(trueCount);
            width = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                r9[width] = b_i + 1;
                width++;
              }
            }
            if (dc.re > r9.size(0)) {
              //   %% indexx2_ = find(mapOfConnections(:,1)==0);
              width = 0;
              StrCounter = 0;
              exitg1 = false;
              while ((!exitg1) &&
                     (StrCounter <= mapOfConnections.size(0) - 1)) {
                if (mapOfConnections[StrCounter] == 0.0) {
                  width = StrCounter;
                  exitg1 = true;
                } else {
                  StrCounter++;
                }
              }
              mapOfConnections[width] = dc.re;
              mapOfConnections[width + mapOfConnections.size(0)] = 1.0;
            } else {
              //  indexx_(1) = 0;
              //     %% indexx_(1) = find(mapOfConnections(:,1)==Tto2);
              npages = 0;
              StrCounter = 0;
              exitg1 = false;
              while ((!exitg1) &&
                     (StrCounter <= mapOfConnections.size(0) - 1)) {
                if (mapOfConnections[StrCounter] == nodalsIterator) {
                  npages = StrCounter;
                  exitg1 = true;
                } else {
                  StrCounter++;
                }
              }
              mapOfConnections[npages + mapOfConnections.size(0)] =
                  mapOfConnections[npages + mapOfConnections.size(0)] + 1.0;
            }
            //   %% End FirstttRRRRRRRR
          }
        } else if (type2 == 'v') {
          if ((dc.re > nodals2Iterator) &&
              (!std::isnan(nodals2[static_cast<int>(x.re) - 1].V))) {
            nodals2[static_cast<int>(dc.re) - 1].V = dc1.re;
            // UNTITLED Construct an instance of this class
            //    Detailed explanation goes here
            nodals2Iterator++;
            //    %%  nodals2 =
            //    setConnections(nodals2,nodals2(Tfrom2),nodals2(Tto2),nan);
            //  %% First
            loop_ub = mapOfConnections.size(0);
            b_mapOfConnections.set_size(mapOfConnections.size(0));
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_mapOfConnections[i1] = (mapOfConnections[i1] != 0.0);
            }
            npages = b_mapOfConnections.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                trueCount++;
              }
            }
            r1.set_size(trueCount);
            width = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                r1[width] = b_i + 1;
                width++;
              }
            }
            if (x.re > r1.size(0)) {
              loop_ub = mapOfConnections.size(0);
              b_mapOfConnections.set_size(mapOfConnections.size(0));
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_mapOfConnections[i1] = (mapOfConnections[i1] == 0.0);
              }
              coder::eml_find(b_mapOfConnections, r3);
              solution.set_size(r3.size(0));
              loop_ub = r3.size(0);
              for (i1 = 0; i1 < loop_ub; i1++) {
                solution[i1] = r3[i1];
              }
              mapOfConnections[static_cast<int>(solution[0]) - 1] = x.re;
              mapOfConnections[(static_cast<int>(solution[0]) +
                                mapOfConnections.size(0)) -
                               1] = 1.0;
            } else {
              //    %%    indexx_(1) = 0;
              loop_ub = mapOfConnections.size(0);
              b_mapOfConnections.set_size(mapOfConnections.size(0));
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_mapOfConnections[i1] =
                    (mapOfConnections[i1] == numberOfNodes);
              }
              coder::eml_find(b_mapOfConnections, r3);
              solution.set_size(r3.size(0));
              loop_ub = r3.size(0);
              for (i1 = 0; i1 < loop_ub; i1++) {
                solution[i1] = r3[i1];
              }
              mapOfConnections[(static_cast<int>(solution[0]) +
                                mapOfConnections.size(0)) -
                               1] =
                  mapOfConnections[(static_cast<int>(solution[0]) +
                                    mapOfConnections.size(0)) -
                                   1] +
                  1.0;
            }
            loop_ub = mapOfConnections.size(0);
            b_mapOfConnections.set_size(mapOfConnections.size(0));
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_mapOfConnections[i1] = (mapOfConnections[i1] != 0.0);
            }
            npages = b_mapOfConnections.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                trueCount++;
              }
            }
            r7.set_size(trueCount);
            width = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                r7[width] = b_i + 1;
                width++;
              }
            }
            if (dc.re > r7.size(0)) {
              //  indexx2_ = find(mapOfConnections(:,1)==0);
              width = 0;
              StrCounter = 0;
              exitg1 = false;
              while ((!exitg1) &&
                     (StrCounter <= mapOfConnections.size(0) - 1)) {
                if (mapOfConnections[StrCounter] == 0.0) {
                  width = StrCounter;
                  exitg1 = true;
                } else {
                  StrCounter++;
                }
              }
              mapOfConnections[width] = dc.re;
              mapOfConnections[width + mapOfConnections.size(0)] = 1.0;
            } else {
              // indexx_(1) = 0;
              //    %% indexx_(1) = find(mapOfConnections(:,1)==Tto2);
              npages = 0;
              StrCounter = 0;
              exitg1 = false;
              while ((!exitg1) &&
                     (StrCounter <= mapOfConnections.size(0) - 1)) {
                if (mapOfConnections[StrCounter] == nodalsIterator) {
                  npages = StrCounter;
                  exitg1 = true;
                } else {
                  StrCounter++;
                }
              }
              mapOfConnections[npages + mapOfConnections.size(0)] =
                  mapOfConnections[npages + mapOfConnections.size(0)] + 1.0;
            }
            //   %% End Firsttt
          } else {
            if (dc.re > nodals2Iterator) {
              nodals2Iterator++;
              // UNTITLED Construct an instance of this class
              //    Detailed explanation goes here
              nodals2[static_cast<int>(dc.re) - 1].V = rtNaN;
            }
            if (std::isnan(nodals2[static_cast<int>(x.re) - 1].V)) {
              // nodals2 =
              // setConnections(nodals2,nodals2(Tfrom2),nodals2(Tto2),nan);%%kda
              // nodals{Tfrom} = nan and nodals{Tto} = nan
              //  Middle
              loop_ub = mapOfConnections.size(0);
              b_mapOfConnections.set_size(mapOfConnections.size(0));
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_mapOfConnections[i1] = (mapOfConnections[i1] != 0.0);
              }
              npages = b_mapOfConnections.size(0) - 1;
              trueCount = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  trueCount++;
                }
              }
              r.set_size(trueCount);
              width = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  r[width] = b_i + 1;
                  width++;
                }
              }
              if (x.re > r.size(0)) {
                //  %% indexx2_ = find(mapOfConnections(:,1)==0);
                width = 0;
                StrCounter = 0;
                exitg1 = false;
                while ((!exitg1) &&
                       (StrCounter <= mapOfConnections.size(0) - 1)) {
                  if (mapOfConnections[StrCounter] == 0.0) {
                    width = StrCounter;
                    exitg1 = true;
                  } else {
                    StrCounter++;
                  }
                }
                mapOfConnections[width] = x.re;
                mapOfConnections[width + mapOfConnections.size(0)] = 1.0;
              } else {
                //      %%  indexx_(1) = 0;
                loop_ub = mapOfConnections.size(0);
                b_mapOfConnections.set_size(mapOfConnections.size(0));
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_mapOfConnections[i1] =
                      (mapOfConnections[i1] == numberOfNodes);
                }
                coder::eml_find(b_mapOfConnections, r3);
                solution.set_size(r3.size(0));
                loop_ub = r3.size(0);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  solution[i1] = r3[i1];
                }
                mapOfConnections[(static_cast<int>(solution[0]) +
                                  mapOfConnections.size(0)) -
                                 1] =
                    mapOfConnections[(static_cast<int>(solution[0]) +
                                      mapOfConnections.size(0)) -
                                     1] +
                    1.0;
              }
              loop_ub = mapOfConnections.size(0);
              b_mapOfConnections.set_size(mapOfConnections.size(0));
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_mapOfConnections[i1] = (mapOfConnections[i1] != 0.0);
              }
              npages = b_mapOfConnections.size(0) - 1;
              trueCount = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  trueCount++;
                }
              }
              r4.set_size(trueCount);
              width = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  r4[width] = b_i + 1;
                  width++;
                }
              }
              if (dc.re > r4.size(0)) {
                // indexx2_ = find(tempCol==0);
                width = 0;
                StrCounter = 0;
                exitg1 = false;
                while ((!exitg1) &&
                       (StrCounter <= mapOfConnections.size(0) - 1)) {
                  if (mapOfConnections[StrCounter] == 0.0) {
                    width = StrCounter;
                    exitg1 = true;
                  } else {
                    StrCounter++;
                  }
                }
                mapOfConnections[width] = dc.re;
                mapOfConnections[width + mapOfConnections.size(0)] = 1.0;
              } else {
                // indexx_(1) = 0;
                //    %% indexx_(1) = find(mapOfConnections(:,1)==Tto2);
                npages = 0;
                StrCounter = 0;
                exitg1 = false;
                while ((!exitg1) &&
                       (StrCounter <= mapOfConnections.size(0) - 1)) {
                  if (mapOfConnections[StrCounter] == nodalsIterator) {
                    npages = StrCounter;
                    exitg1 = true;
                  } else {
                    StrCounter++;
                  }
                }
                mapOfConnections[npages + mapOfConnections.size(0)] =
                    mapOfConnections[npages + mapOfConnections.size(0)] + 1.0;
              }
              //  End M
              if (!std::isnan(nodals2[static_cast<int>(dc.re) - 1].V)) {
                nodals2[static_cast<int>(x.re) - 1].V =
                    -nodals2[static_cast<int>(dc.re) - 1].V;
              }
            } else if (std::isnan(nodals2[static_cast<int>(dc.re) - 1].V)) {
              // Nodal(Tfrom is not nan)
              //  counter2 = counter2+1;
              nodals2[static_cast<int>(dc.re) - 1].V = dc1.re;
              // nodals2 =
              // setConnections(nodals2,nodals2(Tfrom2),nodals2(Tto2),nan);
              //  Second
              loop_ub = mapOfConnections.size(0);
              b_mapOfConnections.set_size(mapOfConnections.size(0));
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_mapOfConnections[i1] = (mapOfConnections[i1] != 0.0);
              }
              npages = b_mapOfConnections.size(0) - 1;
              trueCount = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  trueCount++;
                }
              }
              r2.set_size(trueCount);
              width = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  r2[width] = b_i + 1;
                  width++;
                }
              }
              if (x.re > r2.size(0)) {
                //   %% indexx2_ = find(mapOfConnections(:,1)==0);
                width = 0;
                StrCounter = 0;
                exitg1 = false;
                while ((!exitg1) &&
                       (StrCounter <= mapOfConnections.size(0) - 1)) {
                  if (mapOfConnections[StrCounter] == 0.0) {
                    width = StrCounter;
                    exitg1 = true;
                  } else {
                    StrCounter++;
                  }
                }
                mapOfConnections[width] = x.re;
                mapOfConnections[width + mapOfConnections.size(0)] = 1.0;
              } else {
                //       %% indexx_(1) = 0;
                //   %%  indexx_(1) = find(mapOfConnections(:,1)==Tfrom2);
                npages = 0;
                StrCounter = 0;
                exitg1 = false;
                while ((!exitg1) &&
                       (StrCounter <= mapOfConnections.size(0) - 1)) {
                  if (mapOfConnections[StrCounter] == numberOfNodes) {
                    npages = StrCounter;
                    exitg1 = true;
                  } else {
                    StrCounter++;
                  }
                }
                mapOfConnections[npages + mapOfConnections.size(0)] =
                    mapOfConnections[npages + mapOfConnections.size(0)] + 1.0;
              }
              loop_ub = mapOfConnections.size(0);
              b_mapOfConnections.set_size(mapOfConnections.size(0));
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_mapOfConnections[i1] = (mapOfConnections[i1] != 0.0);
              }
              npages = b_mapOfConnections.size(0) - 1;
              trueCount = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  trueCount++;
                }
              }
              r6.set_size(trueCount);
              width = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  r6[width] = b_i + 1;
                  width++;
                }
              }
              if (dc.re > r6.size(0)) {
                width = 0;
                StrCounter = 0;
                exitg1 = false;
                while ((!exitg1) &&
                       (StrCounter <= mapOfConnections.size(0) - 1)) {
                  if (mapOfConnections[StrCounter] == 0.0) {
                    width = StrCounter;
                    exitg1 = true;
                  } else {
                    StrCounter++;
                  }
                }
                mapOfConnections[width] = dc.re;
                mapOfConnections[width + mapOfConnections.size(0)] = 1.0;
              } else {
                // indexx_(1) = 0;
                //    %% indexx_(1) = find(mapOfConnections(:,1)==Tto2);
                npages = 0;
                StrCounter = 0;
                exitg1 = false;
                while ((!exitg1) &&
                       (StrCounter <= mapOfConnections.size(0) - 1)) {
                  if (mapOfConnections[StrCounter] == nodalsIterator) {
                    npages = StrCounter;
                    exitg1 = true;
                  } else {
                    StrCounter++;
                  }
                }
                mapOfConnections[npages + mapOfConnections.size(0)] =
                    mapOfConnections[npages + mapOfConnections.size(0)] + 1.0;
              }
              //  End 2
            }
          }
          if (std::isnan(nodals2[static_cast<int>(x.re) - 1].V) &&
              std::isnan(nodals2[static_cast<int>(dc.re) - 1].V)) {
            if ((FirstMatrixIndex2 == 0.0) ||
                (FirstMatrixIndex2 > std::fmin(dc.re, x.re))) {
              FirstMatrixIndex2 = std::fmin(dc.re, x.re);
            }
            //  if(FirstMatrixIndex2 == Tto2)
            if (counter3 > max_s_matrix_rows) {
              max_s_matrix_rows = counter3;
            }
            //         if (Tto2-FirstMatrixIndex2+1)>max_s_matrix_cols
            //          max_s_matrix_cols =  (Tto2-FirstMatrixIndex2+1);
            //         end
            //   elseif FirstMatrixIndex2 == Tfrom2
            if (counter3 > max_s_matrix_rows) {
              max_s_matrix_rows = counter3;
              // support rows
            }
            //         if (Tfrom2-FirstMatrixIndex2+1)>max_s_matrix_cols
            //          max_s_matrix_cols =  (Tto2-FirstMatrixIndex2+1);
            //         end
            //    end
            d = (dc.re - FirstMatrixIndex2) + 1.0;
            if (d > max_s_matrix_cols) {
              max_s_matrix_cols = (dc.re - FirstMatrixIndex2) + 1.0;
            }
            if ((x.re - FirstMatrixIndex2) + 1.0 > max_s_matrix_cols) {
              max_s_matrix_cols = (x.re - FirstMatrixIndex2) + 1.0;;
            }
            //      unknownVoltagePoints = FindInNodals(nodals,nan);
            //      for hh = 1 : length(unknownVoltagePoints)
            //          if FirstMatrixIndex2 ==0
            //       FirstMatrixIndex2 = unknownVoltagePoints(hh);
            //       break;
            counter3++;
          }
        }
        //  if (add==true)
        //      length_of_nodes_array = length_of_nodes_array +1;
        //  end
        str_from2.set_size(1, 0);
        str_to2.set_size(1, 0);
        str_value2.set_size(1, 0);
        from2 = false;
        //  false not written yet / true : done
        to2 = false;
        typeB2 = false;
        type2 = ' ';
        readyForValue2 = false;

        //  type
      } else if (!typeB2) {
        type2 = strTypeInput->Value.data[StrCounter2];
        typeB2 = true;
      }
      StrCounter2++;
    }
    //  BBBBBBBBBBBBBBBBBEEEEEEEEEEEEEEEEBBBBBBBBBBBBBBBBBBBBBBBBBBB
    //  Inizializing The Noes Array
    // nodals(1:length_of_nodes_array) = Nodal(0,1);
    //  Earth Nodal
    //  Momkn 2shyl find 5ales  mapOfConnections((mapOfConnections(:,1)==1),2);
    loop_ub = mapOfConnections.size(0);
    b_mapOfConnections.set_size(mapOfConnections.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_mapOfConnections[i1] = (mapOfConnections[i1] == 1.0);
    }
    npages = b_mapOfConnections.size(0) - 1;
    trueCount = 0;
    for (b_i = 0; b_i <= npages; b_i++) {
      if (b_mapOfConnections[b_i]) {
        trueCount++;
      }
    }
    ia.set_size(trueCount);
    width = 0;
    for (b_i = 0; b_i <= npages; b_i++) {
      if (b_mapOfConnections[b_i]) {
        ia[width] = b_i + 1;
        width++;
      }
    }
    numberOfNodes = mapOfConnections[(ia[0] + mapOfConnections.size(0)) - 1];
    // UNTITLED Construct an instance of this class
    //    Detailed explanation goes here
    NNN.V = 0.0;
    NNN.Nodal_Ids.set_size(static_cast<int>(numberOfNodes), 2);
    loop_ub = static_cast<int>(numberOfNodes) << 1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      NNN.Nodal_Ids[i1] = 0.0;
    }
    NNN.Id = 1.0;
    // nodals = repmat(NNN,[1,numberOfNodes]);
    nodals.set_size(1, i);
    for (width = 0; width < i; width++) {
      nodals[width] = NNN;
    }
    nodalsIterator = 1.0;
    str.Value.size[0] = 1;
    str.Value.size[1] = strTypeInput->Value.size[1];
    loop_ub = strTypeInput->Value.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&strTypeInput->Value.data[0],
                &strTypeInput->Value.data[loop_ub], &str.Value.data[0]);
    }
    str.replace(&b_str);
    //  InputStr = InputStr2
    from2 = false;
    //  false not written yet / true : done
    to2 = false;
    typeB2 = false;
    readyForValue2 = false;
    StrCounter = 0;
    str_from2.set_size(1, 0);
    str_to2.set_size(1, 0);
    str_value2.set_size(1, 0);
    type2 = ' ';
    //
    if ((max_s_matrix_rows != 0.0) && (max_s_matrix_cols != 0.0)) {
      width = static_cast<int>(max_s_matrix_rows);
      SupportiveEquation.set_size(width, static_cast<int>(max_s_matrix_cols));
      loop_ub = static_cast<int>(max_s_matrix_rows) *
                static_cast<int>(max_s_matrix_cols);
      for (i1 = 0; i1 < loop_ub; i1++) {
        SupportiveEquation[i1] = 0.0;
      }
      SupportiveResults.set_size(width);
      for (i1 = 0; i1 < width; i1++) {
        SupportiveResults[i1] = 0.0;
      }
    } else {
      SupportiveEquation.set_size(0, 0);
      SupportiveResults.set_size(0);
    }
    FirstMatrixIndex2 = 0.0;
    numberOfNodes = 1.0;
    while (b_str.Value.data[StrCounter] != ';') {
      x = coder::str2double(b_str.Value.data[StrCounter]);
      if (((!std::isnan(x.re)) && (!std::isnan(x.im))) ||
          (b_str.Value.data[StrCounter] == '.')) {
        if (!from2) {
          i1 = str_from2.size(1);
          str_from2.set_size(str_from2.size(0), str_from2.size(1) + 1);
          str_from2[i1] = b_str.Value.data[StrCounter];
        } else if (!to2) {
          i1 = str_to2.size(1);
          str_to2.set_size(str_to2.size(0), str_to2.size(1) + 1);
          str_to2[i1] = b_str.Value.data[StrCounter];
        }
        if (readyForValue2) {
          i1 = str_value2.size(1);
          str_value2.set_size(str_value2.size(0), str_value2.size(1) + 1);
          str_value2[i1] = b_str.Value.data[StrCounter];
        }
      } else if (b_str.Value.data[StrCounter] == ',') {
        if (!from2) {
          from2 = true;
          //  elseif to == false
          //      to = ~to;
        }
      } else if (b_str.Value.data[StrCounter] == '-') {
        readyForValue2 = true;
        to2 = true;
      } else if (bv[static_cast<unsigned char>(b_str.Value.data[StrCounter]) &
                    127]) {
        x = coder::str2double(str_from2);
        dc = coder::str2double(str_to2);
        nodals2Iterator = dc.re;
        dc1 = coder::str2double(str_value2);
        // CoffIndex2 =0;
        if (type2 == 'v') {
          if ((dc.re > nodalsIterator) &&
              (!std::isnan(nodals[static_cast<int>(x.re) - 1].V))) {
            loop_ub = mapOfConnections.size(0);
            b_mapOfConnections.set_size(mapOfConnections.size(0));
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_mapOfConnections[i1] =
                  (mapOfConnections[i1] == nodals2Iterator);
            }
            npages = b_mapOfConnections.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                trueCount++;
              }
            }
            r10.set_size(trueCount);
            width = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                r10[width] = b_i + 1;
                width++;
              }
            }
            nodals[static_cast<int>(dc.re) - 1].V = dc1.re;
            // UNTITLED Construct an instance of this class
            //    Detailed explanation goes here
            i1 = static_cast<int>(
                mapOfConnections[(r10[0] + mapOfConnections.size(0)) - 1]);
            nodals[static_cast<int>(dc.re) - 1].Nodal_Ids.set_size(i1, 2);
            loop_ub = i1 << 1;
            for (i1 = 0; i1 < loop_ub; i1++) {
              nodals[static_cast<int>(nodals2Iterator) - 1].Nodal_Ids[i1] = 0.0;
            }
            nodals[static_cast<int>(dc.re) - 1].Id = dc.re;
            r8.set_size(1, nodals.size(1));
            loop_ub = nodals.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r8[i1] = nodals[i1];
            }
            nodals[static_cast<int>(x.re) - 1].setConnections(
                r8, &nodals[static_cast<int>(dc.re) - 1]);
            nodals.set_size(1, r8.size(1));
            loop_ub = r8.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              nodals[i1] = r8[i1];
            }
            nodalsIterator++;
          } else {
            if (dc.re > nodalsIterator) {
              loop_ub = mapOfConnections.size(0);
              b_mapOfConnections.set_size(mapOfConnections.size(0));
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_mapOfConnections[i1] =
                    (mapOfConnections[i1] == nodals2Iterator);
              }
              npages = b_mapOfConnections.size(0) - 1;
              trueCount = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  trueCount++;
                }
              }
              r11.set_size(trueCount);
              width = 0;
              for (b_i = 0; b_i <= npages; b_i++) {
                if (b_mapOfConnections[b_i]) {
                  r11[width] = b_i + 1;
                  width++;
                }
              }
              // UNTITLED Construct an instance of this class
              //    Detailed explanation goes here
              nodals[static_cast<int>(dc.re) - 1].V = rtNaN;
              i1 = static_cast<int>(
                  mapOfConnections[(r11[0] + mapOfConnections.size(0)) - 1]);
              nodals[static_cast<int>(dc.re) - 1].Nodal_Ids.set_size(i1, 2);
              loop_ub = i1 << 1;
              for (i1 = 0; i1 < loop_ub; i1++) {
                nodals[static_cast<int>(nodals2Iterator) - 1].Nodal_Ids[i1] =
                    0.0;
              }
              nodals[static_cast<int>(dc.re) - 1].Id = dc.re;
              nodalsIterator++;
            }
            if (std::isnan(nodals[static_cast<int>(x.re) - 1].V)) {
              r8.set_size(1, nodals.size(1));
              loop_ub = nodals.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                r8[i1] = nodals[i1];
              }
              nodals[static_cast<int>(x.re) - 1].setConnections(
                  r8, &nodals[static_cast<int>(dc.re) - 1]);
              nodals.set_size(1, r8.size(1));
              loop_ub = r8.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                nodals[i1] = r8[i1];
              }
              // kda nodals{Tfrom} = nan and nodals{Tto} = nan
             /* if (FirstMatrixIndex2 == 0.0) {
                FirstMatrixIndex2 = x.re;
              }*/
              if (!std::isnan(nodals[static_cast<int>(dc.re) - 1].V)) {
                // CoffIndex2 = Tfrom-FirstMatrixIndex2+1;
                nodals[static_cast<int>(x.re) - 1].V =
                    nodals[static_cast<int>(dc.re) - 1].V-dc1.re;
                //   SupportiveEquation(counter2,CoffIndex2)= -1;
                // SupportiveResults(counter2,1)= Tvalue-nodals{Tto}.V;
                numberOfNodes++;
              }
            } else if (std::isnan(nodals[static_cast<int>(dc.re) - 1].V)) {
              // Nodal(Tfrom is not nan)
              //       if FirstMatrixIndex2 ==0||Tto<FirstMatrixIndex2
              //           FirstMatrixIndex2 = Tto;
              //       end
              //   CoffIndex2 = Tto-FirstMatrixIndex2+1;
              //
              //         SupportiveEquation(counter2,CoffIndex2)= 1; %Vfinal -
              //         Vini = TValue
              //
              //  SupportiveResults(counter2,1)= Tvalue+nodals{Tfrom}.V;
              //  counter2 = counter2+1;
              nodals[static_cast<int>(dc.re) - 1].V = dc1.re;//dc1 is Tvalue in matlab script
              r8.set_size(1, nodals.size(1));
              loop_ub = nodals.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                r8[i1] = nodals[i1];
              }
              nodals[static_cast<int>(x.re) - 1].setConnections(
                  r8, &nodals[static_cast<int>(dc.re) - 1]);
              nodals.set_size(1, r8.size(1));
              loop_ub = r8.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                nodals[i1] = r8[i1];
              }
            }
            if ((max_s_matrix_rows != 0.0) && (max_s_matrix_cols != 0.0) &&
                std::isnan(nodals[static_cast<int>(x.re) - 1].V) &&
                std::isnan(nodals[static_cast<int>(dc.re) - 1].V)) {
                if ((FirstMatrixIndex2 == 0.0) ||
                    (FirstMatrixIndex2 > std::fmin(dc.re, x.re))) {
                    FirstMatrixIndex2 = std::fmin(dc.re, x.re);
                }
               /* if (FirstMatrixIndex2 == 0.0) {
                    FirstMatrixIndex2 = x.re;
                    
                }*/
              //    %%  FirstMatrixIndex2 = min(Tto,Tfrom);
              //  if(FirstMatrixIndex2 == Tto)
              //          SupportiveEquation(counter2,Tto-FirstMatrixIndex2+1)=
              //          1;
              //          SupportiveEquation(counter2,Tfrom-FirstMatrixIndex2+1)=
              //          -1; SupportiveResults(counter2,1)= Tvalue;
              //  elseif FirstMatrixIndex2 == Tfrom
              SupportiveEquation[(static_cast<int>(numberOfNodes) +
                                  SupportiveEquation.size(0) *
                                      (static_cast<int>(
                                           (x.re - FirstMatrixIndex2) + 1.0) -
                                       1)) -
                                 1] = -1.0;
              SupportiveEquation[(static_cast<int>(numberOfNodes) +
                                  SupportiveEquation.size(0) *
                                      (static_cast<int>(
                                           (dc.re - FirstMatrixIndex2) + 1.0) -
                                       1)) -
                                 1] = 1.0;
              SupportiveResults[static_cast<int>(numberOfNodes) - 1] = dc1.re;
              //  end
              //      unknownVoltagePoints = FindInNodals(nodals,nan);
              //      for hh = 1 : length(unknownVoltagePoints)
              //          if FirstMatrixIndex2 ==0
              //       FirstMatrixIndex2 = unknownVoltagePoints(hh);
              //       break;
              numberOfNodes++;
            }
          }
        } else if (type2 == 'r') {
          if (dc.re > nodalsIterator) {
            //          if (Tto-length(nodals))>1
            //          nodals(length(nodals)+1:Tto-1)=Nodal(nan,nan);
            //          end
            loop_ub = mapOfConnections.size(0);
            b_mapOfConnections.set_size(mapOfConnections.size(0));
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_mapOfConnections[i1] =
                  (mapOfConnections[i1] == nodals2Iterator);
            }
            npages = b_mapOfConnections.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                trueCount++;
              }
            }
            r12.set_size(trueCount);
            width = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (b_mapOfConnections[b_i]) {
                r12[width] = b_i + 1;
                width++;
              }
            }
            // UNTITLED Construct an instance of this class
            //    Detailed explanation goes here
            nodals[static_cast<int>(dc.re) - 1].V = rtNaN;
            i1 = static_cast<int>(
                mapOfConnections[(r12[0] + mapOfConnections.size(0)) - 1]);
            nodals[static_cast<int>(dc.re) - 1].Nodal_Ids.set_size(i1, 2);
            loop_ub = i1 << 1;
            for (i1 = 0; i1 < loop_ub; i1++) {
              nodals[static_cast<int>(nodals2Iterator) - 1].Nodal_Ids[i1] = 0.0;
            }
            nodals[static_cast<int>(dc.re) - 1].Id = dc.re;
            // nan y3ny m3rfsh el V el 3la el Nodel bkam
            nodalsIterator++;
          } else {
            //          if isnan(nodals{Tto}.Id)
            //               nodals{Tto}=Nodal(nan,Tto);%%nan y3ny m3rfsh el V
            //               el 3la el Nodel bkam
            //          end
            //         %% Nothing I Think..
          }
          if (x.re != dc.re) {
            r8.set_size(1, nodals.size(1));
            loop_ub = nodals.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r8[i1] = nodals[i1];
            }
            nodals[static_cast<int>(x.re) - 1].setConnections(
                r8, &nodals[static_cast<int>(dc.re) - 1], dc1.re);
            nodals.set_size(1, r8.size(1));
            loop_ub = r8.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              nodals[i1] = r8[i1];
            }
          }
        }
        str_from2.set_size(1, 0);
        str_to2.set_size(1, 0);
        str_value2.set_size(1, 0);
        from2 = false;
        //  false not written yet / true : done
        to2 = false;
        type2 = ' ';
        typeB2 = false;
        readyForValue2 = false;

        //  type
      } else if (!typeB2) {
        type2 = b_str.Value.data[StrCounter];
        typeB2 = true;
      }
      StrCounter++;
    }
    //
    //  %% Initialization
    //  for i = 1:6
    //  nodals(i)=Nodal(nan,i);
    //  end
    //  nodals(1).V=0;
    //  nodals(2).V=10;
    //  nodals(3).V=nan;
    //  nodals(4).V = nan;
    //  nodals(5).V = nan;
    //  nodals(6).V = nan;
    //  %% Connections
    //  %addNodal(N1,N2,R)N1(end+1).nodalId = [N2.id,R];N2(end+1).nodalId = [N1
    //  ,R]; %nodals(1).Nodal_Ids =[2,nan];%mbynhm voltage source
    //  %nodals(2).Nodal_Ids = []
    //  nodals = setConnections(nodals,nodals(1),nodals(2));
    //  nodals = setConnections(nodals,nodals(2),nodals(3),10);
    //
    //  nodals=setConnections(nodals,nodals(3),nodals(4),20);
    //  nodals=setConnections(nodals,nodals(3),nodals(1),30);
    //
    //  %nodals=setConnections(nodals,nodals(3),nodals(5),1);
    //
    //  nodals=setConnections(nodals,nodals(4),nodals(5),10);
    //
    //  nodals=setConnections(nodals,nodals(6),nodals(1),3);
    //  nodals=setConnections(nodals,nodals(4),nodals(6),5);Fin
    //  nodals=setConnections(nodals,nodals(5),nodals(6),5);
    //  Calculations
    // m  = [nodals{:}];
    //              arguments
    //                  Nodals (1,1) Cell
    //              V (1,1) double
    //              end
    UnknownNodalsIndexes.set_size(1, 0);
    if (nodals.size(1) == 0) {
      n = 0;
    } else {
      n = nodals.size(1);
    }
    for (b_i = 0; b_i < n; b_i++) {
      if (std::isnan(nodals[b_i].V)) {
        i1 = UnknownNodalsIndexes.size(1);
        UnknownNodalsIndexes.set_size(UnknownNodalsIndexes.size(0),
                                      UnknownNodalsIndexes.size(1) + 1);
        UnknownNodalsIndexes[i1] = static_cast<double>(b_i) + 1.0;
      }
    }
    RowsToBeSum.set_size(0, 0);
    // in case of SuperNodel
    //  3ayz 2gyb 3dd el Unknown V el Connected m3ah
    if (UnknownNodalsIndexes.size(1) > 0) {
      coffecients.set_size(
          static_cast<int>(static_cast<double>(UnknownNodalsIndexes.size(1)) +
                           max_s_matrix_rows),
          UnknownNodalsIndexes.size(1));
      loop_ub =
          static_cast<int>(static_cast<double>(UnknownNodalsIndexes.size(1)) +
                           max_s_matrix_rows) *
          UnknownNodalsIndexes.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        coffecients[i1] = 0.0;
      }
      // max_s_matrix_rows for supportive matrix (super nodal)
      //  In Coffecients Matrix
      results.set_size(UnknownNodalsIndexes.size(1), 1);
      loop_ub = UnknownNodalsIndexes.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        results[i1] = 0.0;
      }
      // Vertival Matrix
      if (max_s_matrix_rows > 0.0) {
        //  RowsToBeSum= zeros(max_s_matrix_rows,NumberOfUnknowns);
        RowsToBeSum.set_size(static_cast<int>(max_s_matrix_rows), 2);
        loop_ub = static_cast<int>(max_s_matrix_rows) << 1;
        for (i1 = 0; i1 < loop_ub; i1++) {
          RowsToBeSum[i1] = 0.0;
        }
      }
    } else {
      coffecients.set_size(0, 0);
      results.set_size(0, 0);
    }
    //  counter = 1;
    counter = 1U;
    //  Find Simple Solutions
    //  ============================================================= for i = 1:
    //  length(nodals)
    //      [~,len] = FindInNodalsIds(nodals,nodals(i),nan);
    //      nanV_NodalsIndexes = zeros(1,len);
    //      nanV_NodalsIndexes = FindInNodalsIds(nodals,nodals(i),nan);
    //      nanV_NodalsIndexes = union(nanV_NodalsIndexes,nanV_NodalsIndexes);
    //      countNan = length(nanV_NodalsIndexes);
    //   for x = 1:countNan
    //
    //   tempR = GetRValue(nodals(i),nodals(nanV_NodalsIndexes(x)));
    //
    //
    //   is_zero = false;
    //   for ih = 1: length(tempR)
    //        if  tempR(ih)==0
    //     is_zero=true;
    //     break;
    //        end
    //   end
    //   if is_zero == true
    //    if isnan(nodals(i).V) %%assuming one of them is known and if they both
    //    r nan it wont harm also
    //
    //     nodals(i).V = nodals(nanV_NodalsIndexes(x)).V;
    //    else
    //          nodals(nanV_NodalsIndexes(x)).V = nodals(i).V;
    //    end
    //   end
    //  end
    //  I Will Assume The Circuit Is Solved Here
    to2 = true;
    //  And If The Opposite Is true It Will Be Turned To False In Next Part Of
    //  the Code End Of The First Solving Process
    //  ==================================================
    if ((SupportiveEquation.size(0) != 0) &&
        (SupportiveEquation.size(1) != 0)) {
      alternativeSolution.set_size(SupportiveEquation.size(0),
                                   SupportiveEquation.size(1));
      loop_ub = SupportiveEquation.size(0) * SupportiveEquation.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        alternativeSolution[i1] = 0.0;
      }
    } else {
      alternativeSolution.set_size(0, 0);
    }
    //  I need it here because i may add equation while Input
    StrCounter = 0;
    StrCounter2 = 0;
    SuperNodelCounter = 1U;
    // in case of 0 ohm wire  across 2 nodels
    if (nodals.size(1) == 0) {
      n = 0;
    } else {
      n = nodals.size(1);
    }
    for (b_i = 0; b_i < n; b_i++) {
      if (std::isnan(nodals[b_i].V) && (UnknownNodalsIndexes.size(1) > 0)) {
        to2 = false;
        if (StrCounter == 0) {
          StrCounter = b_i + 1;
          //  first Index (FMI) I use It to determine the location of
          //  coffecients in their Matrix
          //     %% Introducing : nanV_NodalsIndexes(x)
          //     %% nanV_NodalsIndexes (nanVI) stores the indexes of unkown V
          //     Nodals Ex: it stores [3 5]
          //     %% Ex : x = 1 (nanVI(x) = 3) ------R------ (Current Nodal :
          //     indx = 4) ------- R ------ x = 2 (nanVI(x) = 5)
          //     %%
          //     %%           A                      B                    C
          //     %% i = 3 | (i-FMI+1)           (nanVI(1)-FMI+1)
          //     (nanVI(2)-FMI+1)
          //     %% i = 4 | (nanVI(1)-FMI+1)    (i-FMI+1) (nanVI(2)-FMI+1) The
          //     following two rows're estimated examples
          //     %% i = 5 | (nanVI(1)-FMI+1)    (nanVI(2)-FMI+1)    (i-FMI+1)
        }
        //  %% Linear Equation A*Ni.V + B*Nb.V + C*Nc.V + ... number of unknowns
        //  = D
        //  %% A = Ni.V* ( Segma(R_connected ^-1) )
        //  %% B and C  = -R(Ni,Nb)^-1 and -R(Ni,Nc)^-1
        //  %% D = segma(known nodals * common resistance)
        //  Navigation Matrices
        //  nanV_NodalsIndexes=zeros(2,2);
        //  knownV_NodalsIndexes =zeros(2,2);
        //
        //  len2=0;
        Nodal::b_FindInNodalsIds(nodals, &nodals[b_i], nanV_NodalsIndexes,
                                 &numberOfNodes);
        if (numberOfNodes > 0.0) {
          Nodal::b_FindInNodalsIds(nodals, &nodals[b_i], nanV_NodalsIndexes);
          // around the orginal(current/selected) point nodel(i)
          nanV_NodalsIndexes.set_size(1, static_cast<int>(numberOfNodes));
          coder::unique_vector(nanV_NodalsIndexes, b_nanV_NodalsIndexes);
          // ,nanV_NodalsIndexes(1,1:len2));
        } else {
          b_nanV_NodalsIndexes.set_size(1, 0);
        }
        Nodal::FindInNodalsIds(nodals, &nodals[b_i], nanV_NodalsIndexes,
                               &numberOfNodes);
        if (numberOfNodes > 0.0) {
          Nodal::FindInNodalsIds(nodals, &nodals[b_i], nanV_NodalsIndexes);
          nanV_NodalsIndexes.set_size(1, static_cast<int>(numberOfNodes));
          coder::unique_vector(nanV_NodalsIndexes, knownV_NodalsIndexes);
        } else {
          knownV_NodalsIndexes.set_size(1, 0);
        }
        //  union(knownV_NodalsIndexes(1,1:len2),knownV_NodalsIndexes(1,1:len2));
        //   %% D
        results[static_cast<int>(counter) - 1] = 0.0;
        i1 = knownV_NodalsIndexes.size(1);
        for (trueCount = 0; trueCount < i1; trueCount++) {
          width = static_cast<int>(knownV_NodalsIndexes[trueCount]) - 1;
          Nodal::GetRValue(&nodals[b_i], &nodals[width], nanV_NodalsIndexes);
          i2 = nanV_NodalsIndexes.size(1);
          for (npages = 0; npages < i2; npages++) {
            d = nanV_NodalsIndexes[npages];
            if ((!std::isnan(d)) && (d != 0.0)) {
              results[static_cast<int>(counter) - 1] =
                  results[static_cast<int>(counter) - 1] +
                  nodals[width].V * (1.0 / d);
            }
          }
        }
        //  A
        //  A Could Be B the Next Iteration So..
        numberOfNodes = 0.0;
        c_nanV_NodalsIndexes.set_size(1, b_nanV_NodalsIndexes.size(1) +
                                             knownV_NodalsIndexes.size(1));
        loop_ub = b_nanV_NodalsIndexes.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_nanV_NodalsIndexes[i1] = b_nanV_NodalsIndexes[i1];
        }
        loop_ub = knownV_NodalsIndexes.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_nanV_NodalsIndexes[i1 + b_nanV_NodalsIndexes.size(1)] =
              knownV_NodalsIndexes[i1];
        }
        coder::unique_vector(c_nanV_NodalsIndexes, nanV_NodalsIndexes);
        // union(all_indexes,all_indexes);
        from2 = false;
        i1 = nanV_NodalsIndexes.size(1);
        for (width = 0; width < i1; width++) {
          Nodal::GetRValue(
              &nodals[b_i],
              &nodals[static_cast<int>(nanV_NodalsIndexes[width]) - 1],
              knownV_NodalsIndexes);
          nodalsIterator = 0.0;
          npages = 0;
          exitg1 = false;
          while ((!exitg1) && (npages <= knownV_NodalsIndexes.size(1) - 1)) {
            if ((!std::isnan(knownV_NodalsIndexes[npages])) &&
                (knownV_NodalsIndexes[npages] != 0.0)) {
              nodalsIterator += 1.0 / knownV_NodalsIndexes[npages];
              npages++;
            } else if (knownV_NodalsIndexes[npages] == 0.0) {
              from2 = true;
              exitg1 = true;
            } else {
              npages++;
            }
          }
          if (!from2) {
            numberOfNodes += nodalsIterator;
            //  y3ny lw mkawma wa7da 3 el twazy =0 yb2a kolo = 0
          }
        }
        // l2n el index bybd2 mn 1 hna msh mn zero
        coffecients[(static_cast<int>(counter) +
                     coffecients.size(0) * ((b_i - StrCounter) + 1)) -
                    1] = numberOfNodes;
        //  %% B ,C
        i1 = b_nanV_NodalsIndexes.size(1);
        for (width = 0; width < i1; width++) {
          numberOfNodes = 0.0;
          Nodal::GetRValue(
              &nodals[b_i],
              &nodals[static_cast<int>(b_nanV_NodalsIndexes[width]) - 1],
              nanV_NodalsIndexes);
          if ((RowsToBeSum.size(1) > 1) &&
              (SuperNodelCounter <=
               static_cast<unsigned int>(RowsToBeSum.size(0))) &&
              (RowsToBeSum[(static_cast<int>(SuperNodelCounter) +
                            RowsToBeSum.size(0)) -
                           1] != 0.0)) {
            SuperNodelCounter++;
            StrCounter2 = 0;
          }
          from2 = false;
          i2 = nanV_NodalsIndexes.size(1);
          for (npages = 0; npages < i2; npages++) {
            d = nanV_NodalsIndexes[npages];
            if ((!std::isnan(d)) && (d != 0.0)) {
              //      if tempR(ih)~=0%%2na 2asd 25lyha nested if 3shan mlhash
              //      else case
              numberOfNodes += 1.0 / d;
              //     end
            } else {
              RowsToBeSum[(static_cast<int>(SuperNodelCounter) +
                           RowsToBeSum.size(0) * StrCounter2) -
                          1] = counter;
              // l is the length of the square matrix
              StrCounter2++;
              //       %% 3ayz lw fyh slk R =0 3 el eltwazyy
              //       %% B yb2a = 0
              //       %% hst5dm boolean 2smo is_zero
            }
            if (d == 0.0) {
              //  lw dah hwa el sabab then..
              from2 = true;
            }
          }
          if (!from2) {
            coffecients[(static_cast<int>(counter) +
                         coffecients.size(0) *
                             (static_cast<int>(
                                  (b_nanV_NodalsIndexes[width] -
                                   static_cast<double>(StrCounter)) +
                                  1.0) -
                              1)) -
                        1] = -numberOfNodes;
            //
            //   else
            //       coffecients(counter,coffIndex) =0;
            //       ColumnsToBeSum(WiresCounter,end+1)=coffIndex;
            //
          }
        }
        counter++;
      }
    }
    // Adjust Support Matrix
    // FirstMatrixIndex,FirstMatrixIndex2
    nodals2Iterator = static_cast<double>(StrCounter) - FirstMatrixIndex2;
    counter3 = std::abs(nodals2Iterator);
    if (FirstMatrixIndex2 != 0.0) {
      //  alternativeSolution Is Just Sorted SupportiveEquation To Suit The Sort
      //  System Of Cofficient MATRIX coder.varsize('SupportiveEquation');
      //  SupportiveEquation= adjustMatrixSize(SupportiveEquation,coffecients);
      //  coder.varsize('alternativeSolution')
      //  alternativeSolution =
      //  adjustMatrixSize(alternativeSolution,SupportiveEquation);
      width = coffecients.size(1);
      nodalsIterator = static_cast<double>(UnknownNodalsIndexes.size(1)) + 1.0;
      i1 = SupportiveEquation.size(0);
      for (n = 0; n < i1; n++) {
        i2 = SupportiveEquation.size(1);
        for (npages = 0; npages < i2; npages++) {
          if (!(nodals2Iterator > 0.0)) {
            if (nodals2Iterator < 0.0) {
              numberOfNodes = (static_cast<double>(npages) + 1.0) + counter3;
              d = static_cast<double>(width) * 3.0;
              if (numberOfNodes > d) {
                numberOfNodes -= d;
              } else {
                d = static_cast<double>(width) * 2.0;
                if (numberOfNodes > d) {
                  numberOfNodes -= d;
                } else if (numberOfNodes > width) {
                  numberOfNodes -= static_cast<double>(width);
                }
              }
              coffecients[(static_cast<int>(nodalsIterator) +
                           coffecients.size(0) *
                               (static_cast<int>(numberOfNodes) - 1)) -
                          1] =
                  SupportiveEquation[n + SupportiveEquation.size(0) * npages];
              if (npages + 1 <= alternativeSolution.size(1)) {
                alternativeSolution[n +
                                    alternativeSolution.size(0) *
                                        (static_cast<int>(numberOfNodes) - 1)] =
                    SupportiveEquation[n + SupportiveEquation.size(0) * npages];
              }
            } else {
              // indx = posInMatrix(xx+absDelta,width);
              coffecients[(static_cast<int>(nodalsIterator) +
                           coffecients.size(0) * npages) -
                          1] =
                  SupportiveEquation[n + SupportiveEquation.size(0) * npages];
              if (npages + 1 <= alternativeSolution.size(1)) {
                alternativeSolution[n + alternativeSolution.size(0) * npages] =
                    SupportiveEquation[n + SupportiveEquation.size(0) * npages];
              }
            }
          } else {
            // ...
          }
        }
        nodalsIterator++;
      }
      i1 = SupportiveResults.size(0);
      for (width = 0; width < i1; width++) {
        if ((results.size(0) != 0) && (results.size(1) != 0)) {
          loop_ub = results.size(0);
        } else {
          loop_ub = 0;
        }
        solution.set_size(loop_ub + 1);
        for (i2 = 0; i2 < loop_ub; i2++) {
          solution[i2] = results[i2];
        }
        solution[loop_ub] = SupportiveResults[width];
        results.set_size(solution.size(0), 1);
        loop_ub = solution.size(0);
        for (i2 = 0; i2 < loop_ub; i2++) {
          results[i2] = solution[i2];
        }
      }
    }
    //  Final Stage
    //  Bool Solved
    if (UnknownNodalsIndexes.size(1) > 0) {
      //  Start Of The Ordinary Solution
      if (!to2) {
        d = std::sqrt(static_cast<double>(coffecients.size(0)) *
                      static_cast<double>(coffecients.size(1)));
        if ((d == static_cast<int>(std::round(d))) &&
            ((RowsToBeSum.size(0) == 0) || (RowsToBeSum.size(1) == 0))) {
          coder::mpower(coffecients, SupportiveEquation);
          coder::internal::blas::mtimes(SupportiveEquation, results,
                                        b_solution);
          if ((b_solution.size(0) == 0) || (b_solution.size(1) == 0)) {
            n = 0;
          } else {
            n = b_solution.size(0);
          }
          for (npages = 0; npages < n; npages++) {
            nodals[static_cast<int>(UnknownNodalsIndexes[npages]) - 1].V =
                b_solution[npages];
          }
          //  for cc = nodals
          //   fprintf("node(%d) : %d Volt\n",cc.Id,cc.V);
          //  end
          //  return;
          to2 = true;
        }
      }
      //  End Of Normal Solution
      //  ========================================
      if ((coffecients.size(0) == results.size(0)) && (!to2)) {
        // coffecients = adjustMatrixSize(coffecients,[],3);
        //  Start Of SuperNodel And 0 hom Wires Loop
        if ((RowsToBeSum.size(0) == 0) || (RowsToBeSum.size(1) == 0)) {
          npages = 0;
        } else {
          width = RowsToBeSum.size(0);
          npages = RowsToBeSum.size(1);
          if (width >= npages) {
            npages = width;
          }
        }
        if (npages > 1) {
          //  Row To Be Sum In Coffecients and Results Matrix
          //  %     width = size(coffecients,2);
          //  %     height = size(coffecients,1)+;
          i1 = RowsToBeSum.size(0);
          for (n = 0; n < i1; n++) {
            loop_ub = RowsToBeSum.size(1);
            npages = RowsToBeSum.size(1) - 1;
            trueCount = 0;
            for (b_i = 0; b_i < loop_ub; b_i++) {
              d = RowsToBeSum[n + RowsToBeSum.size(0) * b_i];
              tRow_data[b_i] = d;
              if (d != 0.0) {
                trueCount++;
              }
            }
            width = 0;
            for (b_i = 0; b_i <= npages; b_i++) {
              if (tRow_data[b_i] != 0.0) {
                tRow_data[width] = tRow_data[b_i];
                width++;
              }
            }
            if (trueCount > 1) {
              loop_ub = coffecients.size(1);
              b_coffecients.set_size(trueCount, coffecients.size(1));
              for (i2 = 0; i2 < loop_ub; i2++) {
                for (StrCounter2 = 0; StrCounter2 < trueCount; StrCounter2++) {
                  b_coffecients[StrCounter2 + 2 * i2] =
                      coffecients[(static_cast<int>(tRow_data[StrCounter2]) +
                                   coffecients.size(0) * i2) -
                                  1];
                }
              }
              if (b_coffecients.size(1) == 0) {
                nanV_NodalsIndexes.set_size(1, 0);
              } else {
                npages = b_coffecients.size(1);
                nanV_NodalsIndexes.set_size(1, b_coffecients.size(1));
                for (StrCounter = 0; StrCounter < npages; StrCounter++) {
                  width = StrCounter << 1;
                  nanV_NodalsIndexes[StrCounter] =
                      b_coffecients[width] + b_coffecients[width + 1];
                }
              }
              loop_ub = results.size(1);
              width = results.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                for (StrCounter2 = 0; StrCounter2 < trueCount; StrCounter2++) {
                  b_results_data[StrCounter2] =
                      results[static_cast<int>(tRow_data[StrCounter2]) - 1];
                }
              }
              results_data.set(&b_results_data[0], trueCount, width);
              if (results_data.size(1) == 0) {
                knownV_NodalsIndexes.set_size(1, 0);
              } else {
                npages = results_data.size(1);
                knownV_NodalsIndexes.set_size(1, results_data.size(1));
                for (StrCounter = 0; StrCounter < npages; StrCounter++) {
                  width = StrCounter << 1;
                  knownV_NodalsIndexes[StrCounter] =
                      results_data[width] + results_data[width + 1];
                }
              }
              width = knownV_NodalsIndexes.size(1);
              loop_ub = knownV_NodalsIndexes.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                numberOfNodes = knownV_NodalsIndexes[i2];
              }
              if ((coffecients.size(0) != 0) && (coffecients.size(1) != 0)) {
                npages = coffecients.size(1);
              } else if (nanV_NodalsIndexes.size(1) != 0) {
                npages = nanV_NodalsIndexes.size(1);
              } else {
                npages = coffecients.size(1);
              }
              from2 = (npages == 0);
              if (from2 ||
                  ((coffecients.size(0) != 0) && (coffecients.size(1) != 0))) {
                loop_ub = coffecients.size(0);
              } else {
                loop_ub = 0;
              }
              if (from2 || (nanV_NodalsIndexes.size(1) != 0)) {
                StrCounter = 1;
              } else {
                StrCounter = 0;
              }
              SupportiveEquation.set_size(loop_ub + StrCounter, npages);
              for (i2 = 0; i2 < npages; i2++) {
                for (StrCounter2 = 0; StrCounter2 < loop_ub; StrCounter2++) {
                  SupportiveEquation[StrCounter2 +
                                     SupportiveEquation.size(0) * i2] =
                      coffecients[StrCounter2 + loop_ub * i2];
                }
              }
              for (i2 = 0; i2 < npages; i2++) {
                for (StrCounter2 = 0; StrCounter2 < StrCounter; StrCounter2++) {
                  SupportiveEquation[loop_ub +
                                     SupportiveEquation.size(0) * i2] =
                      nanV_NodalsIndexes[StrCounter * i2];
                }
              }
              coffecients.set_size(SupportiveEquation.size(0),
                                   SupportiveEquation.size(1));
              loop_ub = SupportiveEquation.size(0) * SupportiveEquation.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                coffecients[i2] = SupportiveEquation[i2];
              }
              if ((results.size(0) != 0) && (results.size(1) != 0)) {
                npages = 1;
              } else if (width != 0) {
                npages = 1;
              } else {
                npages = (results.size(1) > 0);
              }
              from2 = (npages == 0);
              if (from2 || ((results.size(0) != 0) && (results.size(1) != 0))) {
                loop_ub = results.size(0);
              } else {
                loop_ub = 0;
              }
              if (from2 || (width != 0)) {
                StrCounter = 1;
              } else {
                StrCounter = 0;
              }
              b_solution.set_size(loop_ub + StrCounter, npages);
              for (i2 = 0; i2 < npages; i2++) {
                for (StrCounter2 = 0; StrCounter2 < loop_ub; StrCounter2++) {
                  b_solution[StrCounter2] = results[StrCounter2];
                }
              }
              for (i2 = 0; i2 < npages; i2++) {
                for (StrCounter2 = 0; StrCounter2 < StrCounter; StrCounter2++) {
                  b_solution[loop_ub] = numberOfNodes;
                }
              }
              results.set_size(b_solution.size(0), b_solution.size(1));
              loop_ub = b_solution.size(0) * b_solution.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                results[i2] = b_solution[i2];
              }
            }
          }
          // for yy = 1 : size(RowsToBeSum,1)
          solution.set_size(RowsToBeSum.size(0) * RowsToBeSum.size(1));
          loop_ub = RowsToBeSum.size(0) * RowsToBeSum.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            solution[i1] = RowsToBeSum[i1];
          }
          npages = RowsToBeSum.size(0) * RowsToBeSum.size(1) - 1;
          trueCount = 0;
          width = 0;
          for (b_i = 0; b_i <= npages; b_i++) {
            if (RowsToBeSum[b_i] != 0.0) {
              trueCount++;
            }
            if (solution[b_i] != 0.0) {
              solution[width] = solution[b_i];
              width++;
            }
          }
          solution.set_size(trueCount);
          if (trueCount > 1) {
            coder::internal::sort(solution);
            if (coffecients.size(0) < 1) {
              nanV_NodalsIndexes.set_size(1, 0);
            } else {
              nanV_NodalsIndexes.set_size(1, coffecients.size(0));
              loop_ub = coffecients.size(0) - 1;
              for (i1 = 0; i1 <= loop_ub; i1++) {
                nanV_NodalsIndexes[i1] = static_cast<double>(i1) + 1.0;
              }
            }
            coder::do_vectors(nanV_NodalsIndexes, solution,
                              knownV_NodalsIndexes, ia, &width);
            width = coffecients.size(1) - 1;
            SupportiveEquation.set_size(knownV_NodalsIndexes.size(1),
                                        coffecients.size(1));
            for (i1 = 0; i1 <= width; i1++) {
              loop_ub = knownV_NodalsIndexes.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                SupportiveEquation[i2 + SupportiveEquation.size(0) * i1] =
                    coffecients[(static_cast<int>(knownV_NodalsIndexes[i2]) +
                                 coffecients.size(0) * i1) -
                                1];
              }
            }
            coffecients.set_size(SupportiveEquation.size(0),
                                 SupportiveEquation.size(1));
            loop_ub = SupportiveEquation.size(0) * SupportiveEquation.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              coffecients[i1] = SupportiveEquation[i1];
            }
            if (results.size(0) < 1) {
              nanV_NodalsIndexes.set_size(1, 0);
            } else {
              nanV_NodalsIndexes.set_size(1, results.size(0));
              loop_ub = results.size(0) - 1;
              for (i1 = 0; i1 <= loop_ub; i1++) {
                nanV_NodalsIndexes[i1] = static_cast<double>(i1) + 1.0;
              }
            }
            coder::do_vectors(nanV_NodalsIndexes, solution,
                              knownV_NodalsIndexes, ia, &width);
            width = results.size(1) - 1;
            b_solution.set_size(knownV_NodalsIndexes.size(1), results.size(1));
            for (i1 = 0; i1 <= width; i1++) {
              loop_ub = knownV_NodalsIndexes.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                b_solution[i2] =
                    results[static_cast<int>(knownV_NodalsIndexes[i2]) - 1];
              }
            }
            results.set_size(b_solution.size(0), b_solution.size(1));
            loop_ub = b_solution.size(0) * b_solution.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              results[i1] = b_solution[i1];
            }
          }
          // end
          //
          //  for yy = 1 : size(ColumnsToBeSum,1)
          //  tCol=ColumnsToBeSum(yy,:);
          //  tCol = tCol(tCol~=0);
          //  minimum_column_index = min(tCol);
          //  tempCoff = coffecients(:,tCol);
          //  summ = sum(coffecients(:,tCol)');
          //  summ = summ'
          //  tempCol= ColumnsToBeSum(yy,:);
          //  tempCol = tempCol(tempCol~= minimum_column_index);
          //  coffecients = coffecients(:,setdiff(1:end,tempCol));%% 2s2s el
          //  3mdan elmsh m7tagha coffecients(:,minimum_column_index)= summ; end
          //  coffecients(1,:) = coffecients(1,:) + coffecients(end,:);
          //  results(1,1)= results(1,1)+results(end,1);
          //  result2 = results(1:end-1,:);
          //  coffecients2= coffecients(1:end-1,:);
          coder::mpower(coffecients, SupportiveEquation);
          coder::internal::blas::mtimes(SupportiveEquation, results,
                                        b_solution);
          if ((b_solution.size(0) == 0) || (b_solution.size(1) == 0)) {
            n = 0;
          } else {
            n = b_solution.size(0);
          }
          for (npages = 0; npages < n; npages++) {
            nodals[static_cast<int>(UnknownNodalsIndexes[npages]) - 1].V =
                b_solution[npages];
          }
          //  for cc = 1: length(solution)
          //   fprintf("node(%d) : %d
          //   \n",UnknownNodalsIndexes(cc),solution(cc));
          //  end
          //  for cc = nodals
          //   fprintf("node(%d) : %d Volt\n",cc.Id,cc.V);
          //  end
          //  If There was a rows to sum Up
          //  If Not Then :
        } else {
          coder::mpower(alternativeSolution, SupportiveEquation);
          npages = SupportiveEquation.size(0) - 1;
          StrCounter = SupportiveEquation.size(1);
          solution.set_size(SupportiveEquation.size(0));
          for (b_i = 0; b_i <= npages; b_i++) {
            solution[b_i] = 0.0;
          }
          for (trueCount = 0; trueCount < StrCounter; trueCount++) {
            width = trueCount * SupportiveEquation.size(0);
            for (b_i = 0; b_i <= npages; b_i++) {
              solution[b_i] = solution[b_i] + SupportiveEquation[width + b_i] *
                                                  SupportiveResults[trueCount];
            }
          }
          i1 = solution.size(0);
          for (npages = 0; npages < i1; npages++) {
            nodals[static_cast<int>(UnknownNodalsIndexes[npages]) - 1].V =
                solution[npages];
          }
          //  for cc = 1: length(solution)
          //   fprintf("node(%d) : %d
          //   \n",UnknownNodalsIndexes(cc),solution(cc));
          //  end
          //  for cc = nodals
          //   fprintf("node(%d) : %d Volt\n",cc.Id,cc.V);
          //  end
        }
      }
      //  %% End Of SuperNodel And 0 hom Wires Loop
    }
    //  end of ( checking if there are elements in coffecients matrix )
    //  %% Printing Results
    //  %% Saving To Txt
    //  fid = fopen("nodes.txt","w");
    //  if fid < 0
    //  fprintf('\n error: cant create the file \n');
    //  end
    //
    //   str1 = "";
    //   str2 = "";
    //
    if (nodals.size(1) == 0) {
      n = 0;
    } else {
      n = nodals.size(1);
    }
    for (npages = 0; npages < n; npages++) {
      str.init(nodals[npages].Id);
      numberOfNodes = nodals[npages].V;
      width = snprintf(nullptr, 0, "%.3f", numberOfNodes);
      str_from2.set_size(1, width + 1);
      snprintf(&str_from2[0], (size_t)(width + 1), "%.3f", numberOfNodes);
      if (1 > width) {
        width = 0;
      }
      str_from2.set_size(str_from2.size(0), width);
      loop_ub = str.Value.size[1];
      if (0 <= loop_ub - 1) {
        std::copy(&str.Value.data[0], &str.Value.data[loop_ub],
                  &varargin_1_data[0]);
      }
      varargin_1_data[str.Value.size[1]] = '\x00';
      str_to2.set_size(1, str_from2.size(1) + 1);
      loop_ub = str_from2.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        str_to2[i1] = str_from2[i1];
      }
      str_to2[str_from2.size(1)] = '\x00';
      printf("node(%s) : %s Volt\n", &varargin_1_data[0], &str_to2[0]);
      fflush(stdout);
      //  fprintf(fid,"%s,%s \n",str1,str2);
    }
    //  fclose(fid);
    //  fid = fopen("currents.txt",'wt');
    //
    //  if fid < 0
    //  fprintf('\n error: cant create the file \n');
    //  end
    //  for cc =1: length(nodals)
    //      for x = 1: length(nodals(cc).Nodal_Ids)
    //          if ~isnan(nodals(cc).Nodal_Ids(x))
    //              temp = nodals(cc).Nodal_Ids;
    //  fprintf(fid,"%d,%d-%d \n",nodals(cc).Id,temp(x,1),temp(x,2));
    //          end
    //  %% x = cc.Noda_Ids x stores column by column ... not row by row
    //  %% i wil inverse it 22lbha and try again
    //
    //  %     for x = cc.Nodal_Ids'
    //  %         if ~isnan(x(2))
    //
    //  %% Thats How to specify a certain location in 2d array with only one
    //  index (_indx)
    //  %%  node_id         value
    //  %%   1               3
    //  %%   2               4
    //
    //      end
    //  end
    //  fclose(fid);
    //  count_ = 1;
    //  node_from_str = "";
    //  node_to_str = "";
    //  current_str = "";
    //  resistance_str = "";
    //  for count = 1 : length(nodals)
    //      count_ = count+1;
    //  if count+1 > length(nodals)
    //      count_ = 1;
    //  end
    //      tempR = Nodal.GetRValue(nodals{count},nodals{count_});
    //      for h = 1:length(tempR)
    //      if ~isnan(tempR(h))
    //          Current = (nodals{count}.V-nodals{count_}.V)/tempR(h);
    //          resistance_str = string(tempR(h));
    //          node_from_str= string(count(1,1));
    //          node_to_str = string(count_(1,1));
    //          current_str = sprintf('%.3f',Current);
    //      fprintf("The Current Move Through \nThe Resistance %s ohm Between
    //      Node %s and %s is : %s Amp
    //      \n\n\n",resistance_str,node_from_str,node_to_str,current_str); end
    //  end
    //  End Of Printing Results Operation
    //  Assigning Values To Output Arrays
    arrayOfNodesIds.set_size(1, i);
    arrayOfPotentialVs.set_size(1, i);
    for (width = 0; width < i; width++) {
      b_succeed = 1;
      arrayOfNodesIds[width] = nodals[width].Id;
      arrayOfPotentialVs[width] = nodals[width].V;
    }
  }
  *succeed = b_succeed;
}

//
// File trailer for SolverX.cpp
//
// [EOF]
//

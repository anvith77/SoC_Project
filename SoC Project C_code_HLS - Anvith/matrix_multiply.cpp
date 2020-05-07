/*****************************************************************************
 *
 *     Author: Xilinx, Inc.
 *
 *     This text contains proprietary, confidential information of
 *     Xilinx, Inc. , is distributed by under license from Xilinx,
 *     Inc., and may be used, copied and/or disclosed only pursuant to
 *     the terms of a valid license agreement with Xilinx, Inc.
 *
 *     XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"
 *     AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND
 *     SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,
 *     OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,
 *     APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION
 *     THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,
 *     AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE
 *     FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY
 *     WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE
 *     IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR
 *     REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF
 *     INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *     FOR A PARTICULAR PURPOSE.
 *
 *     Xilinx products are not intended for use in life support appliances,
 *     devices, or systems. Use in such applications is expressly prohibited.
 *
 *     (c) Copyright 2013-2014 Xilinx Inc.
 *     All rights reserved.
 *
 *****************************************************************************/

#include "matrix_multiply.h"

// The top-level function to synthesize
//
void matrix_multiply_topA(const MATRIX_T1 P [P_ROWS][P_COLS],
                    const MATRIX_T1 Q [Q_ROWS][Q_COLS],
                    MATRIX_T1 A[A_ROWS][A_COLS]){

  MATRIX_T1 p_i [P_ROWS][P_COLS];
  MATRIX_T1 q_i [Q_ROWS][Q_COLS];
  MATRIX_T1 a_i [A_ROWS][A_COLS];

  // Copy input data to local memory
  p_row_loop : for (int r=0;r<P_ROWS;r++) {
    p_col_loop : for (int c=0;c<P_COLS;c++) {
      p_i[r][c] = P[r][c];
    }
  }
  q_row_loop :  for (int r=0;r<Q_ROWS;r++) {
    q_col_loop : for (int c=0;c<Q_COLS;c++) {
      q_i[r][c] = Q[r][c];
    }
  }

  // Call multiplier
  hls::matrix_multiply <hls::NoTranspose, hls::NoTranspose, P_ROWS, P_COLS, Q_ROWS, Q_COLS, A_ROWS, A_COLS, MATRIX_T1, MATRIX_T1> (p_i, q_i, a_i);

  // Copy local memory contents to outputs
  a_row_loop : for (int r=0;r<P_COLS;r++) {
    a_col_loop : for (int c=0;c<Q_COLS;c++) {
      A[r][c] = a_i[r][c];
    }
  }
}


  void matrix_multiply_topB (const MATRIX_T2 Q1 [Q1_ROWS][Q1_COLS],
                      const MATRIX_T2 R [R_ROWS][R_COLS],
                      MATRIX_T2 B[B_ROWS][B_COLS]){

    MATRIX_T2 q1_i [Q1_ROWS][Q1_COLS];
    MATRIX_T2 r_i [R_ROWS][R_COLS];
    MATRIX_T2 b_i [B_ROWS][B_COLS];

    // Copy input data to local memory
    q1_row_loop : for (int r=0;r<Q1_ROWS;r++) {
      q1_col_loop : for (int c=0;c<Q1_COLS;c++) {
        q1_i[r][c] = Q1[r][c];
      }
    }
    r_row_loop :  for (int r=0;r<R_ROWS;r++) {
      r_col_loop : for (int c=0;c<R_COLS;c++) {
        r_i[r][c] = R[r][c];
      }
    }

    // Call multiplier
    hls::matrix_multiply <hls::NoTranspose, hls::NoTranspose, Q1_ROWS, Q1_COLS, R_ROWS, R_COLS, B_ROWS, B_COLS, MATRIX_T2, MATRIX_T2> (q1_i, r_i, b_i);

    // Copy local memory contents to outputs
    b_row_loop : for (int r=0;r<Q1_COLS;r++) {
      b_col_loop : for (int c=0;c<R_COLS;c++) {
        B[r][c] = b_i[r][c];
      }
    }
  }

  void matrix_multiply_topC (const MATRIX_T3 P1 [P1_ROWS][P1_COLS],
                       const MATRIX_T3 R1 [R1_ROWS][R1_COLS],
                       MATRIX_T3 C[C_ROWS][C_COLS]){

     MATRIX_T2 p1_i [P1_ROWS][P1_COLS];
     MATRIX_T2 r1_i [R1_ROWS][R1_COLS];
     MATRIX_T2 c_i [C_ROWS][C_COLS];

     // Copy input data to local memory
     p1_row_loop : for (int r=0;r<P1_ROWS;r++) {
       p1_col_loop : for (int c=0;c<P1_COLS;c++) {
         p1_i[r][c] = P1[r][c];
       }
     }
     r1_row_loop :  for (int r=0;r<R1_ROWS;r++) {
       r1_col_loop : for (int c=0;c<R1_COLS;c++) {
         r1_i[r][c] = R1[r][c];
       }
     }

     // Call multiplier
     hls::matrix_multiply <hls::NoTranspose, hls::NoTranspose, P1_ROWS, P1_COLS, R1_ROWS, R1_COLS, C_ROWS, C_COLS, MATRIX_T3, MATRIX_T3> (p1_i, r1_i, c_i);

     // Copy local memory contents to outputs
     c_row_loop : for (int r=0;r<P1_COLS;r++) {
       c_col_loop : for (int c=0;c<R1_COLS;c++) {
         C[r][c] = c_i[r][c];
       }
     }
   }

  void matrix_multiply_topAB (const MATRIX_T4 A1 [A1_ROWS][A1_COLS],
                       const MATRIX_T4 B1 [B1_ROWS][B1_COLS],
                       MATRIX_T4 AB[AB_ROWS][AB_COLS]){

     MATRIX_T4 a1_i [A1_ROWS][A1_COLS];
     MATRIX_T4 b1_i [B1_ROWS][B1_COLS];
     MATRIX_T4 ab_i [AB_ROWS][AB_COLS];

     // Copy input data to local memory
     a1_row_loop : for (int r=0;r<A1_ROWS;r++) {
       a1_col_loop : for (int c=0;c<A1_COLS;c++) {
         a1_i[r][c] = A1[r][c];
       }
     }
     b1_row_loop :  for (int r=0;r<B1_ROWS;r++) {
       b1_col_loop : for (int c=0;c<B1_COLS;c++) {
         b1_i[r][c] = B1[r][c];
       }
     }

     // Call multiplier
     hls::matrix_multiply <hls::NoTranspose, hls::NoTranspose,A1_ROWS, A1_COLS, B1_ROWS, B1_COLS, AB_ROWS, AB_COLS, MATRIX_T4, MATRIX_T4> (a1_i, b1_i, ab_i);

     // Copy local memory contents to outputs
     ab_row_loop : for (int r=0;r<A1_COLS;r++) {
       ab_col_loop : for (int c=0;c<B1_COLS;c++) {
         AB[r][c] = ab_i[r][c];
       }
     }
   }

  void matrix_multiply_topABalpha (const MATRIX_T5 AB1 [AB1_ROWS][AB1_COLS],
                       const MATRIX_T5 ALP [ALP_ROWS][ALP_COLS],
                       MATRIX_T5 CO1[CO1_ROWS][CO1_COLS]){

     MATRIX_T5 ab1_i [AB1_ROWS][AB1_COLS];
     MATRIX_T5 alp_i [ALP_ROWS][ALP_COLS];
     MATRIX_T5 co1_i [CO1_ROWS][CO1_COLS];

     // Copy input data to local memory
     ab1_row_loop : for (int r=0;r<AB1_ROWS;r++) {
       ab1_col_loop : for (int c=0;c<AB1_COLS;c++) {
         ab1_i[r][c] = AB1[r][c];
       }
     }
     alp_row_loop :  for (int r=0;r<ALP_ROWS;r++) {
       alp_col_loop : for (int c=0;c<ALP_COLS;c++) {
         alp_i[r][c] = ALP[r][c];
       }
     }

     // Call multiplier
     hls::matrix_multiply <hls::NoTranspose, hls::NoTranspose,AB1_ROWS, AB1_COLS, ALP_ROWS, ALP_COLS, CO1_ROWS, CO1_COLS, MATRIX_T5, MATRIX_T5> (ab1_i, alp_i, co1_i);

     // Copy local memory contents to outputs
     co1_row_loop : for (int r=0;r<CO1_COLS;r++) {
       co1_col_loop : for (int c=0;c<CO1_COLS;c++) {
         CO1[r][c] = co1_i[r][c];
       }
     }
   }

  void matrix_multiply_topCbeta (const MATRIX_T6 C1 [C1_ROWS][C1_COLS],
                         const MATRIX_T6 BETA [BETA_ROWS][BETA_COLS],
                         MATRIX_T6 CO2[CO2_ROWS][CO2_COLS]){

       MATRIX_T6 c1_i [C1_ROWS][C1_COLS];
       MATRIX_T6 beta_i [BETA_ROWS][BETA_COLS];
       MATRIX_T6 co2_i [CO2_ROWS][CO2_COLS];

       // Copy input data to local memory
       c1_row_loop : for (int r=0;r<C1_ROWS;r++) {
         c1_col_loop : for (int c=0;c<C1_COLS;c++) {
           c1_i[r][c] = C1[r][c];
         }
       }
       beta_row_loop :  for (int r=0;r<BETA_ROWS;r++) {
         beta_col_loop : for (int c=0;c<BETA_COLS;c++) {
           beta_i[r][c] = BETA[r][c];
         }
       }

       // Call multiplier
       hls::matrix_multiply <hls::NoTranspose, hls::NoTranspose,C1_ROWS,C1_COLS, BETA_ROWS, BETA_COLS, CO2_ROWS, CO2_COLS, MATRIX_T6, MATRIX_T6> (c1_i, beta_i, co2_i);

       // Copy local memory contents to outputs
       co2_row_loop : for (int r=0;r<CO2_COLS;r++) {
         co2_col_loop : for (int c=0;c<CO2_COLS;c++) {
           CO2[r][c] = co2_i[r][c];
         }
       }
     }


  void matrix_addition_cout (const MATRIX_T7 CO3 [CO3_ROWS][CO3_COLS],
          const MATRIX_T7 CO4 [CO4_ROWS][CO4_COLS],
          MATRIX_T7 COUT[COUT_ROWS][COUT_COLS]){

   MATRIX_T7 co3_i [CO3_ROWS][CO3_COLS];
   MATRIX_T7 co4_i [CO4_ROWS][CO4_COLS];
   MATRIX_T7 cout_i [COUT_ROWS][COUT_COLS];

   // Copy input data to local memory
   co3_row_loop : for (int r=0;r<CO3_ROWS;r++) {
     co3_col_loop : for (int c=0;c<CO3_COLS;c++) {
       co3_i[r][c] = CO3[r][c];
     }
   }
   co4_row_loop :  for (int r=0;r<CO4_ROWS;r++) {
     co4_col_loop : for (int c=0;c<CO4_COLS;c++) {
       co4_i[r][c] = CO4[r][c];
     }
   }

  // {
 //	  for (i = 0; i < r; ++i)
 	//          for (j = 0; j < c; ++j) {
 	//              sum[i][j] = a[i][j] + b[i][j];
  // }

   // Call multiplier
   hls::matrix_multiply <hls::NoTranspose, hls::NoTranspose,CO3_ROWS,CO3_COLS, CO4_ROWS, CO4_COLS, COUT_ROWS, COUT_COLS, MATRIX_T7, MATRIX_T7> (co3_i, co4_i, cout_i);

   // Copy local memory contents to outputs
   cout_row_loop : for (int r=0;r<COUT_COLS;r++) {
     cout_col_loop : for (int c=0;c<COUT_COLS;c++) {
       COUT[r][c] = co4_i[r][c]+co3_i[r][c];
       //COUT[r][c] = cout_i[r][c];
     }
   }
  }












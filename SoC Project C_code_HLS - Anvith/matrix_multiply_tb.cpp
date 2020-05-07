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
#include "hls/linear_algebra/utils/x_hls_matrix_utils.h"
#include "hls/linear_algebra/utils/x_hls_matrix_tb_utils.h"

int main (void){
// for the initial matrix A= P X Q
  MATRIX_T1 P[P_ROWS][P_COLS];
  MATRIX_T1 Q[Q_ROWS][Q_COLS];
  MATRIX_T1  A[A_ROWS][A_COLS];

  P[0][0] = 1.0;  P[0][1] = 2.0;  P[0][2] = 3.0;
  P[1][0] = 4.0;  P[1][1] = 5.0;  P[1][2] = 6.0;
  P[2][0] = 7.0;  P[2][1] = 8.0;  P[2][2] = 9.0;

  Q[0][0] = 1.0;  Q[0][1] = 0.0;  Q[0][2] = 0.0;
  Q[1][0] = 0.0;  Q[1][1] = 1.0;  Q[1][2] = 0.0;
  Q[2][0] = 0.0;  Q[2][1] = 0.0;  Q[2][2] = 1.0;

  matrix_multiply_topA(P, Q, A);

  printf("P = \n");
  hls::print_matrix<P_ROWS, P_COLS, MATRIX_T1, hls::NoTranspose>(P, "   ");

  printf("Q = \n");
  hls::print_matrix<Q_ROWS, Q_COLS, MATRIX_T1, hls::NoTranspose>(Q, "   ");

  printf("A = \n");
  hls::print_matrix<A_ROWS, A_COLS, MATRIX_T1, hls::NoTranspose>(A, "   ");

  printf("\n");
  printf("The above Matrix A = P x Q \n");
  printf("----------------------------------------------------------------\n");
  // ends here for A ****************************************
  // Generate error ratio and compare against threshold value
  // - LAPACK error measurement method
  // - Threshold taken from LAPACK test functions
  //if ( difference_ratio<P_ROWS, P_COLS>(P,A) > 30.0 ) {
    //return(1);

  // for the initial matrix B = Q x R

  MATRIX_T2 Q1[Q1_ROWS][Q1_COLS];
  MATRIX_T2 R[R_ROWS][R_COLS];
  MATRIX_T2 B[B_ROWS][B_COLS];

  Q1[0][0] = 1.0;  Q1[0][1] = 0.0;  Q1[0][2] = 0.0;
  Q1[1][0] = 0.0;  Q1[1][1] = 1.0;  Q1[1][2] = 0.0;
  Q1[2][0] = 0.0;  Q1[2][1] = 0.0;  Q1[2][2] = 1.0;

  R[0][0] = 1.0;  R[0][1] = 4.0;  R[0][2] = 9.0;
  R[1][0] = 2.0;  R[1][1] = 5.0;  R[1][2] = 8.0;
  R[2][0] = 3.0;  R[2][1] = 6.0;  R[2][2] = 7.0;

  matrix_multiply_topB(Q1, R, B);

  printf("Q = \n");
  hls::print_matrix<Q1_ROWS, Q1_COLS, MATRIX_T2, hls::NoTranspose>(Q1, "   ");

  printf("R = \n");
  hls::print_matrix<R_ROWS, R_COLS, MATRIX_T2, hls::NoTranspose>(R, "   ");

  printf("B = \n");
  hls::print_matrix<B_ROWS, B_COLS, MATRIX_T2, hls::NoTranspose>(B, "   ");

  printf("\n");
  printf(" Above Matrix B = Q x R \n");
  printf("----------------------------------------------------------------\n");

  // for calculating matrix B it ends here **************************************
  // I've taken Q1 = Q as the same variables cannot be reused as they were previously declared

    MATRIX_T3 P1[P1_ROWS][P1_COLS];
    MATRIX_T3 R1[R1_ROWS][R1_COLS];
    MATRIX_T3 C[C_ROWS][C_COLS];

    P1[0][0] = 1.0;  P1[0][1] = 2.0;  P1[0][2] = 3.0;
    P1[1][0] = 4.0;  P1[1][1] = 5.0;  P1[1][2] = 6.0;
    P1[2][0] = 7.0;  P1[2][1] = 8.0;  P1[2][2] = 9.0;

    R1[0][0] = 1.0;  R1[0][1] = 4.0;  R1[0][2] = 9.0;
    R1[1][0] = 2.0;  R1[1][1] = 5.0;  R1[1][2] = 8.0;
    R1[2][0] = 3.0;  R1[2][1] = 6.0;  R1[2][2] = 7.0;

    matrix_multiply_topC(P1, R1, C);

    printf("P = \n");
    hls::print_matrix<Q1_ROWS, Q1_COLS, MATRIX_T2, hls::NoTranspose>(P1, "   ");

    printf("R = \n");
    hls::print_matrix<R_ROWS, R_COLS, MATRIX_T2, hls::NoTranspose>(R1, "   ");

    printf("C = \n");
    hls::print_matrix<B_ROWS, B_COLS, MATRIX_T2, hls::NoTranspose>(C, "   ");

    printf("\n");
    printf("Above matrix C = P x R \n");
    printf("----------------------------------------------------------------\n");

    MATRIX_T4 A1[A1_ROWS][A1_COLS];
    MATRIX_T4 B1[B1_ROWS][B1_COLS];
    MATRIX_T4 AB[AB_ROWS][AB_COLS];

    A1[0][0] = 1.0;  A1[0][1] = 2.0;  A1[0][2] = 3.0;
    A1[1][0] = 4.0;  A1[1][1] = 5.0;  A1[1][2] = 6.0;
    A1[2][0] = 7.0;  A1[2][1] = 8.0;  A1[2][2] = 9.0;

    B1[0][0] = 1.0;  B1[0][1] = 4.0;  B1[0][2] = 9.0;
    B1[1][0] = 2.0;  B1[1][1] = 5.0;  B1[1][2] = 8.0;
    B1[2][0] = 3.0;  B1[2][1] = 6.0;  B1[2][2] = 7.0;


    matrix_multiply_topAB(A1, B1, AB);

        printf("A = \n");
        hls::print_matrix<A_ROWS, B_COLS, MATRIX_T4, hls::NoTranspose>(A, "   ");

        printf("B = \n");
        hls::print_matrix<A_ROWS, B_COLS, MATRIX_T4, hls::NoTranspose>(B, "   ");

        printf("AB = \n");
        hls::print_matrix<AB_ROWS, AB_COLS, MATRIX_T4, hls::NoTranspose>(AB, "   ");

        printf("\n");
        printf("The above matrix is AB = A x B \n");
        printf("----------------------------------------------------------------\n");

  int alpha = 10;
      MATRIX_T5 AB1[AB1_ROWS][AB1_COLS];
      MATRIX_T5 ALP[ALP_ROWS][ALP_COLS];
      MATRIX_T5 CO1[CO1_ROWS][CO1_COLS];

      AB1[0][0] = 14.0;  AB1[0][1] = 32.0;  AB1[0][2] = 46.0;
      AB1[1][0] = 32.0;  AB1[1][1] = 77.0;  AB1[1][2] = 118.0;
      AB1[2][0] = 50.0;  AB1[2][1] = 122.0;  AB1[2][2] = 190.0;

      ALP[0][0] = alpha;  ALP[0][1] = 0.0;  ALP[0][2] = 0.0;
      ALP[1][0] = 0.0;    ALP[1][1] = alpha;  ALP[1][2] = 0.0;
      ALP[2][0] = 0.0;    ALP[2][1] = 0.0;    ALP[2][2] = alpha;


      matrix_multiply_topABalpha(AB1, ALP, CO1);

          printf("AB = \n");
          hls::print_matrix<AB1_ROWS,ALP_COLS, MATRIX_T5, hls::NoTranspose>(AB1, "   ");

          printf("Alpha = \n");
          hls::print_matrix<ALP_ROWS, ALP_COLS, MATRIX_T5, hls::NoTranspose>(ALP, "   ");

          printf("AB x alpha = \n");
          hls::print_matrix<CO1_ROWS, CO1_COLS, MATRIX_T5, hls::NoTranspose>(CO1, "   ");

          printf("\n");
          printf("The above matrix is AB-alpha = AB x alpha \n");
          printf("----------------------------------------------------------------\n");

  int beta = 5 ;
  	    MATRIX_T6 C1[C1_ROWS][C1_COLS];
        MATRIX_T6 BETA[BETA_ROWS][BETA_COLS];
        MATRIX_T6 CO2[CO2_ROWS][CO2_COLS];

        C1[0][0] = 14.0;  C1[0][1] = 32.0;  C1[0][2] = 46.0;
        C1[1][0] = 32.0;  C1[1][1] = 77.0;  C1[1][2] = 118.0;
        C1[2][0] = 50.0;  C1[2][1] = 122.0;  C1[2][2] = 190.0;

        BETA[0][0] = beta;  BETA[0][1] = 0.0;  BETA[0][2] = 0.0;
        BETA[1][0] = 0.0;  BETA[1][1] = beta;  BETA[1][2] = 0.0;
        BETA[2][0] = 0.0;  BETA[2][1] = 0.0;  BETA[2][2] = beta;


        matrix_multiply_topCbeta(C1, BETA, CO2);

            printf("C = \n");
            hls::print_matrix<C1_ROWS,C1_COLS, MATRIX_T6, hls::NoTranspose>(C1, "   ");

            printf("Beta = \n");
            hls::print_matrix<BETA_ROWS, BETA_COLS, MATRIX_T6, hls::NoTranspose>(BETA, "   ");

            printf("C x Beta = \n");
            hls::print_matrix<CO1_ROWS, CO1_COLS, MATRIX_T6, hls::NoTranspose>(CO2, "   ");

            printf("\n");
            printf("The above matrix is C-beta = C x beta \n");
            printf("----------------------------------------------------------------\n");


            MATRIX_T7 CO3[CO3_ROWS][CO3_COLS];
            MATRIX_T7 CO4[CO4_ROWS][CO4_COLS];
            MATRIX_T7 COUT[COUT_ROWS][COUT_COLS];

           CO3[0][0] = 140.0;   CO3[0][1] = 320.0;   CO3[0][2] = 460.0;
           CO3[1][0] = 320.0;   CO3[1][1] = 770.0;  CO3[1][2] = 1180.0;
           CO3[2][0] = 500.0;   CO3[2][1] = 1220.0;  CO3[2][2] = 1900.0;

           CO4[0][0] = 70.0;    CO4[0][1] = 160.0;    CO4[0][2] = 230.0;
           CO4[1][0] = 160.0;  CO4[1][1] = 385.0;    CO4[1][2] = 590.0;
           CO4[2][0] = 250.0;  CO4[2][1] = 610.0;    CO4[2][2] = 950.0;

           matrix_addition_cout(CO3 , CO4 ,COUT);

           printf("AB x alpha = \n");
           hls::print_matrix<CO3_ROWS,CO3_COLS, MATRIX_T7, hls::NoTranspose>(CO3, "   ");

           printf("C x Beta = \n");
           hls::print_matrix<CO4_ROWS, CO4_COLS, MATRIX_T7, hls::NoTranspose>(CO4, "   ");

           printf("Cout = \n");
           hls::print_matrix<COUT_ROWS, COUT_COLS, MATRIX_T7, hls::NoTranspose>(COUT, "   ");

           printf("\n");
           printf("The above matrix is Cout = C-beta + AB-alpha \n");
           printf("----------------------------------------------------------------\n");


        return(0);




}

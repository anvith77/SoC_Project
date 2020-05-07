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

#ifndef MATRIX_MULTIPLY_H
#define MATRIX_MULTIPLY_H

#include "hls_linear_algebra.h"

//const unsigned A_ROWS = 3;
//const unsigned A_COLS = 3;
//const unsigned B_ROWS = 3;
//const unsigned B_COLS = 3;
//const unsigned C_ROWS = A_ROWS;
//const unsigned C_COLS = B_COLS;

const unsigned P_ROWS = 3;
const unsigned P_COLS = 3;
const unsigned Q_ROWS = 3;
const unsigned Q_COLS = 3;
const unsigned A_ROWS = P_ROWS;
const unsigned A_COLS = Q_ROWS;

const unsigned Q1_ROWS = 3;
const unsigned Q1_COLS = 3;
const unsigned R_ROWS = 3;
const unsigned R_COLS = 3;
const unsigned B_ROWS = Q1_ROWS;
const unsigned B_COLS = R_ROWS;

const unsigned P1_ROWS = 3;
const unsigned P1_COLS = 3;
const unsigned R1_ROWS = 3;
const unsigned R1_COLS = 3;
const unsigned C_ROWS = P1_ROWS;
const unsigned C_COLS = R1_ROWS;

const unsigned A1_ROWS = 3;
const unsigned A1_COLS = 3;
const unsigned B1_ROWS = 3;
const unsigned B1_COLS = 3;
const unsigned AB_ROWS = 3;
const unsigned AB_COLS = 3;

const unsigned AB1_ROWS = 3;
const unsigned AB1_COLS = 3;
const unsigned ALP_ROWS = 3;
const unsigned ALP_COLS = 3;
const unsigned CO1_ROWS = AB1_ROWS;
const unsigned CO1_COLS = ALP_ROWS;

const unsigned C1_ROWS = 3;
const unsigned C1_COLS = 3;
const unsigned BETA_ROWS = 3;
const unsigned BETA_COLS = 3;
const unsigned CO2_ROWS = C1_ROWS;
const unsigned CO2_COLS = BETA_ROWS;

const unsigned CO3_ROWS = 3;
const unsigned CO3_COLS = 3;
const unsigned CO4_ROWS = 3;
const unsigned CO4_COLS = 3;
const unsigned COUT_ROWS = CO3_ROWS;
const unsigned COUT_COLS = CO4_ROWS;





// Define implementation type
typedef float MATRIX_T1;

void matrix_multiply_topA(const MATRIX_T1 P [P_ROWS][P_COLS],
                         const MATRIX_T1 Q [Q_ROWS][Q_COLS],
                         MATRIX_T1 A[A_ROWS][A_COLS]);

typedef float MATRIX_T2;

void matrix_multiply_topB(const MATRIX_T2 Q1 [Q1_ROWS][Q1_COLS],
                         const MATRIX_T2 R [R_ROWS][R_COLS],
                         MATRIX_T2 B[B_ROWS][B_COLS]);

typedef float MATRIX_T3;

void matrix_multiply_topC(const MATRIX_T3 P1 [P1_ROWS][P1_COLS],
                         const MATRIX_T3 R1 [R1_ROWS][R1_COLS],
                         MATRIX_T3 C[C_ROWS][C_COLS]);

typedef float MATRIX_T4;

void matrix_multiply_topAB(const MATRIX_T4 A [A_ROWS][A_COLS],
                         const MATRIX_T4 B [B_ROWS][B_COLS],
                         MATRIX_T4 AB[AB_ROWS][AB_COLS]);

typedef float MATRIX_T5;

void matrix_multiply_topABalpha(const MATRIX_T5 AB1 [AB1_ROWS][AB1_COLS],
                         const MATRIX_T5 B [ALP_ROWS][ALP_COLS],
                         MATRIX_T5 CO1[CO1_ROWS][CO1_COLS]);

typedef float MATRIX_T6;

void matrix_multiply_topCbeta(const MATRIX_T6 C1 [C1_ROWS][C1_COLS],
                         const MATRIX_T6 B [BETA_ROWS][BETA_COLS],
                         MATRIX_T6 CO2[CO2_ROWS][CO2_COLS]);


typedef float MATRIX_T7;

void matrix_addition_cout (const MATRIX_T7 CO3 [CO3_ROWS][CO3_COLS],
        const MATRIX_T7 CO4 [CO4_ROWS][CO4_COLS],
        MATRIX_T7 COUT[COUT_ROWS][COUT_COLS]);


#endif

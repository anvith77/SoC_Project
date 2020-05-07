`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2020 04:14:45 PM
// Design Name: 
// Module Name: gemm
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

//module gemm();
module gemm(A,B,C,D,Cout,clk);

    //input and output ports.
    //The size 32 bits which is 2*2=4 elements,each of which is 8 bits wide.    
    input [31:0] A;
    input [31:0] B;
    input [31:0] C;
    //input [63:0] C;
    input [31:0] D; // using D as a temporary matrix (unit matrix) to avoid any changes in values
    output [31:0] Cout;
                                                   //during matrix multiplication 
    integer alpha = 2;
    integer beta = 1;
    input clk;
    //internal variables    
    reg [31:0] Cout;
    reg [7:0] A1 [0:1][0:1];
    reg [7:0] B1 [0:1][0:1];
    reg [7:0] C1 [0:1][0:1];
    reg [7:0] D1 [0:1][0:1];
    reg [7:0] Cout1 [0:1][0:1]; 
 //   reg [7:0] A1 [0:99][0:99];
 //   reg [7:0] B1 [0:99][0:99];
 //   reg [7:0] C1 [0:99][0:99];
 //   reg [7:0] D1 [0:99][0:99];
 //   reg [7:0] Cout1 [0:99][0:99]; 
    integer i,j,k;
    integer m,n,o;

    always@ (posedge clk)
    begin
   //Initialize the matrices-convert 1 D to 3D arrays    
   //     for(m=0;m < 99;m=m+1)
   //             for(n=0;n < 99;n=n+1)
                    
   //                 {A1[m][n],A1[m+1][n],A1[m][n+1],A1[m+1][n+1]} = A;
   //                 {B1[m][n],B1[m+1][n],B1[m][n+1],B1[m+1][n+1]} = B;
   //                 {C1[m][n],C1[m+1][n],C1[m][n+1],C1[m+1][n+1]} = C;
   //                 {D1[m][n],D1[m+1][n],D1[m][n+1],D1[m+1][n+1]} = D;
    
    
    
        {A1[0][0],A1[0][1],A1[1][0],A1[1][1]} = A;
        {B1[0][0],B1[0][1],B1[1][0],B1[1][1]} = B;
        {C1[0][0],C1[0][1],C1[1][0],C1[1][1]} = C;
        {D1[0][0],D1[0][1],D1[1][0],D1[1][1]} = D;
        i = 0;
        j = 0;
        k = 0;
        {Cout1[0][0],Cout1[0][1],Cout1[1][0],Cout1[1][1]} = 32'd0; //initializing all to zeros.
        //Matrix multiplication
  //      for(i=0;i < 99;i=i+1)
  //          for(j=0;j < 99;j=j+1)
  //              for(k=0;k < 99;k=k+1)
  //                  Cout1[i][j] = Cout1[i][j] + ((A1[i][k] * B1[k][j] * alpha)+ (C1[i][k] * D1[k][j] * beta));
                    //+( ( C1[i][k]*Temp1[k][j] ) )));
       
        for(i=0;i < 2;i=i+1)
               for(j=0;j < 2;j=j+1)
                       for(k=0;k < 2;k=k+1)
                           Cout1[i][j] = Cout1[i][j] + ((A1[i][k] * B1[k][j] * alpha)+ (C1[i][k] * D1[k][j] * beta));      
                          // Cout = Cout1 + ( AxB * alpha ) + ( C * beta ); 
       //final output assignment - 3D array to 1D array conversion.            
        Cout = {Cout1[0][0],Cout1[0][1],Cout1[1][0],Cout1[1][1]};            
    end 

endmodule

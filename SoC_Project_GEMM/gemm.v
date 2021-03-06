`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/07/2020 12:38:24 PM
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
    integer i,j,k;

    always@ (posedge clk)
    begin
    //Initialize the matrices-convert 1 D to 3D arrays
        {A1[0][0],A1[0][1],A1[1][0],A1[1][1]} = A;
        {B1[0][0],B1[0][1],B1[1][0],B1[1][1]} = B;
        {C1[0][0],C1[0][1],C1[1][0],C1[1][1]} = C;
        {D1[0][0],D1[0][1],D1[1][0],D1[1][1]} = D;
        i = 0;
        j = 0;
        k = 0;
        {Cout1[0][0],Cout1[0][1],Cout1[1][0],Cout1[1][1]} = 32'd0; //initializing all to zeros.
        //Matrix multiplication
        for(i=0;i < 2;i=i+1)
            for(j=0;j < 2;j=j+1)
                for(k=0;k < 2;k=k+1)
                    Cout1[i][j] = Cout1[i][j] + ((A1[i][k] * B1[k][j] * alpha)+ (C1[i][k] * D1[k][j] * beta));//+( ( C1[i][k]*Temp1[k][j] ) )));
       // Cout = Cout1 + ( AxB * alpha ) + ( C * beta ); 
       //final output assignment - 3D array to 1D array conversion.            
        Cout = {Cout1[0][0],Cout1[0][1],Cout1[1][0],Cout1[1][1]};            
    end 

endmodule


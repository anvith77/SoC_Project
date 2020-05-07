`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2020 6:17:41 PM
// Design Name: 
// Module Name: gemm_tb
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

module gemm_tb();


    // Inputs
    reg [31:0] A;
    reg [31:0] B;
    reg [31:0] C;
    reg [31:0] D;
    reg clk;
    // Outputs
    wire [31:0] Cout;

    // Instantiate the Unit Under Test (UUT)
    gemm uut (
        .A(A), 
        .B(B), 
        .C(C),
        .D(D),
        .clk(clk),
        .Cout(Cout)
    );
    always #10 clk = !clk;
    initial begin
        // Apply Inputs
//           repeat(10)
//           begin
//           A=$random;
//           B=$random;
//           C=$random;
//           D=D = {8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,
//                  8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,
//                  8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,
//                  8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd1,8'd1,
//                  8'd1,8'd0,8'd0,8'd1,8'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,
//                  8'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,
//                  8'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1,8'd0,8'd0,8'd18'd1};
//          };
//           #10;
//           $display("%0b %0b %0b %0b ",A,B,C,D);
//           end

        clk=0;
        A = 0;  B = 0; C = 0; D =0; #10;
        A = {8'd1,8'd2,8'd3,8'd4};
        B = {8'd5,8'd6,8'd7,8'd8};
        C = {8'd5,8'd6,8'd7,8'd8};
        D = {8'd1,8'd0,8'd0,8'd1};
   
    end
      

endmodule
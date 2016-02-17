`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:49:26 02/14/2016 
// Design Name: 
// Module Name:    FFround 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module FFround(a,b,c,d,m,s,t,aO);

input [31:0] a,b,c,d,m,t;
input [31:0] s;
output [31:0] aO;

//wire [31:0] aO;
///
//wire [31:0] A1,A0,B0,C0,D0;
//
//wire [480:511] msg;
//
//assign msg[480:511] = 32'h61616161;
//
//assign A0[31:0] = 32'h67452301;
//assign B0[31:0] = 32'hefcdab89;
//assign C0[31:0] = 32'h98badcfe;
//assign D0[31:0] = 32'h10325476;
////
wire   [31:0] result;
wire   [31:0] rotate_result1;
wire   [31:0] rotate_result2;

//wire   [31:0] result1;
//
//assign result1 = F(B0,C0,D0);
//assign result = (A0 + F(B0,C0,D0) + msg[480:511] + 32'hd76aa478);
//assign rotate_result1 = result << 7;
//assign rotate_result2 = result >> (32-7);
//assign aO = B0 + (rotate_result1 | rotate_result2);

assign result = (a + F(b,c,d) + m + t);
assign rotate_result1 = result << s;
assign rotate_result2 = result >> (32-s);
assign aO = b + (rotate_result1 | rotate_result2);

function [31:0] F;
input [31:0] x, y, z;
begin // {
   F = (x&y)|((~x)&z);
end // }
endfunction // }

endmodule

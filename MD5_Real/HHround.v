`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:59:19 02/14/2016 
// Design Name: 
// Module Name:    GGround 
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
module HHround(a,b,c,d,m,s,t,aO);

input [31:0] a,b,c,d,m,t;
input [31:0] s;
output [31:0] aO;

wire   [31:0] add_result;
wire  [31:0] rotate_result1;
wire   [31:0] rotate_result2;

assign add_result = (a + H(b,c,d) + m + t);
assign rotate_result1 = add_result << s;
assign rotate_result2 = add_result >> (32-s);
assign aO = b + (rotate_result1 | rotate_result2);

function [31:0] H;
input [31:0] x, y, z;
begin 
   H = (x^y^z);
end
endfunction 
endmodule
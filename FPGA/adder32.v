`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:47:58 02/08/2016 
// Design Name: 
// Module Name:    adder32 
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
module adder32(s,a,b);
//32 bit adder
//Takes two 32 bit numbers and a carry in bit
//Ouputs a 32 bit sum and a carry over bit
//The sum is completed using 4 8-bit adders


input [31:0] a, b;
input ci;
output [31:0] s;
output co;

wire o,o1,o2;

adder8 a81(s[7:0], o, a[7:0], b[7:0], 0);
adder8 a82(s[15:8], o1, a[15:8], b[15:8], o);
adder8 a83(s[23:16], o2, a[23:16], b[23:16], o1);
adder8 a84(s[31:24], co, a[31:24], b[31:24], o2);


	


endmodule

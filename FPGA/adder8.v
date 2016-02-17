`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:08:48 02/08/2016 
// Design Name: 
// Module Name:    adder8 
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
module adder8(s,co,a,b,ci);
//uses the full adder module to make an 8 bit adder
//inputs two 8 bit numbers (a,b) and a carry-in bit (ci)
//outputs an 8 bit sum (s) and a carry-over bit (co)

input [7:0] a, b;
input ci;

output [7:0] s;
output co;

wire o, o1, o2, o3, o4, o5, o6;

fulladder fa1(s[0], o, a[0], b[0], ci);
fulladder fa2(s[1], o1, a[1], b[1], o);
fulladder fa3(s[2], o2, a[2], b[2], o1);
fulladder fa4(s[3], o3, a[3], b[3], o2);
fulladder fa5(s[4], o4, a[4], b[4], o3);
fulladder fa6(s[5], o5, a[5], b[5], o4);
fulladder fa7(s[6], o6, a[6], b[6], o5);
fulladder fa8(s[7], co, a[7], b[7], o6);

endmodule

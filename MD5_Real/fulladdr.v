`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:00:37 02/14/2016 
// Design Name: 
// Module Name:    fulladdr 
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
module fulladdr(a,b,ci,sum,co);

input a,b,ci;
output sum,co;

wire ori1,ori2,ha2i;

halfaddr ha1(a,b,ori1,ha2i);
halfaddr ha2(ori1,ci,ori2,sum);

or or1(ori1,ori2,co);

endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:10:51 02/08/2016 
// Design Name: 
// Module Name:    fulladder 
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
module fulladderTP(s,co,a,b,ci);
//takes inputs a,b,ci (carry-in bit)
//outputs s,co (carry-over bit)

//s = a xor b xor c
//co = bc + ac + ab

input a,b,ci;
output s,co;

wire o, o1, o2, o3, o4;

and and1(o,b,ci);
and and2(o1,a,ci);
and and3(o2,a,b);

or or1(o3,o,o1);
or or2(co,o2,o3);

xor xor1(o4,a,b);
xor	xor2(s,ci,o4);


endmodule

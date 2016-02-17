`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:02:25 02/14/2016 
// Design Name: 
// Module Name:    halfaddr 
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
module halfaddr(a,b,sum,co);
//adds bits a,b and gives result s with carry bit c
input a,b;
output co,sum;

assign sum = a^b;
assign co = a&b;

endmodule

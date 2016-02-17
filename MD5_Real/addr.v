`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:56:18 02/13/2016 
// Design Name: 
// Module Name:    addr 
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
module addr(a,b,ci,sum,co);

input [31:0] a,b;
input ci;
output [31:0]sum;
output co;

wire c1,c2,c3;

addr8 a81(a[7:0],b[7:0],ci,sum[7:0],c1);
addr8 a82(a[15:8],b[15:8],c1,sum[15:8],c2);
addr8 a83(a[23:16],b[23:16],c2,sum[23:16],c3);
addr8 a84(a[23:16],b[23:16],c3,sum[23:16],co);



endmodule

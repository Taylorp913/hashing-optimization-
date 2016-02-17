`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:59:49 02/13/2016 
// Design Name: 
// Module Name:    addr8 
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
module addr8(x,y,ci,sum,co);

input [7:0] x,y;
input ci;
output [7:0] sum;
output co;

wire c1,c2,c3,c4,c5,c6;

fulladdr fa0(x[0],y[0],ci,sum[0],c1);
fulladdr fa1(x[1],y[1],c1,sum[1],c2);
fulladdr fa2(x[2],y[2],c2,sum[2],c3);
fulladdr fa3(x[3],y[3],c3,sum[3],c4);
fulladdr fa4(x[4],y[4],c4,sum[4],c5);
fulladdr fa5(x[5],y[5],c5,sum[5],c6);
fulladdr fa6(x[6],y[6],c6,sum[6],co);


endmodule

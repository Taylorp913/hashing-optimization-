`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:35:46 02/14/2016 
// Design Name: 
// Module Name:    round_testbench 
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
`define T_1  32'hd76aa478
`define T_2  32'he8c7b756

module round_testbench(A1);

output [31:0] A1;

wire [31:0] A1,A0,B0,C0,D0,B1;

wire [448:511] msg;

assign msg[480:511] = 32'h61616161;
assign msg[448:479] = 32'h00806161;

assign A0[31:0] = 32'h67452301;
assign B0[31:0] = 32'hefcdab89;
assign C0[31:0] = 32'h98badcfe;
assign D0[31:0] = 32'h10325476;

FFround FF0(	A0[31:0],B0[31:0],C0[31:0],D0[31:0],		msg[480:511],	32'd07,`T_1 ,A1[31:0]);
FFround FF1(	D0[31:0],A1[31:0],B0[31:0],C0[31:0],		msg[448:479],	32'd12,`T_2 ,B1[31:0]);


endmodule

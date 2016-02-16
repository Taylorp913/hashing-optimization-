`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:44:41 02/11/2016 
// Design Name: 
// Module Name:    Iterate_MD5 
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
`define T_3  32'h242070db
`define T_4  32'hc1bdceee
`define T_5  32'hf57c0faf
`define T_6  32'h4787c62a
`define T_7  32'ha8304613
`define T_8  32'hfd469501
`define T_9  32'h698098d8
`define T_10 32'h8b44f7af
`define T_11 32'hffff5bb1
`define T_12 32'h895cd7be
`define T_13 32'h6b901122
`define T_14 32'hfd987193
`define T_15 32'ha679438e
`define T_16 32'h49b40821
`define T_17 32'hf61e2562
`define T_18 32'hc040b340
`define T_19 32'h265e5a51
`define T_20 32'he9b6c7aa
`define T_21 32'hd62f105d
`define T_22  32'h2441453
`define T_23 32'hd8a1e681
`define T_24 32'he7d3fbc8
`define T_25 32'h21e1cde6
`define T_26 32'hc33707d6
`define T_27 32'hf4d50d87
`define T_28 32'h455a14ed
`define T_29 32'ha9e3e905
`define T_30 32'hfcefa3f8
`define T_31 32'h676f02d9
`define T_32 32'h8d2a4c8a
`define T_33 32'hfffa3942
`define T_34 32'h8771f681
`define T_35 32'h6d9d6122
`define T_36 32'hfde5380c
`define T_37 32'ha4beea44
`define T_38 32'h4bdecfa9
`define T_39 32'hf6bb4b60
`define T_40 32'hbebfbc70
`define T_41 32'h289b7ec6
`define T_42 32'heaa127fa
`define T_43 32'hd4ef3085
`define T_44  32'h4881d05
`define T_45 32'hd9d4d039
`define T_46 32'he6db99e5
`define T_47 32'h1fa27cf8
`define T_48 32'hc4ac5665
`define T_49 32'hf4292244
`define T_50 32'h432aff97
`define T_51 32'hab9423a7
`define T_52 32'hfc93a039
`define T_53 32'h655b59c3
`define T_54 32'h8f0ccc92
`define T_55 32'hffeff47d
`define T_56 32'h85845dd1
`define T_57 32'h6fa87e4f
`define T_58 32'hfe2ce6e0
`define T_59 32'ha3014314
`define T_60 32'h4e0811a1
`define T_61 32'hf7537e82
`define T_62 32'hbd3af235
`define T_63 32'h2ad7d2bb
`define T_64 32'heb86d391

module Iterate_MD5(clk,msg,A,B,C,D);
input [0:511]msg;
input clk;
output [31:0] A,B,C,D;

wire [31:0] A,B,C,D;
wire [31:0] A0,B0,C0,D0,A1,B1,C1,D1,A2,B2,C2,D2,A3,B3,C3,D3,A4,B4,C4,D4;
wire [31:0] A5,B5,C5,D5,A6,B6,C6,D6,A7,B7,C7,D7,A8,B8,C8,D8;
wire [31:0] A9,B9,C9,D9,A10,B10,C10,D10,A11,B11,C11,D11,A12,B12,C12,D12;
wire [31:0] A13,B13,C13,D13,A14,B14,C14,D14,A15,B15,C15,D15,A16,B16,C16,D16;
wire [31:0] AF,BF,CF,DF;

assign A0[31:0] = 32'h67452301;
assign B0[31:0] = 32'hefcdab89;
assign C0[31:0] = 32'h98badcfe;
assign D0[31:0] = 32'h10325476;

reg [6:0] iter = 0;
reg [6:0] next = 0;

always@(*) begin
	next[6:0] = iter[6:0] + 1;
	end
	
always@(posedge clk) begin
		iter[6:0] = next[6:0];
end

FFround FF0(	A0[31:0],B0[31:0],C0[31:0],D0[31:0],		msg[480:511],	32'd07,`T_1 ,A1[31:0]);
FFround FF1(	D0[31:0],A1[31:0],B0[31:0],C0[31:0],		msg[448:479],	32'd12,`T_2 ,D1[31:0]);
FFround FF2(	C0[31:0],D1[31:0],A1[31:0],B0[31:0],		msg[416:447],	32'd17,`T_3 ,C1[31:0]);
FFround FF3(	B0[31:0],C1[31:0],D1[31:0],A1[31:0],		msg[384:415],	32'd22,`T_4 ,B1[31:0]);
FFround FF4(	A1[31:0],B1[31:0],C1[31:0],D1[31:0],		msg[352:383],	32'd07,`T_5 ,A2[31:0]);
FFround FF5(	D1[31:0],A2[31:0],B1[31:0],C1[31:0],		msg[320:351],	32'd12,`T_6 ,D2[31:0]);
FFround FF6(	C1[31:0],D2[31:0],A2[31:0],B1[31:0],		msg[288:319],	32'd17,`T_7 ,C2[31:0]);
FFround FF7(	B1[31:0],C2[31:0],D2[31:0],A2[31:0],		msg[256:287],	32'd22,`T_8 ,B2[31:0]);
FFround FF8(	A2[31:0],B2[31:0],C2[31:0],D2[31:0],		msg[224:255],	32'd07,`T_9 ,A3[31:0]);
FFround FF9(	D2[31:0],A3[31:0],B2[31:0],C2[31:0],		msg[192:223],	32'd12,`T_10,D3[31:0]);
FFround FF10(	C2[31:0],D3[31:0],A3[31:0],B2[31:0],		msg[160:191],	32'd17,`T_11,C3[31:0]);
FFround FF11(	B2[31:0],C3[31:0],D3[31:0],A3[31:0],		msg[128:159],	32'd22,`T_12,B3[31:0]);
FFround FF12(	A3[31:0],B3[31:0],C3[31:0],D3[31:0],		msg[96:127],	32'd07,`T_13,A4[31:0]);
FFround FF13(	D3[31:0],A4[31:0],B3[31:0],C3[31:0],		msg[64:95],		32'd12,`T_14,D4[31:0]);
FFround FF14(	C3[31:0],D4[31:0],A4[31:0],B3[31:0],		msg[32:63],		32'd17,`T_15,C4[31:0]);
FFround FF15(	B3[31:0],C4[31:0],D4[31:0],A4[31:0],		msg[0:31],		32'd22,`T_16,B4[31:0]);

GGround GG0(	A4[31:0],B4[31:0],C4[31:0],D4[31:0],		msg[448:479],	32'd05,`T_17,A5[31:0]);
GGround GG1(	D4[31:0],A5[31:0],B4[31:0],C4[31:0],		msg[288:319],	32'd09,`T_18,D5[31:0]);
GGround GG2(	C4[31:0],D5[31:0],A5[31:0],B4[31:0],		msg[128:159],	32'd14,`T_19,C5[31:0]);
GGround GG3(	B4[31:0],C5[31:0],D5[31:0],A5[31:0],		msg[480:511],	32'd20,`T_20,B5[31:0]);
GGround GG4(	A5[31:0],B5[31:0],C5[31:0],D5[31:0],		msg[320:351],	32'd05,`T_21,A6[31:0]);
GGround GG5(	D5[31:0],A6[31:0],B5[31:0],C5[31:0],		msg[160:191],	32'd09,`T_22,D6[31:0]);
GGround GG6(	C5[31:0],D6[31:0],A6[31:0],B5[31:0],		msg[0:31]   ,	32'd14,`T_23,C6[31:0]);
GGround GG7(	B5[31:0],C6[31:0],D6[31:0],A6[31:0],		msg[352:383],	32'd20,`T_24,B6[31:0]);
GGround GG8(	A6[31:0],B6[31:0],C6[31:0],D6[31:0],		msg[192:223],	32'd05,`T_25,A7[31:0]);
GGround GG9(	D6[31:0],A7[31:0],B6[31:0],C6[31:0],		msg[32:63]  ,	32'd09,`T_26,D7[31:0]);
GGround GG10(	C6[31:0],D7[31:0],A7[31:0],B6[31:0],		msg[384:415],	32'd14,`T_27,C7[31:0]);
GGround GG11(	B6[31:0],C7[31:0],D7[31:0],A7[31:0],		msg[224:255],	32'd20,`T_28,B7[31:0]);
GGround GG12(	A7[31:0],B7[31:0],C7[31:0],D7[31:0],		msg[64:95]  ,	32'd05,`T_29,A8[31:0]);
GGround GG13(	D7[31:0],A8[31:0],B7[31:0],C7[31:0],		msg[416:447],	32'd09,`T_30,D8[31:0]);
GGround GG14(	C7[31:0],D8[31:0],A8[31:0],B7[31:0],		msg[256:287],	32'd14,`T_31,C8[31:0]);
GGround GG15(	B7[31:0],C8[31:0],D8[31:0],A8[31:0],		msg[96:127] ,	32'd20,`T_32,B8[31:0]);
	
HHround HH0(	A8[31:0],B8[31:0],C8[31:0],D8[31:0],		msg[320:351],	32'd04,`T_33,A9[31:0]);
HHround HH1(	D8[31:0],A9[31:0],B8[31:0],C8[31:0],		msg[224:255],	32'd11,`T_34,D9[31:0]);
HHround HH2(	C8[31:0],D9[31:0],A9[31:0],B8[31:0],		msg[128:159],	32'd16,`T_35,C9[31:0]);
HHround HH3(	B8[31:0],C9[31:0],D9[31:0],A9[31:0],		msg[32:63]  ,	32'd23,`T_36,B9[31:0]);
HHround HH4(	A9[31:0],B9[31:0],C9[31:0],D9[31:0],		msg[448:479],	32'd04,`T_37,A10[31:0]);
HHround HH5(	D9[31:0],A10[31:0],B9[31:0],C9[31:0],		msg[352:383],	32'd11,`T_38,D10[31:0]);
HHround HH6(	C9[31:0],D10[31:0],A10[31:0],B9[31:0],		msg[256:287],	32'd16,`T_39,C10[31:0]);
HHround HH7(	B9[31:0],C10[31:0],D10[31:0],A10[31:0],		msg[160:191],	32'd23,`T_40,B10[31:0]);
HHround HH8(	A10[31:0],B10[31:0],C10[31:0],D10[31:0],	msg[64:95]  ,	32'd04,`T_41,A11[31:0]);
HHround HH9(	D10[31:0],A11[31:0],B10[31:0],C10[31:0],	msg[480:511],	32'd11,`T_42,D11[31:0]);
HHround HH10(	C10[31:0],D11[31:0],A11[31:0],B10[31:0],	msg[384:415],	32'd16,`T_43,C11[31:0]);
HHround HH11(	B10[31:0],C11[31:0],D11[31:0],A11[31:0],	msg[288:319],	32'd23,`T_44,B11[31:0]);
HHround HH12(	A11[31:0],B11[31:0],C11[31:0],D11[31:0],	msg[192:223],	32'd04,`T_45,A12[31:0]);
HHround HH13(	D11[31:0],A12[31:0],B11[31:0],C11[31:0],	msg[96:127] ,	32'd11,`T_46,D12[31:0]);
HHround HH14(	C11[31:0],D12[31:0],A12[31:0],B11[31:0],	msg[0:31]   ,	32'd16,`T_47,C12[31:0]);
HHround HH15(	B11[31:0],C12[31:0],D12[31:0],A12[31:0],	msg[416:447],	32'd23,`T_48,B12[31:0]);

IIround II0(	A12[31:0],B12[31:0],C12[31:0],D12[31:0],	msg[480:511],	32'd06,`T_49,A13[31:0]);
IIround II1(	D12[31:0],A13[31:0],B12[31:0],C12[31:0],	msg[256:287],	32'd10,`T_50,D13[31:0]);
IIround II2(	C12[31:0],D13[31:0],A13[31:0],B12[31:0],	msg[32:63]  ,	32'd15,`T_51,C13[31:0]);
IIround II3(	B12[31:0],C13[31:0],D13[31:0],A13[31:0],	msg[320:351],	32'd21,`T_52,B13[31:0]);
IIround II4(	A13[31:0],B13[31:0],C13[31:0],D13[31:0],	msg[96:127] ,	32'd06,`T_53,A14[31:0]);
IIround II5(	D13[31:0],A14[31:0],B13[31:0],C13[31:0],	msg[384:415],	32'd10,`T_54,D14[31:0]);
IIround II6(	C13[31:0],D14[31:0],A14[31:0],B13[31:0],	msg[160:191],	32'd15,`T_55,C14[31:0]);
IIround II7(	B13[31:0],C14[31:0],D14[31:0],A14[31:0],	msg[448:479],	32'd21,`T_56,B14[31:0]);
IIround II8(	A14[31:0],B14[31:0],C14[31:0],D14[31:0],	msg[224:255],	32'd06,`T_57,A15[31:0]);
IIround II9(	D14[31:0],A15[31:0],B14[31:0],C14[31:0],	msg[0:31]   ,	32'd10,`T_58,D15[31:0]);
IIround II10(	C14[31:0],D15[31:0],A15[31:0],B14[31:0],	msg[288:319],	32'd15,`T_59,C15[31:0]);
IIround II11(	B14[31:0],C15[31:0],D15[31:0],A15[31:0],	msg[64:95]  ,	32'd21,`T_60,B15[31:0]);
IIround II12(	A15[31:0],B15[31:0],C15[31:0],D15[31:0],	msg[352:383],	32'd06,`T_61,A16[31:0]);
IIround II13(	D15[31:0],A16[31:0],B15[31:0],C15[31:0],	msg[128:159],	32'd10,`T_62,D16[31:0]);
IIround II14(	C15[31:0],D16[31:0],A16[31:0],B15[31:0],	msg[416:447],	32'd15,`T_63,C16[31:0]);
IIround II15(	B15[31:0],C16[31:0],D16[31:0],A16[31:0],	msg[192:223],	32'd21,`T_64,B16[31:0]);

assign AF[31:0] = A16[31:0]+A0[31:0];
assign BF[31:0] = B16[31:0]+B0[31:0];
assign CF[31:0] = C16[31:0]+C0[31:0];
assign DF[31:0] = D16[31:0]+D0[31:0];

assign A[31:0]=AF[31:0];
assign B[31:0]=BF[31:0];
assign C[31:0]=CF[31:0];
assign D[31:0]=DF[31:0];

endmodule

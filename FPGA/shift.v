`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:05:11 02/10/2016 
// Design Name: 
// Module Name:    shift 
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
module shift(outmsg, inmsg, shift);

input [31:0]inmsg;
output [31:0]outmsg;
input [4:0]shift;


//assign inmsg[31:0] = 32'h12345678;
wire [4:0]first, six, twofive;
//assign first[4:0] = 32-((shift+0)%32);
//assign six[4:0] = 32-((shift+6)%32);
//assign twofive[4:0] = 32-((shift+25)%32);


assign	outmsg[0] = inmsg[((32-shift)+0)%32];
assign	outmsg[1] = inmsg[((32-shift)+1)%32];
assign	outmsg[2] = inmsg[((32-shift)+2)%32];
assign	outmsg[3] = inmsg[((32-shift)+3)%32];
assign	outmsg[4] = inmsg[((32-shift)+4)%32];
assign	outmsg[5] = inmsg[((32-shift)+5)%32];
assign	outmsg[6] = inmsg[((32-shift)+6)%32];
assign	outmsg[7] = inmsg[((32-shift)+7)%32];
assign	outmsg[8] = inmsg[((32-shift)+8)%32];
assign	outmsg[9] = inmsg[((32-shift)+9)%32];
assign	outmsg[10] = inmsg[((32-shift)+10)%32];
assign	outmsg[11] = inmsg[((32-shift)+11)%32];
assign	outmsg[12] = inmsg[((32-shift)+12)%32];
assign  	outmsg[13] = inmsg[((32-shift)+13)%32];
assign	outmsg[14] = inmsg[((32-shift)+14)%32];
assign	outmsg[15] = inmsg[((32-shift)+15)%32];
assign	outmsg[16] = inmsg[((32-shift)+16)%32];
assign	outmsg[17] = inmsg[((32-shift)+17)%32];
assign	outmsg[18] = inmsg[((32-shift)+18)%32];
assign	outmsg[19] = inmsg[((32-shift)+19)%32];
assign	outmsg[20] = inmsg[((32-shift)+20)%32];
assign	outmsg[21] = inmsg[((32-shift)+21)%32];
assign	outmsg[22] = inmsg[((32-shift)+22)%32];
assign	outmsg[23] = inmsg[((32-shift)+23)%32];
assign	outmsg[24] = inmsg[((32-shift)+24)%32];
assign	outmsg[25] = inmsg[((32-shift)+25)%32];
assign	outmsg[26] = inmsg[((32-shift)+26)%32];
assign	outmsg[27] = inmsg[((32-shift)+27)%32];
assign	outmsg[28] = inmsg[((32-shift)+28)%32];
assign	outmsg[29] = inmsg[((32-shift)+29)%32];
assign	outmsg[30] = inmsg[((32-shift)+30)%32];
assign	outmsg[31] = inmsg[((32-shift)+31)%32];


//assign	outmsg[0] = inmsg[32-((shift+0)%32)];
//assign	outmsg[1] = inmsg[32-((shift+1)%32)];
//assign	outmsg[2] = inmsg[32-((shift+2)%32)];
//assign	outmsg[3] = inmsg[32-((shift+3)%32)];
//assign	outmsg[4] = inmsg[32-((shift+4)%32)];
//assign	outmsg[5] = inmsg[32-((shift+5)%32)];
//assign	outmsg[6] = inmsg[32-((shift+6)%32)];
//assign	outmsg[7] = inmsg[32-((shift+7)%32)];
//assign	outmsg[8] = inmsg[32-((shift+8)%32)];
//assign	outmsg[9] = inmsg[32-((shift+9)%32)];
//assign	outmsg[10] = inmsg[32-((shift+10)%32)];
//assign	outmsg[11] = inmsg[32-((shift+11)%32)];
//assign	outmsg[12] = inmsg[32-((shift+12)%32)];
//assign outmsg[13] = inmsg[32-((shift+13)%32)];
//assign	outmsg[14] = inmsg[32-((shift+14)%32)];
//assign	outmsg[15] = inmsg[32-((shift+15)%32)];
//assign	outmsg[16] = inmsg[32-((shift+16)%32)];
//assign	outmsg[17] = inmsg[32-((shift+17)%32)];
//assign	outmsg[18] = inmsg[32-((shift+18)%32)];
//assign	outmsg[19] = inmsg[32-((shift+19)%32)];
//assign	outmsg[20] = inmsg[32-((shift+20)%32)];
//assign	outmsg[21] = inmsg[32-((shift+21)%32)];
//assign	outmsg[22] = inmsg[32-((shift+22)%32)];
//assign	outmsg[23] = inmsg[32-((shift+23)%32)];
//assign	outmsg[24] = inmsg[32-((shift+24)%32)];
//assign	outmsg[25] = inmsg[32-((shift+25)%32)];
//assign	outmsg[26] = inmsg[32-((shift+26)%32)];
//assign	outmsg[27] = inmsg[32-((shift+27)%32)];
//assign	outmsg[28] = inmsg[32-((shift+28)%32)];
//assign	outmsg[29] = inmsg[32-((shift+29)%32)];
//assign	outmsg[30] = inmsg[32-((shift+30)%32)];
//assign	outmsg[31] = inmsg[32-((shift+31)%32)];








endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:07:53 02/14/2016 
// Design Name: 
// Module Name:    MD5_run 
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
module MD5_run(led, start);

output reg led;
output reg start;
 
reg clk = 0;

//generate clock
 
always
	#5 clk = ~clk;

always@(posedge clk) begin
	start <= 1;
end

wire [0:511] msg;
wire [31:0] A,B,C,D;
wire [0:31] Aend,Bend,Cend,Dend;

assign msg[480:511] = 32'h7a7a7a7a;
assign msg[448:479] = 32'h00807a7a;
assign msg[416:447] = 32'h00000000;
assign msg[384:415] = 32'h00000000;
assign msg[352:383] = 32'h00000000;
assign msg[320:351] = 32'h00000000;
assign msg[288:319] = 32'h00000000;
assign msg[256:287] = 32'h00000000;
assign msg[224:255] = 32'h00000000;
assign msg[192:223] = 32'h00000000;
assign msg[160:191] = 32'h00000000;
assign msg[128:159] = 32'h00000000;
assign msg[96:127] = 32'h00000000;
assign msg[64:95] = 32'h00000000;
assign msg[32:63] = 32'h00000030;
assign msg[0:31] = 32'h00000000;

//453e41d218e071ccfb2d1c99ce23906a
assign Aend[0:31]=32'hd2413e45;//32'h453e41d2; <<little endian original
assign Bend[0:31]=32'hcc71e018;//32'h18e071cc;
assign Cend[0:31]=32'h991c2dfb;//32'hfb2d1c99;
assign Dend[0:31]=32'h6a9023ce;//32'hce23906a;

Iterate_MD5 yay(clk,msg[0:511],A[31:0],B[31:0],C[31:0],D[31:0]);


always@(posedge clk) begin
	if(A[31:0]==Aend[0:31]&&B[31:0]==Bend[0:31]&&C[31:0]==Cend[0:31]&&D[31:0]==Dend[0:31]) begin
	led<=1;
	end
end


endmodule

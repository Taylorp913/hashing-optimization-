`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:15:46 02/12/2016 
// Design Name: 
// Module Name:    md5_top_top 
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
module md5_top_top(start, port);

//input clk;
output port;
output reg start;

reg clk = 0;

//generate clock
 
always
	#5 clk = ~clk;




always@(posedge clk) begin
	start <= 1;
end


md5_top md5(port, clk);


endmodule

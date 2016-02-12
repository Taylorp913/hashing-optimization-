`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:16:36 02/10/2016 
// Design Name: 
// Module Name:    MD5test 
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
module MD5test;
wire t_y;
reg t_a, t_b;

MD5 my_gate( .a(t_a), .b(t_b), .F(t_y) );
initial
begin
	$monitor(t_a, t_b, t_y);

	t_a = 1'b0;
	t_b = 1'b0;

	#5
	t_a = 1'b0;
	t_b = 1'b1;

	#5 
	t_a = 1'b1;
	t_b = 1'b0;

	#5
	t_a = 1'b1;
	t_b = 1'b1;

end

endmodule

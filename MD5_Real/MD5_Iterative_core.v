`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:43:51 02/11/2016 
// Design Name: 
// Module Name:    MD5_Iterative_core 
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
module MD5_Iterative_core(
		Load_done,
		XEN2,
		WE2,
		XEN1,
		WE1,
		X_sel,
		CV_sel,
		Func_sel,
		Shift_amnt,
		en1,
		en2,
		T_addr,
		X_addr,
		CLK,
		X_in,
		
		msg_output
		);
		
//--------------		
//	Input/Output	
//--------------
input				Load_done;
input				XEN2;
input				WE2;
input				XEN1;
input				WE1;
input				X_sel;
input				CV_sel;
input				Func_sel;
input	 [0:1]	Shift_amnt;
input				en1;
input				en2;
input				T_addr;
input				X_addr;
input				CLK;
input	 [0:32]	X_in;

output [0:127]	msg_output;

//-------------
//Variables
//-------------

//inputs
wire          	CLK;


//outputs
wire [0:127]	msg_output;
			
 



//-------------
//Parameters
//-------------


	
 


endmodule

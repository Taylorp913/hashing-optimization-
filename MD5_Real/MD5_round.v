`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:59:08 02/11/2016 
// Design Name: 
// Module Name:    MD5_rnd 
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
// RNDs

`define RND1 2'b00
`define RND2 2'b01
`define RND3 2'b10
`define RND4 2'b11

module MD5_rnd(
		a
		,b
		,c
		,d
		,message
		,s
		,t
		,rnd
		
		,a_next
		);
		
input  [31:0] a;
input  [31:0] b;
input  [31:0] c;
input  [31:0] d;
input  [31:0] message;    
input  [31:0] s;
input  [31:0] t;        
input   [1:0] rnd;  

output [31:0] a_next;


wire  [31:0] a;         // 
wire  [31:0] b;
wire  [31:0] c;
wire  [31:0] d;
wire  [31:0] message;
wire  [31:0] s;
wire  [31:0] t;
wire   [1:0] rnd;

reg   [31:0] a_next;

reg   [31:0] result;
reg   [31:0] rotate_result1;
reg   [31:0] rotate_result2;		


always @(a
   or    b
   or    c
   or    d
   or    message
   or    s
   or    t
   or    rnd)begin 
   case (rnd)
   `RND1: 
   begin 
      result = ( a+ F(b ,c ,d) + message+ t );
      rotate_result1 = result<<s;
      rotate_result2 = result>>(32-s);
      a_next = b + (rotate_result1|rotate_result2);
   end 
   `RND2: 
   begin
      result = ( a+ G(b ,c ,d) + message+ t );
      rotate_result1 = result<<s;
      rotate_result2 = result>>(32-s);
      a_next = b + (rotate_result1|rotate_result2);
   end
   `RND3:
   begin
      result = ( a+ H(b ,c ,d) + message+ t );
      rotate_result1 = result<<s;
      rotate_result2 = result>>(32-s);
      a_next = b + (rotate_result1|rotate_result2);
   end
   `RND4:
   begin
      result = ( a+ I(b ,c ,d) + message+ t );
      rotate_result1 = result<<s;
      rotate_result2 = result>>(32-s);
      a_next = b + (rotate_result1|rotate_result2);
   end
   endcase
end
//---------------
//functions
//---------------
function [31:0] F;
input [31:0] x, y, z;
begin // {
   F = (x&y)|((~x)&z);
end // }
endfunction // }

function [31:0] G;
input [31:0] x, y, z;
begin
   G = (x&z)|(y&(~z));
end
endfunction 

function [31:0] H;
input [31:0] x, y, z;
begin
   H = (x^y^z);
end
endfunction 

function [31:0] I;
input [31:0] x, y, z;
begin
   I = (y^(x|(~z)));
end
endfunction 

endmodule 

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

`define ROUND1 2'b00
`define ROUND2 2'b01
`define ROUND3 2'b10
`define ROUND4 2'b11

`define T1  32'hd76aa478
`define T2  32'he8c7b756
`define T3  32'h242070db
`define T4  32'hc1bdceee
`define T5  32'hf57c0faf
`define T6  32'h4787c62a
`define T7  32'ha8304613
`define T8  32'hfd469501
`define T9  32'h698098d8
`define T10 32'h8b44f7af
`define T11 32'hffff5bb1
`define T12 32'h895cd7be
`define T13 32'h6b901122
`define T14 32'hfd987193
`define T15 32'ha679438e
`define T16 32'h49b40821
`define T17 32'hf61e2562
`define T18 32'hc040b340
`define T19 32'h265e5a51
`define T20 32'he9b6c7aa
`define T21 32'hd62f105d
`define T22  32'h2441453
`define T23 32'hd8a1e681
`define T24 32'he7d3fbc8
`define T25 32'h21e1cde6
`define T26 32'hc33707d6
`define T27 32'hf4d50d87
`define T28 32'h455a14ed
`define T29 32'ha9e3e905
`define T30 32'hfcefa3f8
`define T31 32'h676f02d9
`define T32 32'h8d2a4c8a
`define T33 32'hfffa3942
`define T34 32'h8771f681
`define T35 32'h6d9d6122
`define T36 32'hfde5380c
`define T37 32'ha4beea44
`define T38 32'h4bdecfa9
`define T39 32'hf6bb4b60
`define T40 32'hbebfbc70
`define T41 32'h289b7ec6
`define T42 32'heaa127fa
`define T43 32'hd4ef3085
`define T44  32'h4881d05
`define T45 32'hd9d4d039
`define T46 32'he6db99e5
`define T47 32'h1fa27cf8
`define T48 32'hc4ac5665
`define T49 32'hf4292244
`define T50 32'h432aff97
`define T51 32'hab9423a7
`define T52 32'hfc93a039
`define T53 32'h655b59c3
`define T54 32'h8f0ccc92
`define T55 32'hffeff47d
`define T56 32'h85845dd1
`define T57 32'h6fa87e4f
`define T58 32'hfe2ce6e0
`define T59 32'ha3014314
`define T60 32'h4e0811a1
`define T61 32'hf7537e82
`define T62 32'hbd3af235
`define T63 32'h2ad7d2bb
`define T64 32'heb86d391


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
			
 
//registers
reg    [0:1] round;
reg  [0:511] msg_appended;
reg   [0:31] a;
reg   [0:31] A;
reg   [0:31] AA;
reg   [0:31] next_A;
reg   [0:31] b;
reg   [0:31] B;
reg   [0:31] BB;
reg   [0:31] next_B;
reg   [0:31] c;
reg   [0:31] C;
reg   [0:31] CC;
reg   [0:31] next_C;
reg   [0:31] d;
reg   [0:31] D;
reg   [0:31] DD;
reg   [0:31] next_D;
reg   [0:31] message;
reg   [0:31] s; 
reg   [0:31] t;
reg    [3:0] phase;         // Counter to determine 16 phases within each round.
wire  [0:31] next_a;
reg    [7:0] current_state;
reg    [7:0] next_state;
reg [8*11:1] ascii_state;


//-------------
//Parameters
//-------------

parameter AI         = 32'h67452301;
parameter BI         = 32'hefcdab89;
parameter CI         = 32'h98badcfe;
parameter DI         = 32'h10325476;



//-------------
//submodule
//-------------



MD5_round ROUND(.a(a),.b(b),.c(c),.d(d),.message(message),.s(s),.t(t),.rnd(round),.a_out(next_a));


//-------------
//Code Start
//-------------
	
 always @(current_state
   or    msg_in_valid
   or    A
   or    B
   or    C
   or    D
   or    phase
   or    msg_appended
   or    next_a
   or    AA
   or    BB
   or    CC
   or    DD

   ) begin
   round = `ROUND1;
   next_A = A;
   next_B = B; 
   next_C = C; 
   next_D = D;
   
   a = 32'h0;
   b = 32'h0;
   c = 32'h0;
   d = 32'h0;
   m = 32'h0;
   s = 32'h0;
   t = 32'h0;
 
 next_state = current_state; 

   case (1'b1) // synopsys full_case parallel_case 

   current_state[IDLE_BIT]: 
   begin

      ascii_state = "IDLE";


      if (msg_in_valid)  
         next_state = ROUND1;
   end

   //----------------------------------------------------------------
   //--------------------------- ROUND 1 ----------------------------
   //----------------------------------------------------------------
   current_state[ROUND1_BIT]: 
   begin

      ascii_state = "ROUND1";


      round = `ROUND1;

      case (phase)
      4'b0000: begin a=A; b=B; c=C; d=D; m=msg_appended[480:511]; s=32'd07; t= `T1; next_A=next_a; end
      4'b0001: begin a=D; b=A; c=B; d=C; m=msg_appended[448:479]; s=32'd12; t= `T2; next_D=next_a; end
      4'b0010: begin a=C; b=D; c=A; d=B; m=msg_appended[416:447]; s=32'd17; t= `T3; next_C=next_a; end
      4'b0011: begin a=B; b=C; c=D; d=A; m=msg_appended[384:415]; s=32'd22; t= `T4; next_B=next_a; end
      4'b0100: begin a=A; b=B; c=C; d=D; m=msg_appended[352:383]; s=32'd07; t= `T5; next_A=next_a; end
      4'b0101: begin a=D; b=A; c=B; d=C; m=msg_appended[320:351]; s=32'd12; t= `T6; next_D=next_a; end
      4'b0110: begin a=C; b=D; c=A; d=B; m=msg_appended[288:319]; s=32'd17; t= `T7; next_C=next_a; end
      4'b0111: begin a=B; b=C; c=D; d=A; m=msg_appended[256:287]; s=32'd22; t= `T8; next_B=next_a; end
      4'b1000: begin a=A; b=B; c=C; d=D; m=msg_appended[224:255]; s=32'd07; t= `T9; next_A=next_a; end
      4'b1001: begin a=D; b=A; c=B; d=C; m=msg_appended[192:223]; s=32'd12; t=`T10; next_D=next_a; end
      4'b1010: begin a=C; b=D; c=A; d=B; m=msg_appended[160:191]; s=32'd17; t=`T11; next_C=next_a; end
      4'b1011: begin a=B; b=C; c=D; d=A; m=msg_appended[128:159]; s=32'd22; t=`T12; next_B=next_a; end
      4'b1100: begin a=A; b=B; c=C; d=D; m=msg_appended[96:127];  s=32'd7;  t=`T13; next_A=next_a; end
      4'b1101: begin a=D; b=A; c=B; d=C; m=msg_appended[64:95];   s=32'd12; t=`T14; next_D=next_a; end
      4'b1110: begin a=C; b=D; c=A; d=B; m=msg_appended[32:63];   s=32'd17; t=`T15; next_C=next_a; end
      4'b1111: begin a=B; b=C; c=D; d=A; m=msg_appended[0:31];    s=32'd22; t=`T16; next_B=next_a; end
      endcase

      // $display (" ROUND1_1: msg_appended[480:511] = %x", msg_appended[480:511]);
      // $display (" ROUND1_1: msg_appended[0:511] = %x", msg_appended[0:511]);

      if (phase == 4'b1111)
         next_state = ROUND2;
   end
   //----------------
   //ROUND 2 --------
   //----------------

   current_state[ROUND2_BIT]:
   begin

      ascii_state = "ROUND2";

 
      round = `ROUND2;
      case (phase) 
      4'b0000: begin a=A; b=B; c=C; d=D; m=msg_appended[448:479]; s=32'd05; t=`T17; next_A=next_a; end
      4'b0001: begin a=D; b=A; c=B; d=C; m=msg_appended[288:319]; s=32'd09; t=`T18; next_D=next_a; end
      4'b0010: begin a=C; b=D; c=A; d=B; m=msg_appended[128:159]; s=32'd14; t=`T19; next_C=next_a; end
      4'b0011: begin a=B; b=C; c=D; d=A; m=msg_appended[480:511]; s=32'd20; t=`T20; next_B=next_a; end
      4'b0100: begin a=A; b=B; c=C; d=D; m=msg_appended[320:351]; s=32'd05; t=`T21; next_A=next_a; end
      4'b0101: begin a=D; b=A; c=B; d=C; m=msg_appended[160:191]; s=32'd09; t=`T22; next_D=next_a; end
      4'b0110: begin a=C; b=D; c=A; d=B; m=msg_appended[0:31];    s=32'd14; t=`T23; next_C=next_a; end
      4'b0111: begin a=B; b=C; c=D; d=A; m=msg_appended[352:383]; s=32'd20; t=`T24; next_B=next_a; end
      4'b1000: begin a=A; b=B; c=C; d=D; m=msg_appended[192:223]; s=32'd05; t=`T25; next_A=next_a; end
      4'b1001: begin a=D; b=A; c=B; d=C; m=msg_appended[32:63];   s=32'd9;  t=`T26; next_D=next_a; end
      4'b1010: begin a=C; b=D; c=A; d=B; m=msg_appended[384:415]; s=32'd14; t=`T27; next_C=next_a; end
      4'b1011: begin a=B; b=C; c=D; d=A; m=msg_appended[224:255]; s=32'd20; t=`T28; next_B=next_a; end
      4'b1100: begin a=A; b=B; c=C; d=D; m=msg_appended[64:95];   s=32'd05; t=`T29; next_A=next_a; end
      4'b1101: begin a=D; b=A; c=B; d=C; m=msg_appended[416:447]; s=32'd09; t=`T30; next_D=next_a; end
      4'b1110: begin a=C; b=D; c=A; d=B; m=msg_appended[256:287]; s=32'd14; t=`T31; next_C=next_a; end
      4'b1111: begin a=B; b=C; c=D; d=A; m=msg_appended[96:127];  s=32'd20; t=`T32; next_B=next_a; end
      endcase

      if (phase == 4'b1111)
         next_state = ROUND3;
   end
   //------------
   //ROUND 3 
   //------------
 
   current_state[ROUND3_BIT]:
   begin

      ascii_state = "ROUND3";

 
      round = `ROUND3;
      case (phase) 
      4'b0000: begin a=A; b=B; c=C; d=D; m=msg_appended[320:351]; s=32'd04; t=`T33; next_A=next_a; end
      4'b0001: begin a=D; b=A; c=B; d=C; m=msg_appended[224:255]; s=32'd11; t=`T34; next_D=next_a; end
      4'b0010: begin a=C; b=D; c=A; d=B; m=msg_appended[128:159]; s=32'd16; t=`T35; next_C=next_a; end
      4'b0011: begin a=B; b=C; c=D; d=A; m=msg_appended[32:63];   s=32'd23; t=`T36; next_B=next_a; end
      4'b0100: begin a=A; b=B; c=C; d=D; m=msg_appended[448:479]; s=32'd04; t=`T37; next_A=next_a; end
      4'b0101: begin a=D; b=A; c=B; d=C; m=msg_appended[352:383]; s=32'd11; t=`T38; next_D=next_a; end
      4'b0110: begin a=C; b=D; c=A; d=B; m=msg_appended[256:287]; s=32'd16; t=`T39; next_C=next_a; end
      4'b0111: begin a=B; b=C; c=D; d=A; m=msg_appended[160:191]; s=32'd23; t=`T40; next_B=next_a; end
      4'b1000: begin a=A; b=B; c=C; d=D; m=msg_appended[64:95];   s=32'd04; t=`T41; next_A=next_a; end
      4'b1001: begin a=D; b=A; c=B; d=C; m=msg_appended[480:511]; s=32'd11; t=`T42; next_D=next_a; end
      4'b1010: begin a=C; b=D; c=A; d=B; m=msg_appended[384:415]; s=32'd16; t=`T43; next_C=next_a; end
      4'b1011: begin a=B; b=C; c=D; d=A; m=msg_appended[288:319]; s=32'd23; t=`T44; next_B=next_a; end
      4'b1100: begin a=A; b=B; c=C; d=D; m=msg_appended[192:223]; s=32'd04; t=`T45; next_A=next_a; end
      4'b1101: begin a=D; b=A; c=B; d=C; m=msg_appended[96:127];  s=32'd11; t=`T46; next_D=next_a; end
      4'b1110: begin a=C; b=D; c=A; d=B; m=msg_appended[0:31];    s=32'd16; t=`T47; next_C=next_a; end
      4'b1111: begin a=B; b=C; c=D; d=A; m=msg_appended[416:447]; s=32'd23; t=`T48; next_B=next_a; end
      endcase

      if (phase == 4'b1111)
         next_state = ROUND4;
   end
   //----------------------------------------------------------------
   //--------------------------- ROUND 4 ----------------------------
   //----------------------------------------------------------------
 
   current_state[ROUND4_BIT]:
   begin

      ascii_state = "ROUND4";

 
      round = `ROUND4;
      case (phase)
      4'b0000: begin a=A; b=B; c=C; d=D; m=msg_appended[480:511]; s=32'd06; t=`T49; next_A=next_a; end
      4'b0001: begin a=D; b=A; c=B; d=C; m=msg_appended[256:287]; s=32'd10; t=`T50; next_D=next_a; end
      4'b0010: begin a=C; b=D; c=A; d=B; m=msg_appended[32:63];   s=32'd15; t=`T51; next_C=next_a; end
      4'b0011: begin a=B; b=C; c=D; d=A; m=msg_appended[320:351]; s=32'd21; t=`T52; next_B=next_a; end
      4'b0100: begin a=A; b=B; c=C; d=D; m=msg_appended[96:127];  s=32'd06; t=`T53; next_A=next_a; end
      4'b0101: begin a=D; b=A; c=B; d=C; m=msg_appended[384:415]; s=32'd10; t=`T54; next_D=next_a; end
      4'b0110: begin a=C; b=D; c=A; d=B; m=msg_appended[160:191]; s=32'd15; t=`T55; next_C=next_a; end
      4'b0111: begin a=B; b=C; c=D; d=A; m=msg_appended[448:479]; s=32'd21; t=`T56; next_B=next_a; end
      4'b1000: begin a=A; b=B; c=C; d=D; m=msg_appended[224:255]; s=32'd06; t=`T57; next_A=next_a; end
      4'b1001: begin a=D; b=A; c=B; d=C; m=msg_appended[0:31];    s=32'd10; t=`T58; next_D=next_a; end
      4'b1010: begin a=C; b=D; c=A; d=B; m=msg_appended[288:319]; s=32'd15; t=`T59; next_C=next_a; end
      4'b1011: begin a=B; b=C; c=D; d=A; m=msg_appended[64:95];   s=32'd21; t=`T60; next_B=next_a; end
      4'b1100: begin a=A; b=B; c=C; d=D; m=msg_appended[352:383]; s=32'd06; t=`T61; next_A=next_a; end
      4'b1101: begin a=D; b=A; c=B; d=C; m=msg_appended[128:159]; s=32'd10; t=`T62; next_D=next_a; end
      4'b1110: begin a=C; b=D; c=A; d=B; m=msg_appended[416:447]; s=32'd15; t=`T63; next_C=next_a; end
      4'b1111: begin a=B; b=C; c=D; d=A; m=msg_appended[192:223]; s=32'd21; t=`T64; next_B=next_a; end
      endcase

      if (phase == 4'b1111)
         next_state = FINISH_OFF;
   end
   //----------------------------------------------------------------

   current_state[FINISH_OFF_BIT]: 
   begin

      ascii_state = "FINISH_OFF";


      next_A = AA + A;
      next_B = BB + B;
      next_C = CC + C;
      next_D = DD + D;

      next_state = TURN_ARND;
   end
   //----------------------------------------------------------------

   // One cycle for making the system to come to reset state
   current_state[TURN_ARND_BIT]: 
   begin

      ascii_state = "TURN_ARND";


      next_state = IDLE;
   end
 
   endcase 
end

//--------------------------------
//
// Flops and other combinatorial 
// logic definition
//
//--------------------------------

// Outputs
assign msg_output = {{A[24:31], A[16:23], A[8:15], A[0:7]}
                    ,{B[24:31], B[16:23], B[8:15], B[0:7]}
		    ,{C[24:31], C[16:23], C[8:15], C[0:7]}
		    ,{D[24:31], D[16:23], D[8:15], D[0:7]}};
always @(posedge clk)
   msg_out_valid <= current_state[FINISH_OFF_BIT];

assign ready = current_state[IDLE_BIT];

// Internal scratch pads
always @(posedge clk) 
   if (next_state[IDLE_BIT]) begin
      AA <= 32'h0;
      BB <= 32'h0;
      CC <= 32'h0;
      DD <= 32'h0;
   end
   else if (next_state[ROUND1_BIT] && current_state[IDLE_BIT]) begin
      AA <= A;
      BB <= B;
      CC <= C;
      DD <= D;
   end

always @(posedge clk) 
   if (next_state[IDLE_BIT]) 
      msg_appended <= 512'h0;
   else if (next_state[ROUND1_BIT] && current_state[IDLE_BIT]) begin
      msg_appended <= ((8'h80 << msg_in_width) | msg_in)  
                    | ((64'h0 | msg_in_width) << 448);
   end

// Initialize A, B, C and D and then compute them
always @(posedge clk) 
   if (reset 
   ||  next_state[IDLE_BIT]) begin 
      A <= SALTA;
      B <= SALTB;
      C <= SALTC;
      D <= SALTD;
   end
   else begin
      A <= next_A;
      B <= next_B;
      C <= next_C;
      D <= next_D;
   end

// Determine one of the 16 phases within each round
always @(posedge clk)
   if (reset) 
      phase <= 4'b0;
   else if (next_state[ROUND1_BIT] && current_state[IDLE_BIT])
      phase <= 4'b0;
   else 
      phase <= phase + 4'b1;

// Assign current_state based on reset and the next_state
always @(posedge clk)
   if (reset) 
      current_state <= IDLE;
   else 
      current_state <= next_state;
 
 
 


endmodule

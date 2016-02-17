//MD5 ROUND 2

// ((A + G + X[k] + T[i]) << s) + B

module round2(aout,bout,cout,dout,a,b,c,d,msg,shift,t);
input [31:0] a, b, c, d, msg, t;
input [4:0]shift;
output [31:0] aout, bout, cout, dout;

wire [31:0] g, g1, dn, g2, tmp, tmp2,tmp3,tmp4, tmp0;


//Calculate G value
//G = (B & D) | (C & ~D)
assign g1[31:0] = b[31:0] & d[31:0];
assign dn[31:0] = ~d[31:0];
assign g2[31:0] = c[31:0] & dn[31:0];
assign g[31:0] = g1[31:0] | g2[31:0];

//Add (using 32 bit adder)
adder32 a32_0(tmp0[31:0], a[31:0], g[31:0]);
adder32 a32_1(tmp[31:0], tmp0[31:0], msg[31:0]);

adder32 a32_2(tmp2[31:0], tmp[31:0], t[31:0]);

//Shift (Use bit mapping?)
shift sh(tmp3[31:0],tmp2[31:0],shift[4:0]);

//Add with B(using 32 bit adder)
adder32 a32_3(tmp4[31:0],b[31:0],tmp3[31:0]);


assign bout[31:0] = tmp4[31:0];
assign cout[31:0] = b[31:0];
assign dout[31:0] = c[31:0];
assign aout[31:0] = d[31:0];


endmodule 
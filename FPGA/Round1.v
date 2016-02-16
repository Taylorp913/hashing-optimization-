//MD5 ROUND 1

// ((A + F + X[k] + T[i]) << s) + B

module round1(aout,bout,cout,dout,a,b,c,d,msg,shift,t);
input [31:0] a, b, c, d, msg, t;
input [4:0]shift;
output [31:0] aout, bout, cout, dout;

wire [31:0] f, f1, bn, f2, tmp, tmp2,tmp3,tmp4, tmp0;


//Calculate F value
//F = (B & C) | (~B & D)
/*and and1(f1[31:0],b[31:0],c[31:0]);
not not1(bn[31:0],b[31:0]);
and and2(f2[31:0],bn[31:0],d[31:0]);
or or1(f[31:0],f1[31:0],f2[31:0]);*/
assign f1[31:0] = b[31:0] & c[31:0];
assign bn[31:0] = ~b[31:0];
assign f2[31:0] = bn[31:0] & d[31:0];
assign f[31:0] = f1[31:0] | f2[31:0];

//Add (using 32 bit adder)
adder32 a32_0(tmp0[31:0], a[31:0], f[31:0]);
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
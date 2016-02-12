
#include "immintrin.h"
#include "emmintrin.h"
#include <stdio.h>
#include <stdlib.h>
// #define setavx _mm256_setr_epi32
__m128i t1,t2,t3;

int s[64] = {
    7, 12, 17, 22,  7, 12, 17, 22,
    7, 12, 17, 22,  7, 12, 17, 22,
    
    5, 9, 14, 20,  5, 9, 14, 20,
    5, 9, 14, 20,  5, 9, 14, 20,
    
    4, 11, 16, 23,  4, 11, 16, 23,
    4, 11, 16, 23,  4, 11, 16, 23,
    
    6, 10, 15, 21,  6, 10, 15, 21,
    6, 10, 15, 21,  6, 10, 15, 21
};

#define F(x,y,z) ((x & y) | (~x & z))
// #define F(x,y,z)\
// // _mm_and_si128(x,y);\
// // _mm_andnot_si128(x,z);\
// _mm_or_si128(_mm_and_si128(x,y),_mm_andnot_si128(x,z));

// #define G(x, y, z) ((x & z) | (y & ~z))
// #define H(x, y, z) ((x ^ y ^ z))
// #define I(x, y, z) ((y ^ (x | ~z)))
#define SHIFT(a,s) ((a << s) | (a >> (32 - s)))

// #define FF(a, b, c, d, m, s, t)\
// a = (a + F(b, c, d) + m + t);\
// a = (SHIFT(a, s));\
// a = (b + a);

// __m256i avx_set(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g, uint32_t h) {
    
//     __m256i ax = _mm256_setr_epi32(a,b,c,d,e,f,g,h);

//     return ax;
// }

#define JJS(a,s,k,l,m,n,o,p,q,r)\
  k = a[0]; l = a[1]; m = a[2]; n = a[3]; o = a[4]; p = a[5]; q = a[6]; r = a[7];\
  SHIFT(k,s);\
  SHIFT(l,s);\
  SHIFT(m,s);\
  SHIFT(n,s);\
  SHIFT(o,s);\
  SHIFT(p,s);\
  SHIFT(q,s);\
  SHIFT(r,s);\
  k = SHIFT(k, S[0]); l = SHIFT(l, S[0]); m = SHIFT(m, S[0]); n = SHIFT(n, S[0]);\
  o = SHIFT(o, S[0]); p = SHIFT(p, S[0]); q = SHIFT(q, S[0]); r = SHIFT(r, S[0]);\
  a = avx_set(k,l,m,n,o,p,q,r);

// #define JJ(a,b,c,d,g,s,t,k,l,m,n,o,p,q,r)\
// a = (a + F(b, c, d) + g + t);\
// a = JJS(a,s,k,l,m,n,o,p,q,r);\
// // a = (b + H);

#define FF(a, b, c, d, m, s, t)\
a = (a + F(b, c, d) + m + t);\
a = (SHIFT(a, s));\
a = (b + a);



int main() {

  __m128i f1,f2,f3,f4,f5,f6,f7,f8,f9,f0;
  __m128i hd1,hd2,hd3,hd4,hd5,hd6,hd7,hd8,hd9;
  __m128i z1;
  
  __m128i a = _mm_setr_epi32(0x67452301,0x67452301,0x67452301,0x67452301);
  __m128i b = _mm_setr_epi32(0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89);
  __m128i c = _mm_setr_epi32(0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe);
  __m128i d = _mm_setr_epi32(0x10325476,0x10325476,0x10325476,0x10325476);
  __m128i t = _mm_setr_epi32(0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478);
  __m128i m = _mm_setr_epi32(0x61616161,0x62616161,0x63616161,0x64616161);

  __m128i z = _mm_setr_epi32(32,32,32,32);
  __m128i x0 = _mm_setr_epi32(7,7,7,7);
  __m128i s0 = _mm_setr_epi32(1,1,1,1);

  // hd1 = F(b,c,d);
  // hd2 = (a + hd1 + msg[0] + T[0]);
  // hd3 = (hd2 << S[0]);
  // hd4 = (hd2 >> (32 - S[0]));
  // hd5 = hd3 | hd4;
  // hd6 = hd5 + b;
  // hd7 = SHIFT(hd2, S[0]);
  // hd8 = (hd7 + b);

  f1 = _mm_and_si128(b,c);
  f2 = _mm_andnot_si128(b,d);
  f3 = _mm_or_si128(f1,f2);

  f4 = _mm_add_epi32(a,f3);
  f5 = _mm_add_epi32(m,t);
  f6 = _mm_add_epi32(f4,f5);

  f7 = _mm_slli_epi32(f6,s[0]);
  f8 = _mm_srli_epi32(f6,(32-s[0]));
  f9 = _mm_or_si128(f7,f8);

  f0 = _mm_add_epi32(f9,b);

  hd1 = F(b,c,d);
  hd2 = (a + hd1 + m +t);

  // hd1 = (b & c);
  // hd2 = (~b & d);
  // hd3 = hd1 | hd2;
  // hd4 = (a + hd3 + m + t);

  int* res0 = (int*)&hd4;
  printf("hd4 =  %x %x %x %x\n",res0[0],res0[1],res0[2],res0[3]);
  int* res1 = (int*)&a;
  printf("a =  %x %x %x %x\n",res1[0],res1[1],res1[2],res1[3]);
  int* res2 = (int*)&m;
  printf("m =  %x %x %x %x\n",res2[0],res2[1],res2[2],res2[3]);
  int* res3 = (int*)&f3;
  printf("f3 =  %x %x %x %x\n",res3[0],res3[1],res3[2],res3[3]);
  int* res4 = (int*)&f4;
  printf("f4 =  %x %x %x %x\n",res4[0],res4[1],res4[2],res4[3]);
  int* res5 = (int*)&f5;
  printf("f5 =  %x %x %x %x\n",res5[0],res5[1],res5[2],res5[3]);
  int* res6 = (int*)&f6;
  printf("f6 =  %x %x %x %x\n",res6[0],res6[1],res6[2],res6[3]);
  int* res7 = (int*)&f7;
  printf("f7 =  %x %x %x %x\n",res7[0],res7[1],res7[2],res7[3]);
  int* res8 = (int*)&f8;
  printf("f8 =  %x %x %x %x\n",res8[0],res8[1],res8[2],res8[3]);
  int* res9 = (int*)&f9;
  printf("f9 =  %x %x %x %x\n",res9[0],res9[1],res9[2],res9[3]);
  int* res10 = (int*)&f0;
  printf("f10 =  %x %x %x %x\n",res10[0],res10[1],res10[2],res10[3]);
  int* res11 = (int*)&hd1;
  printf("hd1 =  %x %x %x %x\n",res11[0],res11[1],res11[2],res11[3]);
  int* res12 = (int*)&hd2;
  printf("hd2 =  %x %x %x %x\n",res12[0],res12[1],res12[2],res12[3]);
  int* res13 = (int*)&hd3;
  printf("hd3 =  %x %x %x %x\n",res13[0],res13[1],res13[2],res13[3]);
  int* res14 = (int*)&hd4;
  printf("hd4 =  %x %x %x %x\n",res14[0],res14[1],res14[2],res14[3]);
  int* res15 = (int*)&hd3;
  printf("hd3 =  %x %x %x %x\n",res15[0],res15[1],res15[2],res15[3]);
  

  // printf("b = %x %x %x %x\n",b[0],b[1],b[2],b[3]);
  // printf("c = %x %x %x %x\n",c[0],c[1],c[2],c[3]);
  // printf("d = %x %x %x %x\n",d[0],d[1],d[2],d[3]);
  // printf("T = %x %x %x %x\n",T[0],T[1],T[2],T[3]);
  // printf("m = %x %x %x %x\n",m[0],m[1],m[2],m[3]);
  // printf("f1 = %x %x %x %x\n",f1[0],f1[1],f1[2],f1[3]);
  // printf("f2 = %x %x %x %x\n",f2[0],f2[1],f2[2],f2[3]);
  // printf("f3 = %x %x %x %x\n",f3[0],f3[1],f3[2],f3[3]);






  
  // printf("a = %llx %llx %llx %llx %llx %llx %llx %llx\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
  // printf("b = %llx %llx %llx %llx %llx %llx %llx %llx\n",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]);
  // printf("c = %llx %llx %llx %llx %llx %llx %llx %llx\n",c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7]);
  // printf("d = %llx %llx %llx %llx %llx %llx %llx %llx\n",d[0],d[1],d[2],d[3],d[4],d[5],d[6],d[7]);
  // printf("T = %llx %llx %llx %llx %llx %llx %llx %llx\n",T[0],T[1],T[2],T[3],T[4],T[5],T[6],T[7]);
  // printf("m = %llx %llx %llx %llx %llx %llx %llx %llx\n",m[0],m[1],m[2],m[3],m[4],m[5],m[6],m[7]);
  // printf("a = %llx %llx %llx %llx\n",a[0],a[1],a[2],a[3]);
  // printf("b = %llx %llx %llx %llx\n",b[0],b[1],b[2],b[3]);
  // printf("c = %llx %llx %llx %llx\n",c[0],c[1],c[2],c[3]);
  // printf("d = %llx %llx %llx %llx\n",d[0],d[1],d[2],d[3]);
  // printf("T = %llx %llx %llx %llx\n",T[0],T[1],T[2],T[3]);
  // printf("m = %llx %llx %llx %llx\n",m[0],m[1],m[2],m[3]);
  // #define FF(a, b, c, d, m, s, t)\
  // l = (a + F(b, c, d) + m + t);\
  // l1 = (SHIFT(l, s));\
  // l2 = (b + l1);

  //__m256i out = ((b & c) | (~b & d));
  // out1 = (b & c);
  // out2 = (~b & d);
  // hd1 = out1 | out2;

  // int* res1 = (int*)&hd1;
  // printf("hd1 =  %x %x %x %x %x %x %x %x\n",res1[0],res1[1],res1[2],res1[3],res1[4],res1[5],res1[6],res1[7]);

  // #define FF11(a, b, c, d, m, s, t)\
  // a = (a + F(b, c, d) + m + t);\
  // p = _mm256_setr_epi32(SHIFT(l[0],s),SHIFT(l[1],s),SHIFT(l[2],s),SHIFT(l[3],s),SHIFT(l[4],s),SHIFT(l[5],s),SHIFT(l[6],s),SHIFT(l[7],s));\
  // a = (b + p);


  // Sf = (a + F(b,c,d) + n + T);
  // //int* res1 = (int*)&Sf;
  // //printf("Sf_old: %x %x %x %x %x %x %x %x\n",res1[0],res1[1],res1[2],res1[3],res1[4],res1[5],res1[6],res1[7]);

  // as0 = Sf[0]; as1 = Sf[1]; as2 = Sf[2]; as3 = Sf[3]; as4 = Sf[4]; as5 = Sf[5]; as6 = Sf[6]; as7 = Sf[7];
  // s0 = SHIFT(as0, S[0]); s1 = SHIFT(as1, S[0]); s2 = SHIFT(as2, S[0]); s3 = SHIFT(as3, S[0]);
  // s4 = SHIFT(as4, S[0]); s5 = SHIFT(as5, S[0]); s6 = SHIFT(as6, S[0]); s7 = SHIFT(as7, S[0]);
  // Sf = _mm256_setr_epi32(s0,s1,s2,s3,s4,s5,s6,s7);
  // //Sf = _mm256_setr_epi32(SHIFT(as0[0],S[0]),SHIFT(as1[1],S[0]),SHIFT(as2[2],S[0]),SHIFT(as3[3],S[0]),SHIFT(as4[4],S[0]),SHIFT(as5[5],S[0]),SHIFT(as6[6],S[0]),SHIFT(as7[7],S[0]));
  // int* res2 = (int*)&Sf;
  // printf("Sf_new: %x %x %x %x %x %x %x %x\n",res2[0],res2[1],res2[2],res2[3],res2[4],res2[5],res2[6],res2[7]);

  // hd5 = F(b,c,d);
  // printf("hd5_vector = %llx %llx %llx %llx %llx %llx %llx %llx\n",hd5[0],hd5[1],hd5[2],hd5[3],hd5[4],hd5[5],hd5[6],hd5[7]);
  // int* res2 = (int*)&hd5;
  // printf("hd5 =  %x %x %x %x %x %x %x %x\n",res2[0],res2[1],res2[2],res2[3],res2[4],res2[5],res2[6],res2[7]);

  // hd2 = (a + hd5 + m + T);
  // int* resG = (int*)&hd2;
  // printf("hd2 = %x %x %x %x %x %x %x %x\n",resG[0],resG[1],resG[2],resG[3],resG[4],resG[5],resG[6],resG[7]);

  // //int* res2f;
  // //res2f[0] = SHIFT(resG[0], S[0]); res2f[1] = SHIFT(resG[1], S[0]); res2f[2] = SHIFT(resG[2], S[0]); res2f[3] = SHIFT(resG[3], S[0]);
  // //res2f[4] = SHIFT(resG[4], S[0]); res2f[5] = SHIFT(resG[5], S[0]); res2f[6] = SHIFT(resG[6], S[0]); res2f[7] = SHIFT(resG[7], S[0]);
  // resG[0] = SHIFT(resG[0], S[0]); resG[1] = SHIFT(resG[1], S[0]); resG[2] = SHIFT(resG[2], S[0]); resG[3] = SHIFT(resG[3], S[0]);
  // resG[4] = SHIFT(resG[4], S[0]); resG[5] = SHIFT(resG[5], S[0]); resG[6] = SHIFT(resG[6], S[0]); resG[7] = SHIFT(resG[7], S[0]);
  // printf("resG = %x %x %x %x %x %x %x %x\n",resG[0],resG[1],resG[2],resG[3],resG[4],resG[5],resG[6],resG[7]);

  // resG[0] = hd2[0]; resG[1] = hd2[1]; resG[2] = hd2[2]; resG[3] = hd2[3]; resG[4] = hd2[4]; resG[5] = hd2[5]; resG[6] = hd2[6]; resG[7 = hd2[7];
  // printf("res2f[0] = %x\n", res2f[0]);
  // printf("res2f[1] = %x\n", res2f[1]);
  // printf("res2f[2] = %x\n", res2f[2]);
  // printf("res2f[3] = %x\n", res2f[3]);
  // printf("res2f[4] = %x\n", res2f[4]);
  // printf("res2f[5] = %x\n", res2f[5]);
  // printf("res2f[6] = %x\n", res2f[6]);
  // printf("res2f[7] = %x\n", res2f[7]);

  // as0 = hd2[0]; as1 = hd2[1]; as2 = hd2[2]; as3 = hd2[3]; as4 = hd2[4]; as5 = hd2[5]; as6 = hd2[6]; as7 = hd2[7];
  // as0 = SHIFT(as0, S[0]); as1 = SHIFT(as1, S[0]); as2 = SHIFT(as2, S[0]); as3 = SHIFT(as3, S[0]);
  // as4 = SHIFT(as4, S[0]); as5 = SHIFT(as5, S[0]); as6 = SHIFT(as6, S[0]); as7 = SHIFT(as7, S[0]);

  // s0 = SHIFT(as0, S[0]); s1 = SHIFT(as1, S[0]); s2 = SHIFT(as2, S[0]); s3 = SHIFT(as3, S[0]);
  // s4 = SHIFT(as4, S[0]); s5 = SHIFT(as5, S[0]); s6 = SHIFT(as6, S[0]); s7 = SHIFT(as7, S[0]);

  // printf("as0 = %x\n", as0);
  // printf("as1 = %x\n", as1);
  // printf("as2 = %x\n", as2);
  // printf("as3 = %x\n", as3);
  // printf("as4 = %x\n", as4);
  // printf("as5 = %x\n", as5);
  // printf("as6 = %x\n", as6);
  // printf("as7 = %x\n", as7);

  // printf("s0 = %x\n", s0);
  // printf("s1 = %x\n", s1);
  // printf("s2 = %x\n", s2);
  // printf("s3 = %x\n", s3);
  // printf("s4 = %x\n", s4);
  // printf("s5 = %x\n", s5);
  // printf("s6 = %x\n", s6);
  // printf("s7 = %x\n", s7);


  // printf("as0_1st = %x\n", as0);
  // printf("s0_1st = %x\n", s0);
  // hd3 = _mm256_setr_epi32(as0,as1,as2,as3,as4,as5,as6,as7);
  // hd3 = _mm256_setr_epi32(s0,s1,s2,s3,s4,s5,s6,s7);
  
  //Sf = _mm256_setr_epi32(SHIFT(as0, S[0]),SHIFT(as1, S[0]),SHIFT(as2, S[0]),SHIFT(as3, S[0]),SHIFT(as4, S[0]),SHIFT(as5, S[0]),SHIFT(as6, S[0]),SHIFT(as7, S[0]));
  
  // hd4 = b + hd3;

  // F1 = JJS(a,S[0],s0,s1,s2,s3,s4,s5,s6,s7);
  // int* resH = (int*)&hd4;
  // printf("hd4 = %x %x %x %x %x %x %x %x\n",resH[0],resH[1],resH[2],resH[3],resH[4],resH[5],resH[6],resH[7]);
  // // f2 = JJS(a,S[0],s0,s1,s2,s3,s4,s5,s6,s7);
  // // f1 = JJ(a,b,c,d,m,S[0],T,s0,s1,s2,s3,s4,s5,s6,s7);
  // // int* resH = (int*)&f1;
  // // printf("f1 = %x\n", resH[0]);
  // // int* resH = (int*)&F1;
  // // printf("F1 = %x\n", resH[0]);
  // int* res3 = (int*)&F1;
  // printf("F1 = %x %x %x %x %x %x %x %x\n",res3[0],res3[1],res3[2],res3[3],res3[4],res3[5],res3[6],res3[7]);

    // tot = (bi & ci);
    // printf("Hex value 'b': %x\n",bi);
    // printf("Int value 'b': %u\n",bi);
    // printf("Hex value 'c': %x\n",ci);
    // printf("Int value 'c': %u\n",ci);
    // printf("Hex total: %x\n",tot);
    // printf("Int total: %u\n",tot);

  // __m256i a = _mm256_setr_epi32(0x67452301,0x67452301,0x67452301,0x67452301,0x67452301,0x67452301,0x67452301,0x67452301);
  // __m256i b = _mm256_setr_epi32(0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89);
  // __m256i c = _mm256_setr_epi32(0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe);
  // __m256i d = _mm256_setr_epi32(0x10325476,0x10325476,0x10325476,0x10325476,0x10325476,0x10325476,0x10325476,0x10325476);
  // __m256i T = _mm256_setr_epi32(0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478);
  // __m256i H = _mm256_setr_epi32(0,0,0,0,0,0,0,0);
  // __m256i m = _mm256_setr_epi32(0x61616161,0x62616161,0x63616161,0x64616161,0x65616161,0x66616161,0x67616161,0x68616161);


  // int* res3 = (int*)&f1;
  // printf("f1 = = : %x %x %x %x %x %x %x %x\n",res3[0],res3[1],res3[2],res3[3],res3[4],res3[5],res3[6],res3[7]);

  // printf("as0_2nd = %x\n", as0);
  // printf("s0_2nd = %x\n", s0);
  
  // int* resG = (int*)&Sf;
  // printf("m = %x %x %x %x %x %x %x %x\n",resG[0],resG[1],resG[2],resG[3],resG[4],resG[5],resG[6],resG[7]);
  // int* resH = (int*)&n;
  // printf("n = %x\n", resH[0]);
  // int* resK = (int*)&m;
  // printf("m = %x\n", resK[0]);
  // //printf("n = %x %x %x %x %x %x %x %x\n",resH[0],resH[1],resH[2],resH[3],resH[4],resH[5],resH[6],resH[7]);
  // int* resE = (int*)&T;
  // printf("T = %x\n", resE[0]);
  // printf("S[0] = %x\n", S[0]);
  // int* resF = (int*)&a;
  // printf("a = %x\n", resF[0]);

  // int* resI = (int*)&Sf;
  // printf("Sf = %x\n", resI[0]);
  // int* resD = (int*)&hd1;
  // printf("hd1 = %x\n", resD[0]);
  // int* resA = (int*)&hd2;
  // printf("hd2 = %x\n", resA[0]);
  // int* resB = (int*)&hd3;
  // printf("hd3 = %x\n", resB[0]);
  // int* resC = (int*)&hd4;
  // printf("hd4 = %x\n", resC[0]);

  //FF(a, b, c, d, m, S, T);

  // int* res1 = (int*)&out1;
  // printf("Hex total: %x %x %x %x %x %x %x %x\n",res1[0],res1[1],res1[2],res1[3],res1[4],res1[5],res1[6],res1[7]);
  // printf("Int total: %i %i %i %i %i %i %i %i\n",res1[0],res1[1],res1[2],res1[3],res1[4],res1[5],res1[6],res1[7]);

  // int* res2 = (int*)&out2;
  // printf("Hex total: %x %x %x %x %x %x %x %x\n",res2[0],res2[1],res2[2],res2[3],res2[4],res2[5],res2[6],res2[7]);
  // printf("Int total: %i %i %i %i %i %i %i %i\n",res2[0],res2[1],res2[2],res2[3],res2[4],res2[5],res2[6],res2[7]);

  // int* res3 = (int*)&out3;
  // printf("Hex total out3: %x %x %x %x %x %x %x %x\n",res3[0],res3[1],res3[2],res3[3],res3[4],res3[5],res3[6],res3[7]);
  // printf("Int total out3: %i %i %i %i %i %i %i %i\n",res3[0],res3[1],res3[2],res3[3],res3[4],res3[5],res3[6],res3[7]);

  // int* res4 = (int*)&hd3;
  // printf("Hex total hd3: %x %x %x %x %x %x %x %x\n",res4[0],res4[1],res4[2],res4[3],res4[4],res4[5],res4[6],res4[7]);
  // printf("Int total hd3: %i %i %i %i %i %i %i %i\n",res4[0],res4[1],res4[2],res4[3],res4[4],res4[5],res4[6],res4[7]);

  //printf("s0: %i\n",s0);

  // __m256i a = _mm256_set1_epi32(0x67452301);
  // __m256i b = _mm256_set1_epi32(0xefcdab89);
  // __m256i c = _mm256_set1_epi32(0x98badcfe);
  // __m256i d = _mm256_set1_epi32(0x10325476);
  // __m256i T = _mm256_set1_epi32(0xd76aa478);
  // __m256i S = _mm256_set1_epi32(7);

  // __m256i a = (b & c);

  // float* resA = (float*)&a;
  // printf("%lf\n", resA[0]);
  // printf("%x\n", resA[0]);

  // printf("Hex value 'b[0]': %lli\n",b[0]);
  // printf("Int value 'b[0]': %lli\n",b[0]);
  // printf("Hex value 'c[0]': %llx\n",c[0]);
  // printf("Int value 'c[0]': %lli\n",c[0]);


  // float* res = (float*)&c;
  // printf("%lf %lf %lf %lf %lf %lf %lf %lf\n", res[0], res[1], res[2], res[3], res[4], res[5], res[6], res[7]);
  

  
  return 0;
}



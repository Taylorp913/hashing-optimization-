//
//  md5.h
//  md5_project
//
//  Created by Danny Froerer on 2/1/16.
//  Copyright © 2016 Danny Froerer. All rights reserved.
//

#ifndef md5_h
#define md5_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "immintrin.h"

#define input1 0x453e41d218e071cc//zzzzzz
#define input2 0xfb2d1c99ce23906a

//constructore for input data type
union Guess
{
	uint8_t   _8[64];
	uint32_t  _32[16];
	uint64_t  _64[8];
};
#define alph(a) ('a'+a)
void guess_print(union Guess *guess) {
	int idx;
	printf("%c", guess->_8[0]);
	printf("%c", guess->_8[1]);
	printf("%c", guess->_8[2]);
	printf("%c", guess->_8[3]);
	printf("%c", guess->_8[4]);
	printf("%c", guess->_8[5]);
	printf("%c", guess->_8[6]);
	printf("%c", guess->_8[7]);
	printf("\n");
}
//The increment value for each alpha character in the password 1-26
#define  I1 (uint64_t) 26
#define  I2 (uint64_t) 676
#define  I3 (uint64_t) 17576
#define  I4 (uint64_t) 456976
#define  I5 (uint64_t) 11881376

// Digit5 = E5+E4
#define  Digit5 (uint64_t) 12356630
#define  Digit6 (uint64_t) 321272406

#define  tbegin_1 (uint64_t) 12356630
#define  tstop_1 (uint64_t) 89585574
#define  tbegin_2 (uint64_t) 89585574
#define  tstop_2 (uint64_t) 166814518
#define  tbegin_3 (uint64_t) 166814518
#define  tstop_3 (uint64_t) 244043462
#define  tbegin_4 (uint64_t) 244043462
#define  tstop_4 (uint64_t) 321272406

void increment_pass(union Guess *guess, uint64_t i)
{
	guess->_8[0] = alph((i - Digit5) % I1);
	guess->_8[1] = alph((((i - Digit5) / I1) % I1));
	guess->_8[2] = alph((((i - Digit5) / I2) % I1));
	guess->_8[3] = alph((((i - Digit5) / I3) % I1));
	guess->_8[4] = alph((((i - Digit5) / I4) % I1));
	guess->_8[5] = alph((((i - Digit5) / I5) % I1));
	guess->_8[6] = 0x80;
	memset(&guess->_8[7], 0, 56); //Pad
	guess->_64[7] = 6 * 8; //length * 8 
}

#define transform_input( a,  b) {\
        input._8[0] = (a>> 56) &0xff;\
        input._8[1] = (a>> 48) &0xff;\
        input._8[2] = (a>> 40) &0xff;\
        input._8[3] = (a>> 32) &0xff;\
        input._8[4] = (a>> 24) &0xff;\
        input._8[5] = (a>> 16) &0xff;\
        input._8[6] = (a>>  8) &0xff;\
        input._8[7] = (a     ) &0xff;\
        input._8[8] = (b>> 56) &0xff;\
        input._8[9] = (b>> 48) &0xff;\
        input._8[10] = (b>> 40) &0xff;\
        input._8[11] = (b>> 32) &0xff;\
        input._8[12] = (b>> 24) &0xff;\
        input._8[13] = (b>> 16) &0xff;\
        input._8[14] = (b>>  8) &0xff;\
        input._8[15] = (b     ) &0xff;}

#define alpha 26;

// Initial first block values
uint32_t ai = 0x67452301;
uint32_t bi = 0xefcdab89;
uint32_t ci = 0x98badcfe;
uint32_t di = 0x10325476;

#define F(x, y, z) ((x & y) | (~x & z))
#define G(x, y, z) ((x & z) | (y & ~z))
#define H(x, y, z) ((x ^ y ^ z))
#define I(x, y, z) ((y ^ (x | ~z)))
//#define SHIFT(a, s) ((a << s) | (a >> (32 - s)))
#define SHIFT(x,s){\
  x = _mm256_setr_epi32(\
    (((uint32_t*)&x)[0]<<s) | (((uint32_t*)&x)[0]>>(32-s)),\
    0,\
    (((uint32_t*)&x)[2]<<s) | (((uint32_t*)&x)[2]>>(32-s)),\
    0,\
    (((uint32_t*)&x)[4]<<s) | (((uint32_t*)&x)[4]>>(32-s)),\
    0,\
    (((uint32_t*)&x)[6]<<s) | (((uint32_t*)&x)[6]>>(32-s)),\
    0);}


#define FF(a, b, c, d, m, s, t)\
a = (a + F(b, c, d) + m + t);\
a = (SHIFT(a, s));\
a = (b + a);

#define GG(a, b, c, d, m, s, t) \
a = (a + G(b, c, d) + m + t); \
a = (SHIFT(a, s)); \
a = (b + a); \


#define HH(a, b, c, d, m, s, t) \
a = (a + H(b, c, d) + m + t); \
a = (SHIFT(a, s)); \
a = (b + a); \


#define II(a, b, c, d, m, s, t) \
a = (a + I(b, c, d) + m + t); \
a = (SHIFT(a, s)); \
a = (b + a); \


uint32_t T[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,

	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,

	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,

	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};

// All the 's' values for the 4 rounds
int S[64] = {
	7, 12, 17, 22,  7, 12, 17, 22,
	7, 12, 17, 22,  7, 12, 17, 22,

	5, 9, 14, 20,  5, 9, 14, 20,
	5, 9, 14, 20,  5, 9, 14, 20,

	4, 11, 16, 23,  4, 11, 16, 23,
	4, 11, 16, 23,  4, 11, 16, 23,

	6, 10, 15, 21,  6, 10, 15, 21,
	6, 10, 15, 21,  6, 10, 15, 21
};


void md5_manipulate(union Guess *md5, union Guess *gss,union Guess *gss2,union Guess *gss3,union Guess *gss4) {

	__m256i a = _mm256_set1_epi32(0x67452301);
    __m256i b = _mm256_set1_epi32(0xEFCDAB89);
    __m256i c = _mm256_set1_epi32(0x98BADCFE);
    __m256i d = _mm256_set1_epi32(0x10325476);


    __m256i avx0= _mm256_setr_epi32(gss->_32[0], 0, gss2->_32[0], 0, gss3->_32[0], 0, gss4->_32[0], 0);
    __m256i avx1= _mm256_setr_epi32(gss->_32[1], 0, gss2->_32[1], 0, gss3->_32[1], 0, gss4->_32[1], 0);
    __m256i avx2= _mm256_setr_epi32(gss->_32[2], 0, gss2->_32[2], 0, gss3->_32[2], 0, gss4->_32[2], 0);
    __m256i avx3= _mm256_setr_epi32(gss->_32[3], 0, gss2->_32[3], 0, gss3->_32[3], 0, gss4->_32[3], 0);
    __m256i avx4= _mm256_setr_epi32(gss->_32[4], 0, gss2->_32[4], 0, gss3->_32[4], 0, gss4->_32[4], 0);
    __m256i avx5= _mm256_setr_epi32(gss->_32[5], 0, gss2->_32[5], 0, gss3->_32[5], 0, gss4->_32[5], 0);
    __m256i avx6= _mm256_setr_epi32(gss->_32[6], 0, gss2->_32[6], 0, gss3->_32[6], 0, gss4->_32[6], 0);
    __m256i avx7= _mm256_setr_epi32(gss->_32[7], 0, gss2->_32[7], 0, gss3->_32[7], 0, gss4->_32[7], 0);
    __m256i avx8= _mm256_setr_epi32(gss->_32[8], 0, gss2->_32[8], 0, gss3->_32[8], 0, gss4->_32[8], 0);
    __m256i avx9= _mm256_setr_epi32(gss->_32[9], 0, gss2->_32[9], 0, gss3->_32[9], 0, gss4->_32[9], 0);
    __m256i avx10= _mm256_setr_epi32(gss->_32[10], 0, gss2->_32[10], 0, gss3->_32[10], 0, gss4->_32[10], 0);
    __m256i avx11= _mm256_setr_epi32(gss->_32[11], 0, gss2->_32[11], 0, gss3->_32[11], 0, gss4->_32[11], 0);
    __m256i avx12= _mm256_setr_epi32(gss->_32[12], 0, gss2->_32[12], 0, gss3->_32[12], 0, gss4->_32[12], 0);
    __m256i avx13= _mm256_setr_epi32(gss->_32[13], 0, gss2->_32[13], 0, gss3->_32[13], 0, gss4->_32[13], 0);
    __m256i avx14= _mm256_setr_epi32(gss->_32[14], 0, gss2->_32[14], 0, gss3->_32[14], 0, gss4->_32[14], 0);
    __m256i avx15= _mm256_setr_epi32(gss->_32[15], 0, gss2->_32[15], 0, gss3->_32[15], 0, gss4->_32[15], 0);

	FF(a, b, c, d, avx0, 7,	_mm256_set1_epi32(0xd76aa478));
	FF(d, a, b, c, avx1, 12,	_mm256_set1_epi32(0xe8c7b756));
	FF(c, d, a, b, avx2, 17,	_mm256_set1_epi32(0x242070db));
	FF(b, c, d, a, avx3, 22,	_mm256_set1_epi32(0xc1bdceee));
	FF(a, b, c, d, avx4, 7,	_mm256_set1_epi32(0xf57c0faf));
	FF(d, a, b, c, avx5, 12,	_mm256_set1_epi32(0x4787c62a));
	FF(c, d, a, b, avx6, 17,	_mm256_set1_epi32(0xa8304613));
	FF(b, c, d, a, avx7, 22,	_mm256_set1_epi32(0xfd469501));
	FF(a, b, c, d, avx8, 7,	_mm256_set1_epi32(0x698098d8));
	FF(d, a, b, c, avx9, 12,	_mm256_set1_epi32(0x8b44f7af));
	FF(c, d, a, b, avx10,	17,	_mm256_set1_epi32(0xffff5bb1));
	FF(b, c, d, a, avx11,	22,	_mm256_set1_epi32(0x895cd7be));
	FF(a, b, c, d, avx12,	7,	_mm256_set1_epi32(0x6b901122));
	FF(d, a, b, c, avx13,	12,	_mm256_set1_epi32(0xfd987193));
	FF(c, d, a, b, avx14,	17,	_mm256_set1_epi32(0xa679438e));
	FF(b, c, d, a, avx15,	22,	_mm256_set1_epi32(0x49b40821));

	GG(a, b, c, d, avx1, 	S[16], 	_mm256_set1_epi32(0xf61e2562));
	GG(d, a, b, c, avx6, 	S[17], 	_mm256_set1_epi32(0xc040b340));
	GG(c, d, a, b, avx11,	S[18], 	_mm256_set1_epi32(0x265e5a51));
	GG(b, c, d, a, avx0, 	S[19], 	_mm256_set1_epi32(0xe9b6c7aa));
	GG(a, b, c, d, avx5, 	S[20], 	_mm256_set1_epi32(0xd62f105d));
	GG(d, a, b, c, avx10,	S[21], 	_mm256_set1_epi32(0x02441453));
	GG(c, d, a, b, avx15,	S[22], 	_mm256_set1_epi32(0xd8a1e681));
	GG(b, c, d, a, avx4, 	S[23], 	_mm256_set1_epi32(0xe7d3fbc8));
	GG(a, b, c, d, avx9, 	S[24], 	_mm256_set1_epi32(0x21e1cde6));
	GG(d, a, b, c, avx14,	S[25], 	_mm256_set1_epi32(0xc33707d6));
	GG(c, d, a, b, avx3, 	S[26], 	_mm256_set1_epi32(0xf4d50d87));
	GG(b, c, d, a, avx8, 	S[27], 	_mm256_set1_epi32(0x455a14ed));
	GG(a, b, c, d, avx13,	S[28], 	_mm256_set1_epi32(0xa9e3e905));
	GG(d, a, b, c, avx2, 	S[29], 	_mm256_set1_epi32(0xfcefa3f8));
	GG(c, d, a, b, avx7, 	S[30], 	_mm256_set1_epi32(0x676f02d9));
	GG(b, c, d, a, avx12,	S[31], 	_mm256_set1_epi32(0x8d2a4c8a));

	HH(a, b, c, d, avx5, 	S[32], 	_mm256_set1_epi32(0xfffa3942));
	HH(d, a, b, c, avx8, 	S[33], 	_mm256_set1_epi32(0x8771f681));
	HH(c, d, a, b, avx11,	S[34], 	_mm256_set1_epi32(0x6d9d6122));
	HH(b, c, d, a, avx14,	S[35], 	_mm256_set1_epi32(0xfde5380c));
	HH(a, b, c, d, avx1, 	S[36], 	_mm256_set1_epi32(0xa4beea44));
	HH(d, a, b, c, avx4, 	S[37], 	_mm256_set1_epi32(0x4bdecfa9));
	HH(c, d, a, b, avx7, 	S[38], 	_mm256_set1_epi32(0xf6bb4b60));
	HH(b, c, d, a, avx10,	S[39], 	_mm256_set1_epi32(0xbebfbc70));
	HH(a, b, c, d, avx13,	S[40], 	_mm256_set1_epi32(0x289b7ec6));
	HH(d, a, b, c, avx0, 	S[41], 	_mm256_set1_epi32(0xeaa127fa));
	HH(c, d, a, b, avx3, 	S[42], 	_mm256_set1_epi32(0xd4ef3085));
	HH(b, c, d, a, avx6, 	S[43], 	_mm256_set1_epi32(0x04881d05));
	HH(a, b, c, d, avx9, 	S[44], 	_mm256_set1_epi32(0xd9d4d039));
	HH(d, a, b, c, avx12,	S[45], 	_mm256_set1_epi32(0xe6db99e5));
	HH(c, d, a, b, avx15,	S[46], 	_mm256_set1_epi32(0x1fa27cf8));
	HH(b, c, d, a, avx2, 	S[47], 	_mm256_set1_epi32(0xc4ac5665));

	II(a, b, c, d, avx0, 	S[48], 	_mm256_set1_epi32(0xf4292244));
	II(d, a, b, c, avx7, 	S[49], 	_mm256_set1_epi32(0x432aff97));
	II(c, d, a, b, avx14,	S[50], 	_mm256_set1_epi32(0xab9423a7));
	II(b, c, d, a, avx5, 	S[51], 	_mm256_set1_epi32(0xfc93a039));
	II(a, b, c, d, avx12,	S[52], 	_mm256_set1_epi32(0x655b59c3));
	II(d, a, b, c, avx3, 	S[53], 	_mm256_set1_epi32(0x8f0ccc92));
	II(c, d, a, b, avx10,	S[54], 	_mm256_set1_epi32(0xffeff47d));
	II(b, c, d, a, avx1, 	S[55], 	_mm256_set1_epi32(0x85845dd1));
	II(a, b, c, d, avx8, 	S[56], 	_mm256_set1_epi32(0x6fa87e4f));
	II(d, a, b, c, avx15,	S[57], 	_mm256_set1_epi32(0xfe2ce6e0));
	II(c, d, a, b, avx6, 	S[58], 	_mm256_set1_epi32(0xa3014314));
	II(b, c, d, a, avx13,	S[59], 	_mm256_set1_epi32(0x4e0811a1));
	II(a, b, c, d, avx4, 	S[60], 	_mm256_set1_epi32(0xf7537e82));
	II(d, a, b, c, avx11,	S[61], 	_mm256_set1_epi32(0xbd3af235));
	II(c, d, a, b, avx2, 	S[62], 	_mm256_set1_epi32(0x2ad7d2bb));
	II(b, c, d, a, avx9, 	S[63], 	_mm256_set1_epi32(0xeb86d391));


	__m256i avxai= _mm256_setr_epi32(ai, 0, ai, 0, ai, 0, ai, 0);
	__m256i avxbi= _mm256_setr_epi32(bi, 0, bi, 0, bi, 0, bi, 0);
	__m256i avxci= _mm256_setr_epi32(ci, 0, ci, 0, ci, 0, ci, 0);
	__m256i avxdi= _mm256_setr_epi32(di, 0, di, 0, di, 0, di, 0);

	a += avxai;
	b += avxbi;
	c += avxci;
	d += avxdi; 

	uint32_t * A = (uint32_t*)&a;
	uint32_t * B = (uint32_t*)&b;
	uint32_t * C = (uint32_t*)&c;
	uint32_t * D = (uint32_t*)&d;
	
	md5->_32[0] = A[0];
	md5->_32[1] = B[0];
	md5->_32[2] = C[0];
	md5->_32[3] = D[0];
	md5->_32[4] = A[2];
	md5->_32[5] = B[2];
	md5->_32[6] = C[2];
	md5->_32[7] = D[2];
	md5->_32[8] = A[4];
	md5->_32[9] = B[4];
	md5->_32[10] = C[4];
	md5->_32[11] = D[4];
	md5->_32[12] = A[6];
	md5->_32[13] = B[6];
	md5->_32[14] = C[6];
	md5->_32[15] = D[6];

}




#endif /* md5_h */

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
#include <cstring>
#include "immintrin.h"
#include "emmintrin.h"

// Used for shorter declarations
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long


__m128i T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15;
__m128i T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31;
__m128i T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47;
__m128i T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,T58,T59,T60,T61,T62,T63;

// __m128i S0,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S14,S15;
// __m128i S16,S17,S18,S19,S20,S21,S22,S23,S24,S25,S26,S27,S28,S29,S30,S31;
// __m128i S32,S33,S34,S35,S36,S37,S38,S39,S40,S41,S42,S43,S44,S45,S46,S47;
// __m128i S48,S49,S50,S51,S52,S53,S54,S55,S56,S57,S58,S59,S60,S61,S62,S63;

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



int k[64] = {
    25, 20, 15, 10, 25, 20, 15, 10,
    25, 20, 15, 10, 25, 20, 15, 10,
    
    27, 23, 18, 12, 27, 23, 18, 12,
    27, 23, 18, 12, 27, 23, 18, 12,
    
    28, 21, 16, 9, 28, 21, 16, 9,
    28, 21, 16, 9, 28, 21, 16, 9,
    
    26, 22, 17, 11, 26, 22, 17, 11,
    26, 22, 17, 11, 26, 22, 17, 11
};

// Define struct
typedef struct {
    uchar message0[64];
    uchar message1[64];
    uchar message2[64];
    uchar message3[64];
    uint msg_len0;
    uint msg_len1;
    uint msg_len2;
    uint msg_len3;
    __m128i a,b,c,d,l,m,t;
    __m128i avxa, avxb, avxc, avxd;
    __m128i avx_hash0, avx_hash1, avx_hash2, avx_hash3;
    __m128i f1,f2,f3,f4,f5,f6,f7,f8,f9,f0;
    __m128i za,zb,zc,zd;
    __m128i avx0, avx1, avx2, avx3;
    __m128i avx4, avx5, avx6, avx7;
    __m128i avx8, avx9, avx10, avx11;
    __m128i avx12, avx13, avx14, avx15;
    __m128i T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15;
    __m128i T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31;
    __m128i T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47;
    __m128i T48,T49,T50,T51,T52,T53,T54,T55,T56,T57,T58,T59,T60,T61,T62,T63;
} MD5;


void avx_print(MD5 *md5, uchar final[]) {
    int i;
    for (i=0; i < 64; i++)
        printf("%x",final[i]);
    printf("\n");
}

void avx_print_int(unsigned int final[]) {
    int i;
    for (i=0; i < 16; i++)
        printf("%x",final[i]);
    printf("\n");
}

void avx_print_char(unsigned char final[]) {
    int i;
    for (i=0; i < 16; i++)
        printf("%x",final[i]);
    printf("\n");
}


// Initialize struct elements
void avx_initialize(MD5 *md5)
{
    md5->msg_len0 = 0;
    md5->msg_len1 = 0;
    md5->msg_len2 = 0;
    md5->msg_len3 = 0;

    md5->a = _mm_set1_epi32(0x67452301);
    md5->b = _mm_set1_epi32(0xefcdab89);
    md5->c = _mm_set1_epi32(0x98badcfe);
    md5->c = _mm_set1_epi32(0x98badcfe);
    md5->d = _mm_set1_epi32(0x10325476);
    md5->l = _mm_set1_epi32(0x11111111);
    md5->m = _mm_set1_epi32(0);
    md5->t = _mm_set1_epi32(0);

    md5->avxa = _mm_set1_epi32(0x67452301);
    md5->avxb = _mm_set1_epi32(0xefcdab89);
    md5->avxc = _mm_set1_epi32(0x98badcfe);
    md5->avxd = _mm_set1_epi32(0x10325476);

    md5->avx_hash0 = _mm_set1_epi32(0);
    md5->avx_hash1 = _mm_set1_epi32(0);
    md5->avx_hash2 = _mm_set1_epi32(0);
    md5->avx_hash3 = _mm_set1_epi32(0);

    md5->za = _mm_set1_epi32(0);
    md5->zb = _mm_set1_epi32(0);
    md5->zc = _mm_set1_epi32(0);
    md5->zd = _mm_set1_epi32(0);
    
    md5->f1 = _mm_set1_epi32(0);
    md5->f2 = _mm_set1_epi32(0);
    md5->f3 = _mm_set1_epi32(0);
    md5->f4 = _mm_set1_epi32(0);
    md5->f5 = _mm_set1_epi32(0);
    md5->f6 = _mm_set1_epi32(0);
    md5->f7 = _mm_set1_epi32(0);
    md5->f8 = _mm_set1_epi32(0);
    md5->f9 = _mm_set1_epi32(0);
    md5->f0 = _mm_set1_epi32(0);

    md5->avx0 = _mm_set1_epi32(0);
    md5->avx1 = _mm_set1_epi32(0);
    md5->avx2 = _mm_set1_epi32(0);
    md5->avx3 = _mm_set1_epi32(0);
    md5->avx4 = _mm_set1_epi32(0);
    md5->avx5 = _mm_set1_epi32(0);
    md5->avx6 = _mm_set1_epi32(0);
    md5->avx7 = _mm_set1_epi32(0);
    md5->avx8 = _mm_set1_epi32(0);
    md5->avx9 = _mm_set1_epi32(0);
    md5->avx10 = _mm_set1_epi32(0);
    md5->avx11 = _mm_set1_epi32(0);
    md5->avx12 = _mm_set1_epi32(0);
    md5->avx13 = _mm_set1_epi32(0);
    md5->avx14 = _mm_set1_epi32(0);
    md5->avx15 = _mm_set1_epi32(0);

    md5->T0 = _mm_set1_epi32(0xd76aa478);
    md5->T1 = _mm_set1_epi32(0xe8c7b756); 
    md5->T2 = _mm_set1_epi32(0x242070db); 
    md5->T3 = _mm_set1_epi32(0xc1bdceee);
    md5->T4 = _mm_set1_epi32(0xf57c0faf); 
    md5->T5 = _mm_set1_epi32(0x4787c62a); 
    md5->T6 = _mm_set1_epi32(0xa8304613); 
    md5->T7 = _mm_set1_epi32(0xfd469501);
    md5->T8 = _mm_set1_epi32(0x698098d8); 
    md5->T9 = _mm_set1_epi32(0x8b44f7af); 
    md5->T10 = _mm_set1_epi32(0xffff5bb1); 
    md5->T11 = _mm_set1_epi32(0x895cd7be);
    md5->T12 = _mm_set1_epi32(0x6b901122); 
    md5->T13 = _mm_set1_epi32(0xfd987193); 
    md5->T14 = _mm_set1_epi32(0xa679438e); 
    md5->T15 = _mm_set1_epi32(0x49b40821);
    
    md5->T16 = _mm_set1_epi32(0xf61e2562); 
    md5->T17 = _mm_set1_epi32(0xc040b340); 
    md5->T18 = _mm_set1_epi32(0x265e5a51); 
    md5->T19 = _mm_set1_epi32(0xe9b6c7aa);
    md5->T20 = _mm_set1_epi32(0xd62f105d); 
    md5->T21 = _mm_set1_epi32(0x02441453); 
    md5->T22 = _mm_set1_epi32(0xd8a1e681); 
    md5->T23 = _mm_set1_epi32(0xe7d3fbc8);
    md5->T24 = _mm_set1_epi32(0x21e1cde6); 
    md5->T25 = _mm_set1_epi32(0xc33707d6); 
    md5->T26 = _mm_set1_epi32(0xf4d50d87); 
    md5->T27 = _mm_set1_epi32(0x455a14ed);
    md5->T28 = _mm_set1_epi32(0xa9e3e905); 
    md5->T29 = _mm_set1_epi32(0xfcefa3f8); 
    md5->T30 = _mm_set1_epi32(0x676f02d9); 
    md5->T31 = _mm_set1_epi32(0x8d2a4c8a);
    
    md5->T32 = _mm_set1_epi32(0xfffa3942); 
    md5->T33 = _mm_set1_epi32(0x8771f681); 
    md5->T34 = _mm_set1_epi32(0x6d9d6122); 
    md5->T35 = _mm_set1_epi32(0xfde5380c);
    md5->T36 = _mm_set1_epi32(0xa4beea44); 
    md5->T37 = _mm_set1_epi32(0x4bdecfa9); 
    md5->T38 = _mm_set1_epi32(0xf6bb4b60); 
    md5->T39 = _mm_set1_epi32(0xbebfbc70);
    md5->T40 = _mm_set1_epi32(0x289b7ec6); 
    md5->T41 = _mm_set1_epi32(0xeaa127fa); 
    md5->T42 = _mm_set1_epi32(0xd4ef3085); 
    md5->T43 = _mm_set1_epi32(0x04881d05);
    md5->T44 = _mm_set1_epi32(0xd9d4d039); 
    md5->T45 = _mm_set1_epi32(0xe6db99e5); 
    md5->T46 = _mm_set1_epi32(0x1fa27cf8); 
    md5->T47 = _mm_set1_epi32(0xc4ac5665);
    
    md5->T48 = _mm_set1_epi32(0xf4292244); 
    md5->T49 = _mm_set1_epi32(0x432aff97); 
    md5->T50 = _mm_set1_epi32(0xab9423a7); 
    md5->T51 = _mm_set1_epi32(0xfc93a039);
    md5->T52 = _mm_set1_epi32(0x655b59c3); 
    md5->T53 = _mm_set1_epi32(0x8f0ccc92); 
    md5->T54 = _mm_set1_epi32(0xffeff47d); 
    md5->T55 = _mm_set1_epi32(0x85845dd1);
    md5->T56 = _mm_set1_epi32(0x6fa87e4f); 
    md5->T57 = _mm_set1_epi32(0xfe2ce6e0); 
    md5->T58 = _mm_set1_epi32(0xa3014314); 
    md5->T59 = _mm_set1_epi32(0x4e0811a1);
    md5->T60 = _mm_set1_epi32(0xf7537e82); 
    md5->T61 = _mm_set1_epi32(0xbd3af235); 
    md5->T62 = _mm_set1_epi32(0x2ad7d2bb); 
    md5->T63 = _mm_set1_epi32(0xeb86d391);


    /*.........................................PRINTING TO TEST THE PROGRAM.........................................*/

    // int* resT63 = (int*)&md5->T63;
    // printf("T63 =  %x %x %x %x\n",resT63[0],resT63[1],resT63[2],resT63[3]);
    // int* resT0 = (int*)&md5->T0;
    // printf("T0 =  %x %x %x %x\n",resT0[0],resT0[1],resT0[2],resT0[3]);
    // int* resT50 = (int*)&md5->T50;
    // printf("T50 =  %x %x %x %x\n",resT50[0],resT50[1],resT50[2],resT50[3]);
    // int* resa = (int*)&md5->a;
    // printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    // int* resc = (int*)&md5->c;
    // printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    // int* resavxc = (int*)&md5->avxc;
    // printf("avxc =  %x %x %x %x\n",resavxc[0],resavxc[1],resavxc[2],resavxc[3]);
    // int* resavx7 = (int*)&md5->avx7;
    // printf("avx7 =  %x %x %x %x\n",resavx7[0],resavx7[1],resavx7[2],resavx7[3]);
    // int* resavx_hash = (int*)&md5->avx_hash3;
    // printf("avx_hash =  %x %x %x %x\n",resavx_hash[0],resavx_hash[1],resavx_hash[2],resavx_hash[3]);
    // int* resf = (int*)&md5->f5;
    // printf("f =  %x %x %x %x\n",resf[0],resf[1],resf[2],resf[3]);

}


// Set the input message to be in the struct
void avx_set(MD5 *md5, uchar pass0[], uchar pass1[], uchar pass2[], uchar pass3[], ulong length0, ulong length1, ulong length2, ulong length3){
    unsigned int i;
    // MESSAGE_0
    for (i = 0; i < length0; i++) {
        md5 -> message0[md5 -> msg_len0] = pass0[i];
        md5 -> msg_len0++;
    }
    
    // MESSAGE_1
    for (i = 0; i < length1; i++) {
        md5 -> message1[md5 -> msg_len1] = pass1[i];
        md5 -> msg_len1++;
    }
    
    // MESSAGE_2
    for (i = 0; i < length2; i++) {
        md5 -> message2[md5 -> msg_len2] = pass2[i];
        md5 -> msg_len2++;
    }
    
    // MESSAGE_3
    for (i = 0; i < length3; i++) {
        md5 -> message3[md5 -> msg_len3] = pass3[i];
        md5 -> msg_len3++;
    }
}


// Pad the bastards with zeros
void avx_pad(MD5 *md5){
    unsigned int i;
    // MESSAGE_0
    i = md5 -> msg_len0;
    md5 -> message0[i++] = 0x80;
    
    while (i < 64) {
        md5 -> message0[i++] = 0x00;
    }
    md5 -> message0[56] = md5 -> msg_len0 * 8;
    
    // MESSAGE_1
    i = md5 -> msg_len1;
    md5 -> message1[i++] = 0x80;
    
    while (i < 64) {
        md5 -> message1[i++] = 0x00;
    }
    md5 -> message1[56] = md5 -> msg_len1 * 8;
    
    // MESSAGE_2
    i = md5 -> msg_len2;
    md5 -> message2[i++] = 0x80;
    
    while (i < 64) {
        md5 -> message2[i++] = 0x00;
    }
    md5 -> message2[56] = md5 -> msg_len2 * 8;
    
    // MESSAGE_3
    i = md5 -> msg_len3;
    md5 -> message3[i++] = 0x80;
    
    while (i < 64) {
        md5 -> message3[i++] = 0x00;
    }
    md5 -> message3[56] = md5 -> msg_len3 * 8;
}


void avx_manipulate_p1(MD5 *md5, uchar message0[], uchar message1[], uchar message2[], uchar message3[]) {
    uint a,b,c,d;
    uint msg0[16], msg1[16], msg2[16], msg3[16];
    uint i,j;
    
    // For loop changes from big endian to little endian
    for (i = 0, j = 0; i < 16; i++, j += 4) {
        msg0[i] = (message0[j]) + (message0[j + 1] << 8) + (message0[j + 2] << 16) + (message0[j + 3] << 24);
    }
    
    for (i = 0, j = 0; i < 16; i++, j += 4) {
        msg1[i] = (message1[j]) + (message1[j + 1] << 8) + (message1[j + 2] << 16) + (message1[j + 3] << 24);
    }
    
    for (i = 0, j = 0; i < 16; i++, j += 4) {
        msg2[i] = (message2[j]) + (message2[j + 1] << 8) + (message2[j + 2] << 16) + (message2[j + 3] << 24);
    }
    
    for (i = 0, j = 0; i < 16; i++, j += 4) {
        msg3[i] = (message3[j]) + (message3[j + 1] << 8) + (message3[j + 2] << 16) + (message3[j + 3] << 24);
    }


    /*.........................................PRINTING TO TEST THE PROGRAM.........................................*/

    avx_print_int(msg0);
    avx_print_int(msg1);
    avx_print_int(msg2);
    avx_print_int(msg3);

    md5->avx0 = _mm_setr_epi32(msg0[0],msg1[0],msg2[0],msg3[0]);
    md5->avx1 = _mm_setr_epi32(msg0[1],msg1[1],msg2[1],msg3[1]);
    md5->avx2 = _mm_setr_epi32(msg0[2],msg1[2],msg2[2],msg3[2]);
    md5->avx3 = _mm_setr_epi32(msg0[3],msg1[3],msg2[3],msg3[3]);
    md5->avx4 = _mm_setr_epi32(msg0[4],msg1[4],msg2[4],msg3[4]);
    md5->avx5 = _mm_setr_epi32(msg0[5],msg1[5],msg2[5],msg3[5]);
    md5->avx6 = _mm_setr_epi32(msg0[6],msg1[6],msg2[6],msg3[6]);
    md5->avx7 = _mm_setr_epi32(msg0[7],msg1[7],msg2[7],msg3[7]);
    md5->avx8 = _mm_setr_epi32(msg0[8],msg1[8],msg2[8],msg3[8]);
    md5->avx9 = _mm_setr_epi32(msg0[9],msg1[9],msg2[9],msg3[9]);
    md5->avx10 = _mm_setr_epi32(msg0[10],msg1[10],msg2[10],msg3[10]);
    md5->avx11 = _mm_setr_epi32(msg0[11],msg1[11],msg2[11],msg3[11]);
    md5->avx12 = _mm_setr_epi32(msg0[12],msg1[12],msg2[12],msg3[12]);
    md5->avx13 = _mm_setr_epi32(msg0[13],msg1[13],msg2[13],msg3[13]);
    md5->avx14 = _mm_setr_epi32(msg0[14],msg1[14],msg2[14],msg3[14]);
    md5->avx15 = _mm_setr_epi32(msg0[15],msg1[15],msg2[15],msg3[15]);


    /*.........................................PRINTING TO TEST THE PROGRAM.........................................*/

  // int* res0 = (int*)&md5->avx0;
  // printf("avx0 =  %x %x %x %x\n",res0[0],res0[1],res0[2],res0[3]);
  // int* res1 = (int*)&md5->avx1;
  // printf("avx1 =  %x %x %x %x\n",res1[0],res1[1],res1[2],res1[3]);
  // int* res2 = (int*)&md5->avx2;
  // printf("avx2 =  %x %x %x %x\n",res2[0],res2[1],res2[2],res2[3]);
  // int* res3 = (int*)&md5->avx3;
  // printf("avx3 =  %x %x %x %x\n",res3[0],res3[1],res3[2],res3[3]);
  // int* res4 = (int*)&md5->avx4;
  // printf("avx4 =  %x %x %x %x\n",res4[0],res4[1],res4[2],res4[3]);
  // int* res5 = (int*)&md5->avx5;
  // printf("avx5 =  %x %x %x %x\n",res5[0],res5[1],res5[2],res5[3]);
  // int* res6 = (int*)&md5->avx6;
  // printf("avx6 =  %x %x %x %x\n",res6[0],res6[1],res6[2],res6[3]);
  // int* res7 = (int*)&md5->avx7;
  // printf("avx7 =  %x %x %x %x\n",res7[0],res7[1],res7[2],res7[3]);
  // int* res8 = (int*)&md5->avx8;
  // printf("avx8 =  %x %x %x %x\n",res8[0],res8[1],res8[2],res8[3]);
  // int* res9 = (int*)&md5->avx9;
  // printf("avx9 =  %x %x %x %x\n",res9[0],res9[1],res9[2],res9[3]);
  // int* res10 = (int*)&md5->avx10;
  // printf("avx10 =  %x %x %x %x\n",res10[0],res10[1],res10[2],res10[3]);
  // int* res11 = (int*)&md5->avx11;
  // printf("avx11 =  %x %x %x %x\n",res11[0],res11[1],res11[2],res11[3]);
  // int* res12 = (int*)&md5->avx12;
  // printf("avx12 =  %x %x %x %x\n",res12[0],res12[1],res12[2],res12[3]);
  // int* res13 = (int*)&md5->avx13;
  // printf("avx13 =  %x %x %x %x\n",res13[0],res13[1],res13[2],res13[3]);
  // int* res14 = (int*)&md5->avx14;
  // printf("avx14 =  %x %x %x %x\n",res14[0],res14[1],res14[2],res14[3]);
  // int* res15 = (int*)&md5->avx15;
  // printf("avx15 =  %x %x %x %x\n",res15[0],res15[1],res15[2],res15[3]);



    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/


}
    

void avx_F(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, int s, __m128i t, int k){

    //#define F(b, c, d) ((b & c) | (~b & d))
    md5->m = m;
    md5->t = t;

    md5->zb = md5->b;
    md5->zc = md5->c;
    md5->zd = md5->d;

    md5->f1 = _mm_and_si128(md5->b,md5->c);
    md5->f2 = _mm_andnot_si128(md5->b,md5->d);
    md5->f3 = _mm_or_si128(md5->f1,md5->f2);

    md5->f4 = _mm_add_epi32(md5->a,md5->f3);
    md5->f5 = _mm_add_epi32(md5->m,md5->t);
    md5->f6 = _mm_add_epi32(md5->f4,md5->f5);

    md5->f7 = _mm_slli_epi32(md5->f6,s);
    md5->f8 = _mm_srli_epi32(md5->f6,k);
    md5->f9 = _mm_or_si128(md5->f7,md5->f8);

    md5->f0 = _mm_add_epi32(md5->f9,md5->b);
}

void avx_G(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, int s, __m128i t, int k){

    //#define G(b, c, d) ((b & d) | (c & ~d))
    md5->m = m;
    md5->t = t;

    md5->zb = md5->b;
    md5->zc = md5->c;
    md5->zd = md5->d;

    md5->f1 = _mm_and_si128(md5->b,md5->d);
    md5->f2 = _mm_andnot_si128(md5->d,md5->c);
    md5->f3 = _mm_or_si128(md5->f1,md5->f2);

    md5->f4 = _mm_add_epi32(md5->a,md5->f3);
    md5->f5 = _mm_add_epi32(md5->m,md5->t);
    md5->f6 = _mm_add_epi32(md5->f4,md5->f5);

    md5->f7 = _mm_slli_epi32(md5->f6,s);
    md5->f8 = _mm_srli_epi32(md5->f6,k);
    md5->f9 = _mm_or_si128(md5->f7,md5->f8);

    md5->f0 = _mm_add_epi32(md5->f9,md5->b);
}

void avx_H(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, int s, __m128i t, int k){

    //#define H(b, c, d) ((b ^ c ^ d))
    md5->m = m;
    md5->t = t;

    md5->zb = md5->b;
    md5->zc = md5->c;
    md5->zd = md5->d;
    
    md5->f1 = _mm_xor_si128(md5->b,md5->c);
    md5->f2 = _mm_xor_si128(md5->f1,md5->d);

    md5->f3 = _mm_add_epi32(md5->a,md5->f2);
    md5->f4 = _mm_add_epi32(md5->m,md5->t);
    md5->f5 = _mm_add_epi32(md5->f3,md5->f4);

    md5->f6 = _mm_slli_epi32(md5->f5,s);
    md5->f7 = _mm_srli_epi32(md5->f5,k);
    md5->f8 = _mm_or_si128(md5->f6,md5->f7);

    md5->f0 = _mm_add_epi32(md5->f8,md5->b);

}

void avx_I(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, int s, __m128i t, __m128i l, int k){

    //#define I(b, c, d) ((c ^ (b | ~d)))
    md5->m = m;
    md5->t = t;

    md5->zb = md5->b;
    md5->zc = md5->c;
    md5->zd = md5->d;

    md5->f1 = _mm_andnot_si128(md5->d,md5->l);
    md5->f2 = _mm_or_si128(md5->f1,md5->b);
    md5->f3 = _mm_xor_si128(md5->f2,md5->c);

    md5->f4 = _mm_add_epi32(md5->a,md5->f3);
    md5->f5 = _mm_add_epi32(md5->m,md5->t);
    md5->f6 = _mm_add_epi32(md5->f4,md5->f5);

    md5->f7 = _mm_slli_epi32(md5->f6,s);
    md5->f8 = _mm_srli_epi32(md5->f6,k);
    md5->f9 = _mm_or_si128(md5->f7,md5->f8);

    md5->f0 = _mm_add_epi32(md5->f9,md5->b);
}

void avx_add_hash(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d){
    md5->avx_hash0 = _mm_add_epi32(md5->a,md5->avxa);
    md5->avx_hash1 = _mm_add_epi32(md5->b,md5->avxb);
    md5->avx_hash2 = _mm_add_epi32(md5->c,md5->avxc);
    md5->avx_hash3 = _mm_add_epi32(md5->d,md5->avxd);
}

    
void avx_manipulate_p2(MD5 *md5){
int* resa;
int* resb;
int* resc;
int* resd;

    avx_F(md5, md5->a, md5->b, md5->c, md5->d, md5->avx0,  S[0],  md5->T0, k[0]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->d, md5->a, md5->b, md5->c, md5->avx1,  S[1],  md5->T1, k[1]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->c, md5->d, md5->a, md5->b, md5->avx2,  S[2],  md5->T2, k[2]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->b, md5->c, md5->d, md5->a, md5->avx3,  S[3],  md5->T3, k[3]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    resa = (int*)&md5->a;
    printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    resb = (int*)&md5->b;
    printf("b =  %x %x %x %x\n",resb[0],resb[1],resb[2],resb[3]);
    resc = (int*)&md5->c;
    printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    resd = (int*)&md5->d;
    printf("d =  %x %x %x %x\n\n",resd[0],resd[1],resd[2],resd[3]);
    avx_F(md5, md5->a, md5->b, md5->c, md5->d, md5->avx4,  S[4],  md5->T4, k[4]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->d, md5->a, md5->b, md5->c, md5->avx5,  S[5],  md5->T5, k[5]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->c, md5->d, md5->a, md5->b, md5->avx6,  S[6],  md5->T6, k[6]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->b, md5->c, md5->d, md5->a, md5->avx7,  S[7],  md5->T7, k[7]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    resa = (int*)&md5->a;
    printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    resb = (int*)&md5->b;
    printf("b =  %x %x %x %x\n",resb[0],resb[1],resb[2],resb[3]);
    resc = (int*)&md5->c;
    printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    resd = (int*)&md5->d;
    printf("d =  %x %x %x %x\n\n",resd[0],resd[1],resd[2],resd[3]);
    avx_F(md5, md5->a, md5->b, md5->c, md5->d, md5->avx8,  S[8],  md5->T8, k[8]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->d, md5->a, md5->b, md5->c, md5->avx9,  S[9],  md5->T9, k[9]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->c, md5->d, md5->a, md5->b, md5->avx10, S[10], md5->T10, k[10]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->b, md5->c, md5->d, md5->a, md5->avx11, S[11], md5->T11, k[11]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    resa = (int*)&md5->a;
    printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    resb = (int*)&md5->b;
    printf("b =  %x %x %x %x\n",resb[0],resb[1],resb[2],resb[3]);
    resc = (int*)&md5->c;
    printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    resd = (int*)&md5->d;
    printf("d =  %x %x %x %x\n\n",resd[0],resd[1],resd[2],resd[3]);
    avx_F(md5, md5->a, md5->b, md5->c, md5->d, md5->avx12, S[12], md5->T12, k[12]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->d, md5->a, md5->b, md5->c, md5->avx13, S[13], md5->T13, k[13]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->c, md5->d, md5->a, md5->b, md5->avx14, S[14], md5->T14, k[14]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_F(md5, md5->b, md5->c, md5->d, md5->a, md5->avx15, S[15], md5->T15, k[15]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    resa = (int*)&md5->a;
    printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    resb = (int*)&md5->b;
    printf("b =  %x %x %x %x\n",resb[0],resb[1],resb[2],resb[3]);
    resc = (int*)&md5->c;
    printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    resd = (int*)&md5->d;
    printf("d =  %x %x %x %x\n\n",resd[0],resd[1],resd[2],resd[3]);


    // resa = (int*)&md5->a;
    // printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    // resb = (int*)&md5->b;
    // printf("b =  %x %x %x %x\n",resb[0],resb[1],resb[2],resb[3]);
    // resc = (int*)&md5->c;
    // printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    // resd = (int*)&md5->d;
    // printf("d =  %x %x %x %x\n",resd[0],resd[1],resd[2],resd[3]);





    // int* resa = (int*)&md5->a;
    // printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    // int* resb = (int*)&md5->b;
    // printf("b =  %x %x %x %x\n",resb[0],resb[1],resb[2],resb[3]);
    // int* resc = (int*)&md5->c;
    // printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    // int* resd = (int*)&md5->d;
    // printf("d =  %x %x %x %x\n",resd[0],resd[1],resd[2],resd[3]);
    // int* res_avx0 = (int*)&md5->avx15;
    // printf("avx15 =  %x %x %x %x\n",res_avx0[0],res_avx0[1],res_avx0[2],res_avx0[3]);
    // int* resT0 = (int*)&md5->T15;
    // printf("T15 =  %x %x %x %x\n",resT0[0],resT0[1],resT0[2],resT0[3]);

    avx_G(md5, md5->a, md5->b, md5->c, md5->d, md5->avx1,  S[16], md5->T16, k[16]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->d, md5->a, md5->b, md5->c, md5->avx6,  S[17], md5->T17, k[17]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->c, md5->d, md5->a, md5->b, md5->avx11, S[18], md5->T18, k[18]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->b, md5->c, md5->d, md5->a, md5->avx0,  S[19], md5->T19, k[19]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->a, md5->b, md5->c, md5->d, md5->avx5,  S[20], md5->T20, k[20]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->d, md5->a, md5->b, md5->c, md5->avx10, S[21], md5->T21, k[21]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->c, md5->d, md5->a, md5->b, md5->avx15, S[22], md5->T22, k[22]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->b, md5->c, md5->d, md5->a, md5->avx4,  S[23], md5->T23, k[23]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->a, md5->b, md5->c, md5->d, md5->avx9,  S[24], md5->T24, k[24]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->d, md5->a, md5->b, md5->c, md5->avx14, S[25], md5->T25, k[25]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->c, md5->d, md5->a, md5->b, md5->avx3,  S[26], md5->T26, k[26]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->b, md5->c, md5->d, md5->a, md5->avx8,  S[27], md5->T27, k[27]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->a, md5->b, md5->c, md5->d, md5->avx13, S[28], md5->T28, k[28]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->d, md5->a, md5->b, md5->c, md5->avx2,  S[29], md5->T29, k[29]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->c, md5->d, md5->a, md5->b, md5->avx7,  S[30], md5->T30, k[30]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_G(md5, md5->b, md5->c, md5->d, md5->a, md5->avx12, S[31], md5->T31, k[31]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    resa = (int*)&md5->a;
    printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    resb = (int*)&md5->b;
    printf("b =  %x %x %x %x\n",resb[0],resb[1],resb[2],resb[3]);
    resc = (int*)&md5->c;
    printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    resd = (int*)&md5->d;
    printf("d =  %x %x %x %x\n\n",resd[0],resd[1],resd[2],resd[3]);

    avx_H(md5, md5->a, md5->b, md5->c, md5->d, md5->avx5,  S[32], md5->T32, k[32]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->d, md5->a, md5->b, md5->c, md5->avx8,  S[33], md5->T33, k[33]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->c, md5->d, md5->a, md5->b, md5->avx11, S[34], md5->T34, k[34]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->b, md5->c, md5->d, md5->a, md5->avx14, S[35], md5->T35, k[35]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->a, md5->b, md5->c, md5->d, md5->avx1,  S[36], md5->T36, k[36]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->d, md5->a, md5->b, md5->c, md5->avx4,  S[37], md5->T37, k[37]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->c, md5->d, md5->a, md5->b, md5->avx7,  S[38], md5->T38, k[38]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->b, md5->c, md5->d, md5->a, md5->avx10, S[39], md5->T39, k[39]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->a, md5->b, md5->c, md5->d, md5->avx13, S[40], md5->T40, k[40]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->d, md5->a, md5->b, md5->c, md5->avx0,  S[41], md5->T41, k[41]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->c, md5->d, md5->a, md5->b, md5->avx3,  S[42], md5->T42, k[42]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->b, md5->c, md5->d, md5->a, md5->avx6,  S[43], md5->T43, k[43]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->a, md5->b, md5->c, md5->d, md5->avx9,  S[44], md5->T44, k[44]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->d, md5->a, md5->b, md5->c, md5->avx12, S[45], md5->T45, k[45]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->c, md5->d, md5->a, md5->b, md5->avx15, S[46], md5->T46, k[46]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_H(md5, md5->b, md5->c, md5->d, md5->a, md5->avx2,  S[47], md5->T47, k[47]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;

    resa = (int*)&md5->a;
    printf("a =  %x %x %x %x\n",resa[0],resa[1],resa[2],resa[3]);
    resb = (int*)&md5->b;
    printf("b =  %x %x %x %x\n",resb[0],resb[1],resb[2],resb[3]);
    resc = (int*)&md5->c;
    printf("c =  %x %x %x %x\n",resc[0],resc[1],resc[2],resc[3]);
    resd = (int*)&md5->d;
    printf("d =  %x %x %x %x\n\n",resd[0],resd[1],resd[2],resd[3]);

    avx_I(md5, md5->a, md5->b, md5->c, md5->d, md5->avx0,  S[48], md5->T48, md5->l, k[48]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->d, md5->a, md5->b, md5->c, md5->avx7,  S[49], md5->T49, md5->l, k[49]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->c, md5->d, md5->a, md5->b, md5->avx14, S[50], md5->T50, md5->l, k[50]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->b, md5->c, md5->d, md5->a, md5->avx5,  S[51], md5->T51, md5->l, k[51]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->a, md5->b, md5->c, md5->d, md5->avx12, S[52], md5->T52, md5->l, k[52]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->d, md5->a, md5->b, md5->c, md5->avx3,  S[53], md5->T53, md5->l, k[53]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->c, md5->d, md5->a, md5->b, md5->avx10, S[54], md5->T54, md5->l, k[54]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->b, md5->c, md5->d, md5->a, md5->avx1,  S[55], md5->T55, md5->l, k[55]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->a, md5->b, md5->c, md5->d, md5->avx8,  S[56], md5->T56, md5->l, k[56]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->d, md5->a, md5->b, md5->c, md5->avx15, S[57], md5->T57, md5->l, k[57]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->c, md5->d, md5->a, md5->b, md5->avx6,  S[58], md5->T58, md5->l, k[58]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->b, md5->c, md5->d, md5->a, md5->avx13, S[59], md5->T59, md5->l, k[59]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->a, md5->b, md5->c, md5->d, md5->avx4,  S[60], md5->T60, md5->l, k[60]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->d, md5->a, md5->b, md5->c, md5->avx11, S[61], md5->T61, md5->l, k[61]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->c, md5->d, md5->a, md5->b, md5->avx2,  S[62], md5->T62, md5->l, k[62]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;
    avx_I(md5, md5->b, md5->c, md5->d, md5->a, md5->avx9,  S[63], md5->T63, md5->l, k[63]);
    md5->a = md5->zd; md5->b = md5->f0; md5->c = md5->zb; md5->d = md5->zc;

    

    avx_add_hash(md5, md5->a, md5->b, md5->c, md5->d);
  
}

void avx_bigendian(MD5 *md5, uchar final0[], uchar final1[], uchar final2[], uchar final3[]){
    
    __m128i q,r,s,t;
    uint m[4],n[4],o[4],p[4];

    q = md5->avx_hash0;
    r = md5->avx_hash1;
    s = md5->avx_hash2;
    t = md5->avx_hash3;
    
    int* res0 = (int*)&q;
    int* res1 = (int*)&r;
    int* res2 = (int*)&s;
    int* res3 = (int*)&t;
    
    // Separate the AVX functions and pull out the parts that you want
    // Message 0
    m[0] = res0[0];
    n[0] = res0[0];
    o[0] = res0[0];
    p[0] = res0[0];

    m[1] = res1[0];
    n[1] = res1[0];
    o[1] = res1[0];
    p[1] = res1[0];

    m[2] = res2[0];
    n[2] = res2[0];
    o[2] = res2[0];
    p[2] = res2[0];

    m[3] = res3[0];
    n[3] = res3[0];
    o[3] = res3[0];
    p[3] = res3[0];

    final0[0] = (m[0] & 0x000000ff);
    final0[1] = ((n[0] >> 8) & 0x0000ff);
    final0[2] = ((o[0] >> 16) & 0x00ff);
    final0[3] = ((p[0] >> 24) & 0xff);
    final0[4] = (m[1] & 0x000000ff);
    final0[5] = ((n[1] >> 8) & 0x0000ff);
    final0[6] = ((o[1] >> 16) & 0x00ff);
    final0[7] = ((p[1] >> 24) & 0xff);
    final0[8] = (m[2] & 0x000000ff);
    final0[9] = ((n[2] >> 8) & 0x0000ff);
    final0[10] = ((o[2] >> 16) & 0x00ff);
    final0[11] = ((p[2] >> 24) & 0xff);
    final0[12] = (m[3] & 0x000000ff);
    final0[13] = ((n[3] >> 8) & 0x0000ff);
    final0[14] = ((o[3] >> 16) & 0x00ff);
    final0[15] = ((p[3] >> 24) & 0xff);

    // Message 1
    m[0] = res0[1];
    n[0] = res0[1];
    o[0] = res0[1];
    p[0] = res0[1];

    m[1] = res1[1];
    n[1] = res1[1];
    o[1] = res1[1];
    p[1] = res1[1];

    m[2] = res2[1];
    n[2] = res2[1];
    o[2] = res2[1];
    p[2] = res2[1];

    m[3] = res3[1];
    n[3] = res3[1];
    o[3] = res3[1];
    p[3] = res3[1];

    final1[0] = (m[0] & 0x000000ff);
    final1[1] = ((n[0] >> 8) & 0x0000ff);
    final1[2] = ((o[0] >> 16) & 0x00ff);
    final1[3] = ((p[0] >> 24) & 0xff);
    final1[4] = (m[1] & 0x000000ff);
    final1[5] = ((n[1] >> 8) & 0x0000ff);
    final1[6] = ((o[1] >> 16) & 0x00ff);
    final1[7] = ((p[1] >> 24) & 0xff);
    final1[8] = (m[2] & 0x000000ff);
    final1[9] = ((n[2] >> 8) & 0x0000ff);
    final1[10] = ((o[2] >> 16) & 0x00ff);
    final1[11] = ((p[2] >> 24) & 0xff);
    final1[12] = (m[3] & 0x000000ff);
    final1[13] = ((n[3] >> 8) & 0x0000ff);
    final1[14] = ((o[3] >> 16) & 0x00ff);
    final1[15] = ((p[3] >> 24) & 0xff);

    // Message 2
    m[0] = res0[2];
    n[0] = res0[2];
    o[0] = res0[2];
    p[0] = res0[2];

    m[1] = res1[2];
    n[1] = res1[2];
    o[1] = res1[2];
    p[1] = res1[2];

    m[2] = res2[2];
    n[2] = res2[2];
    o[2] = res2[2];
    p[2] = res2[2];

    m[3] = res3[2];
    n[3] = res3[2];
    o[3] = res3[2];
    p[3] = res3[2];

    final2[0] = (m[0] & 0x000000ff);
    final2[1] = ((n[0] >> 8) & 0x0000ff);
    final2[2] = ((o[0] >> 16) & 0x00ff);
    final2[3] = ((p[0] >> 24) & 0xff);
    final2[4] = (m[1] & 0x000000ff);
    final2[5] = ((n[1] >> 8) & 0x0000ff);
    final2[6] = ((o[1] >> 16) & 0x00ff);
    final2[7] = ((p[1] >> 24) & 0xff);
    final2[8] = (m[2] & 0x000000ff);
    final2[9] = ((n[2] >> 8) & 0x0000ff);
    final2[10] = ((o[2] >> 16) & 0x00ff);
    final2[11] = ((p[2] >> 24) & 0xff);
    final2[12] = (m[3] & 0x000000ff);
    final2[13] = ((n[3] >> 8) & 0x0000ff);
    final2[14] = ((o[3] >> 16) & 0x00ff);
    final2[15] = ((p[3] >> 24) & 0xff);

    // Message 3
    m[0] = res0[3];
    n[0] = res0[3];
    o[0] = res0[3];
    p[0] = res0[3];

    m[1] = res1[3];
    n[1] = res1[3];
    o[1] = res1[3];
    p[1] = res1[3];

    m[2] = res2[3];
    n[2] = res2[3];
    o[2] = res2[3];
    p[2] = res2[3];

    m[3] = res3[3];
    n[3] = res3[3];
    o[3] = res3[3];
    p[3] = res3[3];

    final3[0] = (m[0] & 0x000000ff);
    final3[1] = ((n[0] >> 8) & 0x0000ff);
    final3[2] = ((o[0] >> 16) & 0x00ff);
    final3[3] = ((p[0] >> 24) & 0xff);
    final3[4] = (m[1] & 0x000000ff);
    final3[5] = ((n[1] >> 8) & 0x0000ff);
    final3[6] = ((o[1] >> 16) & 0x00ff);
    final3[7] = ((p[1] >> 24) & 0xff);
    final3[8] = (m[2] & 0x000000ff);
    final3[9] = ((n[2] >> 8) & 0x0000ff);
    final3[10] = ((o[2] >> 16) & 0x00ff);
    final3[11] = ((p[2] >> 24) & 0xff);
    final3[12] = (m[3] & 0x000000ff);
    final3[13] = ((n[3] >> 8) & 0x0000ff);
    final3[14] = ((o[3] >> 16) & 0x00ff);
    final3[15] = ((p[3] >> 24) & 0xff);
    
}


#endif /* avx_test_h */


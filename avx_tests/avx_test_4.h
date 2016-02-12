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
    __m128i avxa, avxb, avxc, avxd;
    __m128i avx0, avx1, avx2, avx3;
    __m128i avx4, avx5, avx6, avx7;
    __m128i avx8, avx9, avx10, avx11;
    __m128i avx12, avx13, avx14, avx15;
    __m128i avx_hash0, avx_hash1, avx_hash2, avx_hash3;
    __m128i f1,f2,f3,f4,f5,f6,f7,f8,f9,f0;
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
    // LENGTH 0_3
    md5 -> msg_len0 = 0;
    md5 -> msg_len1 = 0;
    md5 -> msg_len2 = 0;
    md5 -> msg_len3 = 0;

    __m128i avxa = _mm_setr_epi32(0x67452301,0x67452301,0x67452301,0x67452301);
    __m128i avxb = _mm_setr_epi32(0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89);
    __m128i avxc = _mm_setr_epi32(0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe);
    __m128i avxd = _mm_setr_epi32(0x10325476,0x10325476,0x10325476,0x10325476);

    __m128i avx0 = _mm_setr_epi32(0,0,0,0);
    __m128i avx1 = _mm_setr_epi32(0,0,0,0);
    __m128i avx2 = _mm_setr_epi32(0,0,0,0);
    __m128i avx3 = _mm_setr_epi32(0,0,0,0);
    __m128i avx4 = _mm_setr_epi32(0,0,0,0);
    __m128i avx5 = _mm_setr_epi32(0,0,0,0);
    __m128i avx6 = _mm_setr_epi32(0,0,0,0);
    __m128i avx7 = _mm_setr_epi32(0,0,0,0);
    __m128i avx8 = _mm_setr_epi32(0,0,0,0);
    __m128i avx9 = _mm_setr_epi32(0,0,0,0);
    __m128i avx10 = _mm_setr_epi32(0,0,0,0);
    __m128i avx11 = _mm_setr_epi32(0,0,0,0);
    __m128i avx12 = _mm_setr_epi32(0,0,0,0);
    __m128i avx13 = _mm_setr_epi32(0,0,0,0);
    __m128i avx14 = _mm_setr_epi32(0,0,0,0);
    __m128i avx15 = _mm_setr_epi32(0,0,0,0);

    __m128i avx_hash0 = _mm_setr_epi32(0,0,0,0);
    __m128i avx_hash1 = _mm_setr_epi32(0,0,0,0);
    __m128i avx_hash2 = _mm_setr_epi32(0,0,0,0);
    __m128i avx_hash3 = _mm_setr_epi32(0,0,0,0);
    
    __m128i f1 = _mm_setr_epi32(0,0,0,0);
    __m128i f2 = _mm_setr_epi32(0,0,0,0);
    __m128i f3 = _mm_setr_epi32(0,0,0,0);
    __m128i f4 = _mm_setr_epi32(0,0,0,0);
    __m128i f5 = _mm_setr_epi32(0,0,0,0);
    __m128i f6 = _mm_setr_epi32(0,0,0,0);
    __m128i f7 = _mm_setr_epi32(0,0,0,0);
    __m128i f8 = _mm_setr_epi32(0,0,0,0);
    __m128i f9 = _mm_setr_epi32(0,0,0,0);
    __m128i f0 = _mm_setr_epi32(0,0,0,0);

    // Have to initialize the 'T' vector
    __m128i T0 = _mm_setr_epi32(0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478); 
    __m128i T1 = _mm_setr_epi32(0xe8c7b756,0xe8c7b756,0xe8c7b756,0xe8c7b756); 
    __m128i T2 = _mm_setr_epi32(0x242070db,0x242070db,0x242070db,0x242070db); 
    __m128i T3 = _mm_setr_epi32(0xc1bdceee,0xc1bdceee,0xc1bdceee,0xc1bdceee);
    __m128i T4 = _mm_setr_epi32(0xf57c0faf,0xf57c0faf,0xf57c0faf,0xf57c0faf); 
    __m128i T5 = _mm_setr_epi32(0x4787c62a,0x4787c62a,0x4787c62a,0x4787c62a); 
    __m128i T6 = _mm_setr_epi32(0xa8304613,0xa8304613,0xa8304613,0xa8304613); 
    __m128i T7 = _mm_setr_epi32(0xfd469501,0xfd469501,0xfd469501,0xfd469501);
    __m128i T8 = _mm_setr_epi32(0x698098d8,0x698098d8,0x698098d8,0x698098d8); 
    __m128i T9 = _mm_setr_epi32(0x8b44f7af,0x8b44f7af,0x8b44f7af,0x8b44f7af); 
    __m128i T10 = _mm_setr_epi32(0xffff5bb1,0xffff5bb1,0xffff5bb1,0xffff5bb1); 
    __m128i T11 = _mm_setr_epi32(0x895cd7be,0x895cd7be,0x895cd7be,0x895cd7be);
    __m128i T12 = _mm_setr_epi32(0x6b901122,0x6b901122,0x6b901122,0x6b901122); 
    __m128i T13 = _mm_setr_epi32(0xfd987193,0xfd987193,0xfd987193,0xfd987193); 
    __m128i T14 = _mm_setr_epi32(0xa679438e,0xa679438e,0xa679438e,0xa679438e); 
    __m128i T15 = _mm_setr_epi32(0x49b40821,0x49b40821,0x49b40821,0x49b40821);
    
    __m128i T16 = _mm_setr_epi32(0xf61e2562,0xf61e2562,0xf61e2562,0xf61e2562); 
    __m128i T17 = _mm_setr_epi32(0xc040b340,0xc040b340,0xc040b340,0xc040b340); 
    __m128i T18 = _mm_setr_epi32(0x265e5a51,0x265e5a51,0x265e5a51,0x265e5a51); 
    __m128i T19 = _mm_setr_epi32(0xe9b6c7aa,0xe9b6c7aa,0xe9b6c7aa,0xe9b6c7aa);
    __m128i T20 = _mm_setr_epi32(0xd62f105d,0xd62f105d,0xd62f105d,0xd62f105d); 
    __m128i T21 = _mm_setr_epi32(0x02441453,0x02441453,0x02441453,0x02441453); 
    __m128i T22 = _mm_setr_epi32(0xd8a1e681,0xd8a1e681,0xd8a1e681,0xd8a1e681); 
    __m128i T23 = _mm_setr_epi32(0xe7d3fbc8,0xe7d3fbc8,0xe7d3fbc8,0xe7d3fbc8);
    __m128i T24 = _mm_setr_epi32(0x21e1cde6,0x21e1cde6,0x21e1cde6,0x21e1cde6); 
    __m128i T25 = _mm_setr_epi32(0xc33707d6,0xc33707d6,0xc33707d6,0xc33707d6); 
    __m128i T26 = _mm_setr_epi32(0xf4d50d87,0xf4d50d87,0xf4d50d87,0xf4d50d87); 
    __m128i T27 = _mm_setr_epi32(0x455a14ed,0x455a14ed,0x455a14ed,0x455a14ed);
    __m128i T28 = _mm_setr_epi32(0xa9e3e905,0xa9e3e905,0xa9e3e905,0xa9e3e905); 
    __m128i T29 = _mm_setr_epi32(0xfcefa3f8,0xfcefa3f8,0xfcefa3f8,0xfcefa3f8); 
    __m128i T30 = _mm_setr_epi32(0x676f02d9,0x676f02d9,0x676f02d9,0x676f02d9); 
    __m128i T31 = _mm_setr_epi32(0x8d2a4c8a,0x8d2a4c8a,0x8d2a4c8a,0x8d2a4c8a);
    
    __m128i T32 = _mm_setr_epi32(0xfffa3942,0xfffa3942,0xfffa3942,0xfffa3942); 
    __m128i T33 = _mm_setr_epi32(0x8771f681,0x8771f681,0x8771f681,0x8771f681); 
    __m128i T34 = _mm_setr_epi32(0x6d9d6122,0x6d9d6122,0x6d9d6122,0x6d9d6122); 
    __m128i T35 = _mm_setr_epi32(0xfde5380c,0xfde5380c,0xfde5380c,0xfde5380c);
    __m128i T36 = _mm_setr_epi32(0xa4beea44,0xa4beea44,0xa4beea44,0xa4beea44); 
    __m128i T37 = _mm_setr_epi32(0x4bdecfa9,0x4bdecfa9,0x4bdecfa9,0x4bdecfa9); 
    __m128i T38 = _mm_setr_epi32(0xf6bb4b60,0xf6bb4b60,0xf6bb4b60,0xf6bb4b60); 
    __m128i T39 = _mm_setr_epi32(0xbebfbc70,0xbebfbc70,0xbebfbc70,0xbebfbc70);
    __m128i T40 = _mm_setr_epi32(0x289b7ec6,0x289b7ec6,0x289b7ec6,0x289b7ec6); 
    __m128i T41 = _mm_setr_epi32(0xeaa127fa,0xeaa127fa,0xeaa127fa,0xeaa127fa); 
    __m128i T42 = _mm_setr_epi32(0xd4ef3085,0xd4ef3085,0xd4ef3085,0xd4ef3085); 
    __m128i T43 = _mm_setr_epi32(0x04881d05,0x04881d05,0x04881d05,0x04881d05);
    __m128i T44 = _mm_setr_epi32(0xd9d4d039,0xd9d4d039,0xd9d4d039,0xd9d4d039); 
    __m128i T45 = _mm_setr_epi32(0xe6db99e5,0xe6db99e5,0xe6db99e5,0xe6db99e5); 
    __m128i T46 = _mm_setr_epi32(0x1fa27cf8,0x1fa27cf8,0x1fa27cf8,0x1fa27cf8); 
    __m128i T47 = _mm_setr_epi32(0xc4ac5665,0xc4ac5665,0xc4ac5665,0xc4ac5665);
    
    __m128i T48 = _mm_setr_epi32(0xf4292244,0xf4292244,0xf4292244,0xf4292244); 
    __m128i T49 = _mm_setr_epi32(0x432aff97,0x432aff97,0x432aff97,0x432aff97); 
    __m128i T50 = _mm_setr_epi32(0xab9423a7,0xab9423a7,0xab9423a7,0xab9423a7); 
    __m128i T51 = _mm_setr_epi32(0xfc93a039,0xfc93a039,0xfc93a039,0xfc93a039);
    __m128i T52 = _mm_setr_epi32(0x655b59c3,0x655b59c3,0x655b59c3,0x655b59c3); 
    __m128i T53 = _mm_setr_epi32(0x8f0ccc92,0x8f0ccc92,0x8f0ccc92,0x8f0ccc92); 
    __m128i T54 = _mm_setr_epi32(0xffeff47d,0xffeff47d,0xffeff47d,0xffeff47d); 
    __m128i T55 = _mm_setr_epi32(0x85845dd1,0x85845dd1,0x85845dd1,0x85845dd1);
    __m128i T56 = _mm_setr_epi32(0x6fa87e4f,0x6fa87e4f,0x6fa87e4f,0x6fa87e4f); 
    __m128i T57 = _mm_setr_epi32(0xfe2ce6e0,0xfe2ce6e0,0xfe2ce6e0,0xfe2ce6e0); 
    __m128i T58 = _mm_setr_epi32(0xa3014314,0xa3014314,0xa3014314,0xa3014314); 
    __m128i T59 = _mm_setr_epi32(0x4e0811a1,0x4e0811a1,0x4e0811a1,0x4e0811a1);
    __m128i T60 = _mm_setr_epi32(0xf7537e82,0xf7537e82,0xf7537e82,0xf7537e82); 
    __m128i T61 = _mm_setr_epi32(0xbd3af235,0xbd3af235,0xbd3af235,0xbd3af235); 
    __m128i T62 = _mm_setr_epi32(0x2ad7d2bb,0x2ad7d2bb,0x2ad7d2bb,0x2ad7d2bb); 
    __m128i T63 = _mm_setr_epi32(0xeb86d391,0xeb86d391,0xeb86d391,0xeb86d391);


    // // Initialize the 'S' variables
    // __m128i S0 = _mm_setr_epi32(7,7,7,7);
    // __m128i S1 = _mm_setr_epi32(12,12,12,12);
    // __m128i S2 = _mm_setr_epi32(17,17,17,17);
    // __m128i S3 = _mm_setr_epi32(22,22,22,22);
    // __m128i S4 = _mm_setr_epi32(7,7,7,7);
    // __m128i S5 = _mm_setr_epi32(12,12,12,12);
    // __m128i S6 = _mm_setr_epi32(17,17,17,17);
    // __m128i S7 = _mm_setr_epi32(22,22,22,22);
    // __m128i S8 = _mm_setr_epi32(7,7,7,7);
    // __m128i S9 = _mm_setr_epi32(12,12,12,12);
    // __m128i S10 = _mm_setr_epi32(17,17,17,17);
    // __m128i S11 = _mm_setr_epi32(22,22,22,22);
    // __m128i S12 = _mm_setr_epi32(7,7,7,7);
    // __m128i S13 = _mm_setr_epi32(12,12,12,12);
    // __m128i S14 = _mm_setr_epi32(17,17,17,17);
    // __m128i S15 = _mm_setr_epi32(22,22,22,22);

    // __m128i S16 = _mm_setr_epi32(5,5,5,5);
    // __m128i S17 = _mm_setr_epi32(9,9,9,9);
    // __m128i S18 = _mm_setr_epi32(14,14,14,14);
    // __m128i S19 = _mm_setr_epi32(20,20,20,20);
    // __m128i S20 = _mm_setr_epi32(5,5,5,5);
    // __m128i S21 = _mm_setr_epi32(9,9,9,9);
    // __m128i S22 = _mm_setr_epi32(14,14,14,14);
    // __m128i S23 = _mm_setr_epi32(20,20,20,20);
    // __m128i S24 = _mm_setr_epi32(5,5,5,5);
    // __m128i S25 = _mm_setr_epi32(9,9,9,9);
    // __m128i S26 = _mm_setr_epi32(14,14,14,14);
    // __m128i S27 = _mm_setr_epi32(20,20,20,20);
    // __m128i S28 = _mm_setr_epi32(5,5,5,5);
    // __m128i S29 = _mm_setr_epi32(9,9,9,9);
    // __m128i S30 = _mm_setr_epi32(14,14,14,14);
    // __m128i S31 = _mm_setr_epi32(20,20,20,20);

    // __m128i S32 = _mm_setr_epi32(4,4,4,4);
    // __m128i S33 = _mm_setr_epi32(11,11,11,11);
    // __m128i S34 = _mm_setr_epi32(16,16,16,16);
    // __m128i S35 = _mm_setr_epi32(23,23,23,23);
    // __m128i S36 = _mm_setr_epi32(4,4,4,4);
    // __m128i S37 = _mm_setr_epi32(11,11,11,11);
    // __m128i S38 = _mm_setr_epi32(16,16,16,16);
    // __m128i S39 = _mm_setr_epi32(23,23,23,23);
    // __m128i S40 = _mm_setr_epi32(4,4,4,4);
    // __m128i S41 = _mm_setr_epi32(11,11,11,11);
    // __m128i S42 = _mm_setr_epi32(16,16,16,16);
    // __m128i S43 = _mm_setr_epi32(23,23,23,23);
    // __m128i S44 = _mm_setr_epi32(4,4,4,4);
    // __m128i S45 = _mm_setr_epi32(11,11,11,11);
    // __m128i S46 = _mm_setr_epi32(16,16,16,16);
    // __m128i S47 = _mm_setr_epi32(23,23,23,23);

    // __m128i S48 = _mm_setr_epi32(6,6,6,6);
    // __m128i S49 = _mm_setr_epi32(10,10,10,10);
    // __m128i S50 = _mm_setr_epi32(15,15,15,15);
    // __m128i S51 = _mm_setr_epi32(21,21,21,21);
    // __m128i S52 = _mm_setr_epi32(6,6,6,6);
    // __m128i S53 = _mm_setr_epi32(10,10,10,10);
    // __m128i S54 = _mm_setr_epi32(15,15,15,15);
    // __m128i S55 = _mm_setr_epi32(21,21,21,21);
    // __m128i S56 = _mm_setr_epi32(6,6,6,6);
    // __m128i S57 = _mm_setr_epi32(10,10,10,10);
    // __m128i S58 = _mm_setr_epi32(15,15,15,15);
    // __m128i S59 = _mm_setr_epi32(21,21,21,21);
    // __m128i S60 = _mm_setr_epi32(6,6,6,6);
    // __m128i S61 = _mm_setr_epi32(10,10,10,10);
    // __m128i S62 = _mm_setr_epi32(15,15,15,15);
    // __m128i S63 = _mm_setr_epi32(21,21,21,21);

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


    avx_print_int(msg0);
    avx_print_int(msg1);
    avx_print_int(msg2);
    avx_print_int(msg3);

    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    /*...................The Program is working up until this point...................*/
    

    md5 -> avx0 = _mm_setr_epi32(msg0[0],msg1[0],msg2[0],msg3[0]);
    md5 -> avx1 = _mm_setr_epi32(msg0[1],msg1[1],msg2[1],msg3[1]);
    md5 -> avx2 = _mm_setr_epi32(msg0[2],msg1[2],msg2[2],msg3[2]);
    md5 -> avx3 = _mm_setr_epi32(msg0[3],msg1[3],msg2[3],msg3[3]);
    md5 -> avx4 = _mm_setr_epi32(msg0[4],msg1[4],msg2[4],msg3[4]);
    md5 -> avx5 = _mm_setr_epi32(msg0[5],msg1[5],msg2[5],msg3[5]);
    md5 -> avx6 = _mm_setr_epi32(msg0[6],msg1[6],msg2[6],msg3[6]);
    md5 -> avx7 = _mm_setr_epi32(msg0[7],msg1[7],msg2[7],msg3[7]);
    md5 -> avx8 = _mm_setr_epi32(msg0[8],msg1[8],msg2[8],msg3[8]);
    md5 -> avx9 = _mm_setr_epi32(msg0[9],msg1[9],msg2[9],msg3[9]);
    md5 -> avx10 = _mm_setr_epi32(msg0[10],msg1[10],msg2[10],msg3[10]);
    md5 -> avx11 = _mm_setr_epi32(msg0[11],msg1[11],msg2[11],msg3[11]);
    md5 -> avx12 = _mm_setr_epi32(msg0[12],msg1[12],msg2[12],msg3[12]);
    md5 -> avx13 = _mm_setr_epi32(msg0[13],msg1[13],msg2[13],msg3[13]);
    md5 -> avx14 = _mm_setr_epi32(msg0[14],msg1[14],msg2[14],msg3[14]);
    md5 -> avx15 = _mm_setr_epi32(msg0[15],msg1[15],msg2[15],msg3[15]);
    
    // Store all initial values of a,b,c,d into their respective variables for manipulation
}
    

void avx_F(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, int s, __m128i t, int k){

    //#define F(b, c, d) ((b & c) | (~b & d))

    md5 -> f1 = _mm_and_si128(b,c);
    md5 -> f2 = _mm_andnot_si128(b,d);
    md5 -> f3 = _mm_or_si128(md5->f1,md5->f2);

    md5 -> f4 = _mm_add_epi32(a,md5->f3);
    md5 -> f5 = _mm_add_epi32(m,t);
    md5 -> f6 = _mm_add_epi32(md5->f4,md5->f5);

    md5 -> f7 = _mm_slli_epi32(md5->f6,s);
    md5 -> f8 = _mm_srli_epi32(md5->f6,k);
    md5 -> f9 = _mm_or_si128(md5->f7,md5->f8);

    a = _mm_add_epi32(md5->f9,b);
}

void avx_G(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, int s, __m128i t, int k){

    //#define G(b, c, d) ((b & d) | (c & ~d))

    md5 -> f1 = _mm_and_si128(b,d);
    md5 -> f2 = _mm_andnot_si128(d,c);
    md5 -> f3 = _mm_or_si128(md5->f1,md5->f2);

    md5 -> f4 = _mm_add_epi32(a,md5->f3);
    md5 -> f5 = _mm_add_epi32(m,t);
    md5 -> f6 = _mm_add_epi32(md5->f4,md5->f5);

    md5 -> f7 = _mm_slli_epi32(md5->f6,s);
    md5 -> f8 = _mm_srli_epi32(md5->f6,k);
    md5 -> f9 = _mm_or_si128(md5->f7,md5->f8);

    a = _mm_add_epi32(md5->f9,b);
}

void avx_H(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, int s, __m128i t, int k){

    //#define H(b, c, d) ((b ^ c ^ d))

    md5 -> f1 = _mm_xor_si128(b,c);
    md5 -> f2 = _mm_xor_si128(md5->f1,d);

    md5 -> f3 = _mm_add_epi32(a,md5->f2);
    md5 -> f4 = _mm_add_epi32(m,t);
    md5 -> f5 = _mm_add_epi32(md5->f3,md5->f4);

    md5 -> f6 = _mm_slli_epi32(md5->f5,s);
    md5 -> f7 = _mm_srli_epi32(md5->f5,k);
    md5 -> f8 = _mm_or_si128(md5->f6,md5->f7);

    a = _mm_add_epi32(md5->f8,b);
}

void avx_I(MD5 *md5, __m128i a, __m128i b, __m128i c, __m128i d, __m128i m, int s, __m128i t, __m128i l, int k){

    //#define I(b, c, d) ((c ^ (b | ~d)))

    md5 -> f1 = _mm_andnot_si128(d,l);
    md5 -> f2 = _mm_or_si128(md5->f1,b);
    md5 -> f3 = _mm_xor_si128(md5->f2,c);

    md5 -> f4 = _mm_add_epi32(a,md5->f3);
    md5 -> f5 = _mm_add_epi32(m,t);
    md5 -> f6 = _mm_add_epi32(md5->f4,md5->f5);

    md5 -> f7 = _mm_slli_epi32(md5->f6,s);
    md5 -> f8 = _mm_srli_epi32(md5->f6,k);
    md5 -> f9 = _mm_or_si128(md5->f7,md5->f8);

    a = _mm_add_epi32(md5->f9,b);
}

    
void avx_manipulate_p2(MD5 *md5){

    __m128i a = _mm_setr_epi32(0x67452301,0x67452301,0x67452301,0x67452301);
    __m128i b = _mm_setr_epi32(0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89);
    __m128i c = _mm_setr_epi32(0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe);
    __m128i d = _mm_setr_epi32(0x10325476,0x10325476,0x10325476,0x10325476);
    __m128i l = _mm_setr_epi32(0x11111111,0x11111111,0x11111111,0x11111111);

    avx_F(md5, a, b, c, d, md5->avx0,  S[0],  T0, k[0]);
    avx_F(md5, d, a, b, c, md5->avx1,  S[1],  T1, k[1]);
    avx_F(md5, c, d, a, b, md5->avx2,  S[2],  T2, k[2]);
    avx_F(md5, b, c, d, a, md5->avx3,  S[3],  T3, k[3]);
    avx_F(md5, a, b, c, d, md5->avx4,  S[4],  T4, k[4]);
    avx_F(md5, d, a, b, c, md5->avx5,  S[5],  T5, k[5]);
    avx_F(md5, c, d, a, b, md5->avx6,  S[6],  T6, k[6]);
    avx_F(md5, b, c, d, a, md5->avx7,  S[7],  T7, k[7]);
    avx_F(md5, a, b, c, d, md5->avx8,  S[8],  T8, k[8]);
    avx_F(md5, d, a, b, c, md5->avx9,  S[9],  T9, k[9]);
    avx_F(md5, c, d, a, b, md5->avx10, S[10], T10, k[10]);
    avx_F(md5, b, c, d, a, md5->avx11, S[11], T11, k[11]);
    avx_F(md5, a, b, c, d, md5->avx12, S[12], T12, k[12]);
    avx_F(md5, d, a, b, c, md5->avx13, S[13], T13, k[13]);
    avx_F(md5, c, d, a, b, md5->avx14, S[14], T14, k[14]);
    avx_F(md5, b, c, d, a, md5->avx15, S[15], T15, k[15]);

    avx_G(md5, a, b, c, d, md5->avx1,  S[16], T16, k[16]);
    avx_G(md5, d, a, b, c, md5->avx6,  S[17], T17, k[17]);
    avx_G(md5, c, d, a, b, md5->avx11, S[18], T18, k[18]);
    avx_G(md5, b, c, d, a, md5->avx0,  S[19], T19, k[19]);
    avx_G(md5, a, b, c, d, md5->avx5,  S[20], T20, k[20]);
    avx_G(md5, d, a, b, c, md5->avx10, S[21], T21, k[21]);
    avx_G(md5, c, d, a, b, md5->avx15, S[22], T22, k[22]);
    avx_G(md5, b, c, d, a, md5->avx4,  S[23], T23, k[23]);
    avx_G(md5, a, b, c, d, md5->avx9,  S[24], T24, k[24]);
    avx_G(md5, d, a, b, c, md5->avx14, S[25], T25, k[25]);
    avx_G(md5, c, d, a, b, md5->avx3,  S[26], T26, k[26]);
    avx_G(md5, b, c, d, a, md5->avx8,  S[27], T27, k[27]);
    avx_G(md5, a, b, c, d, md5->avx13, S[28], T28, k[28]);
    avx_G(md5, d, a, b, c, md5->avx2,  S[29], T29, k[29]);
    avx_G(md5, c, d, a, b, md5->avx7,  S[30], T30, k[30]);
    avx_G(md5, b, c, d, a, md5->avx12, S[31], T31, k[31]);

    avx_H(md5, a, b, c, d, md5->avx5,  S[32], T32, k[32]);
    avx_H(md5, d, a, b, c, md5->avx8,  S[33], T33, k[33]);
    avx_H(md5, c, d, a, b, md5->avx11, S[34], T34, k[34]);
    avx_H(md5, b, c, d, a, md5->avx14, S[35], T35, k[35]);
    avx_H(md5, a, b, c, d, md5->avx1,  S[36], T36, k[36]);
    avx_H(md5, d, a, b, c, md5->avx4,  S[37], T37, k[37]);
    avx_H(md5, c, d, a, b, md5->avx7,  S[38], T38, k[38]);
    avx_H(md5, b, c, d, a, md5->avx10, S[39], T39, k[39]);
    avx_H(md5, a, b, c, d, md5->avx13, S[40], T40, k[40]);
    avx_H(md5, d, a, b, c, md5->avx0,  S[41], T41, k[41]);
    avx_H(md5, c, d, a, b, md5->avx3,  S[42], T42, k[42]);
    avx_H(md5, b, c, d, a, md5->avx6,  S[43], T43, k[43]);
    avx_H(md5, a, b, c, d, md5->avx9,  S[44], T44, k[44]);
    avx_H(md5, d, a, b, c, md5->avx12, S[45], T45, k[45]);
    avx_H(md5, c, d, a, b, md5->avx15, S[46], T46, k[46]);
    avx_H(md5, b, c, d, a, md5->avx2,  S[47], T47, k[47]);

    avx_I(md5, a, b, c, d, md5->avx0,  S[48], T48, l, k[48]);
    avx_I(md5, d, a, b, c, md5->avx7,  S[49], T49, l, k[49]);
    avx_I(md5, c, d, a, b, md5->avx14, S[50], T50, l, k[50]);
    avx_I(md5, b, c, d, a, md5->avx5,  S[51], T51, l, k[51]);
    avx_I(md5, a, b, c, d, md5->avx12, S[52], T52, l, k[52]);
    avx_I(md5, d, a, b, c, md5->avx3,  S[53], T53, l, k[53]);
    avx_I(md5, c, d, a, b, md5->avx10, S[54], T54, l, k[54]);
    avx_I(md5, b, c, d, a, md5->avx1,  S[55], T55, l, k[55]);
    avx_I(md5, a, b, c, d, md5->avx8,  S[56], T56, l, k[56]);
    avx_I(md5, d, a, b, c, md5->avx15, S[57], T57, l, k[57]);
    avx_I(md5, c, d, a, b, md5->avx6,  S[58], T58, l, k[58]);
    avx_I(md5, b, c, d, a, md5->avx13, S[59], T59, l, k[59]);
    avx_I(md5, a, b, c, d, md5->avx4,  S[60], T60, l, k[60]);
    avx_I(md5, d, a, b, c, md5->avx11, S[61], T61, l, k[61]);
    avx_I(md5, c, d, a, b, md5->avx2,  S[62], T62, l, k[62]);
    avx_I(md5, b, c, d, a, md5->avx9,  S[63], T63, l, k[63]);

    md5->avx_hash0 = md5->avxa + a;
    md5->avx_hash1 = md5->avxb + b;
    md5->avx_hash2 = md5->avxc + c;
    md5->avx_hash3 = md5->avxd + d;     
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


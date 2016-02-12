
//
//  md5_original.h
//  md5_avx
//
//  Created by Danny Froerer on 2/3/16.
//  Copyright © 2016 Danny Froerer. All rights reserved.
//

#ifndef md5_original_h
#define md5_original_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>


#define alpha 26;

//char lower[alpha] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//char upper[alpha] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

// Initial first block values
uint32_t ai = 0x67452301;
uint32_t bi = 0xefcdab89;
uint32_t ci = 0x98badcfe;
uint32_t di = 0x10325476;

#define F(x, y, z) ((x & y) | (~x & z))
#define G(x, y, z) ((x & z) | (y & ~z))
#define H(x, y, z) ((x ^ y ^ z))
#define I(x, y, z) ((y ^ (x | ~z)))
#define SHIFT(a, s) ((a << s) | (a >> (32 - s)))

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

//uint32_t blocks[16];

typedef struct {
    unsigned char message[64];      //data
    // unsigned int msg[16];
    unsigned int msg_len;           //msg_len
    unsigned int blocks[4];         //blocks
    unsigned int msgbitlen[2];      //bitlen
} MD5;

void md5_initialize(MD5 *md5)
{
    md5 -> msg_len = 0;
    md5 -> blocks[0] = ai;
    md5 -> blocks[1] = bi;
    md5 -> blocks[2] = ci;
    md5 -> blocks[3] = di;
    md5 -> msgbitlen[0] = 0;
    md5 -> msgbitlen[1] = 0;
}

void md5_set(MD5 *md5, unsigned char message[], unsigned long length) {
    unsigned int i;
    
    for (i = 0; i < length; i++) {
        md5 -> message[md5 -> msg_len] = message[i];
        md5 -> msg_len++;
    }
}


void md5_manipulate(MD5 *md5, unsigned char message[]) {
    unsigned int a,b,c,d;
    unsigned int msg[16];
    unsigned int i,j;
    
    // For loop changes from big endian to little endian
    for (i = 0, j = 0; i < 16; i++, j += 4) {
        msg[i] = (message[j]) + (message[j + 1] << 8) + (message[j + 2] << 16) + (message[j + 3] << 24);
    }
    
    // Store all initial values of a,b,c,d into their respective variables for manipulation
    a = md5 -> blocks[0];
    b = md5 -> blocks[1];
    c = md5 -> blocks[2];
    d = md5 -> blocks[3];
    
    FF(a, b, c, d, msg[0],  S[0],  T[0]);
    FF(d, a, b, c, msg[1],  S[1],  T[1]);
    FF(c, d, a, b, msg[2],  S[2],  T[2]);
    FF(b, c, d, a, msg[3],  S[3],  T[3]);
    FF(a, b, c, d, msg[4],  S[4],  T[4]);
    FF(d, a, b, c, msg[5],  S[5],  T[5]);
    FF(c, d, a, b, msg[6],  S[6],  T[6]);
    FF(b, c, d, a, msg[7],  S[7],  T[7]);
    FF(a, b, c, d, msg[8],  S[8],  T[8]);
    FF(d, a, b, c, msg[9],  S[9],  T[9]);
    FF(c, d, a, b, msg[10], S[10], T[10]);
    FF(b, c, d, a, msg[11], S[11], T[11]);
    FF(a, b, c, d, msg[12], S[12], T[12]);
    FF(d, a, b, c, msg[13], S[13], T[13]);
    FF(c, d, a, b, msg[14], S[14], T[14]);
    FF(b, c, d, a, msg[15], S[15], T[15]);
    
    GG(a, b, c, d, msg[1],  S[16], T[16]);
    GG(d, a, b, c, msg[6],  S[17], T[17]);
    GG(c, d, a, b, msg[11], S[18], T[18]);
    GG(b, c, d, a, msg[0],  S[19], T[19]);
    GG(a, b, c, d, msg[5],  S[20], T[20]);
    GG(d, a, b, c, msg[10], S[21], T[21]);
    GG(c, d, a, b, msg[15], S[22], T[22]);
    GG(b, c, d, a, msg[4],  S[23], T[23]);
    GG(a, b, c, d, msg[9],  S[24], T[24]);
    GG(d, a, b, c, msg[14], S[25], T[25]);
    GG(c, d, a, b, msg[3],  S[26], T[26]);
    GG(b, c, d, a, msg[8],  S[27], T[27]);
    GG(a, b, c, d, msg[13], S[28], T[28]);
    GG(d, a, b, c, msg[2],  S[29], T[29]);
    GG(c, d, a, b, msg[7],  S[30], T[30]);
    GG(b, c, d, a, msg[12], S[31], T[31]);
    
    HH(a, b, c, d, msg[5],  S[32], T[32]);
    HH(d, a, b, c, msg[8],  S[33], T[33]);
    HH(c, d, a, b, msg[11], S[34], T[34]);
    HH(b, c, d, a, msg[14], S[35], T[35]);
    HH(a, b, c, d, msg[1],  S[36], T[36]);
    HH(d, a, b, c, msg[4],  S[37], T[37]);
    HH(c, d, a, b, msg[7],  S[38], T[38]);
    HH(b, c, d, a, msg[10], S[39], T[39]);
    HH(a, b, c, d, msg[13], S[40], T[40]);
    HH(d, a, b, c, msg[0],  S[41], T[41]);
    HH(c, d, a, b, msg[3],  S[42], T[42]);
    HH(b, c, d, a, msg[6],  S[43], T[43]);
    HH(a, b, c, d, msg[9],  S[44], T[44]);
    HH(d, a, b, c, msg[12], S[45], T[45]);
    HH(c, d, a, b, msg[15], S[46], T[46]);
    HH(b, c, d, a, msg[2],  S[47], T[47]);
    
    II(a, b, c, d, msg[0],  S[48], T[48]);
    II(d, a, b, c, msg[7],  S[49], T[49]);
    II(c, d, a, b, msg[14], S[50], T[50]);
    II(b, c, d, a, msg[5],  S[51], T[51]);
    II(a, b, c, d, msg[12], S[52], T[52]);
    II(d, a, b, c, msg[3],  S[53], T[53]);
    II(c, d, a, b, msg[10], S[54], T[54]);
    II(b, c, d, a, msg[1],  S[55], T[55]);
    II(a, b, c, d, msg[8],  S[56], T[56]);
    II(d, a, b, c, msg[15], S[57], T[57]);
    II(c, d, a, b, msg[6],  S[58], T[58]);
    II(b, c, d, a, msg[13], S[59], T[59]);
    II(a, b, c, d, msg[4],  S[60], T[60]);
    II(d, a, b, c, msg[11], S[61], T[61]);
    II(c, d, a, b, msg[2],  S[62], T[62]);
    II(b, c, d, a, msg[9],  S[63], T[63]);
    
    md5->blocks[0] += a;
    md5->blocks[1] += b;
    md5->blocks[2] += c;
    md5->blocks[3] += d;
}

void md5_pad(MD5 *md5) {
    unsigned int i;
    
    i = md5 -> msg_len;
    md5 -> message[i++] = 0x80;
    
    while (i < 64) {
        md5 -> message[i++] = 0x00;
    }
    md5 -> message[56] = md5 -> msg_len * 8;
}


void md5_bigendian(MD5 *md5, unsigned char final[]) {
    
    unsigned int m[4],n[4],o[4],p[4];
    unsigned int i,j;
    
    for(i = 0, j = 0; i < 4; i++, j += 4){
        m[i] = md5 -> blocks[i];
        n[i] = md5 -> blocks[i];
        o[i] = md5 -> blocks[i];
        p[i] = md5 -> blocks[i];
        final[j] = (m[i] & 0x000000ff);
        final[j+1] = ((n[i] >> 8) & 0x0000ff);
        final[j+2] = ((o[i] >> 16) & 0x00ff);
        final[j+3] = ((p[i] >> 24) & 0xff);
    }
}

void md5_print(unsigned char final[]) {
    int idx;
    for (idx=0; idx < 16; idx++)
        printf("%02x",final[idx]);
    printf("\n");
}

#endif /* md5_original_h */


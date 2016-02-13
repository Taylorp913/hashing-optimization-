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

// Used for shorter declarations
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

unsigned char lower[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
unsigned char upper[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


// Initial first block values
uint32_t ai = 0x67452301;
uint32_t bi = 0xefcdab89;
uint32_t ci = 0x98badcfe;
uint32_t di = 0x10325476;
uint32_t hd1,hd2,hd3,hd4,hd5,hd6,hd7,hd8;

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


// Values for the T[i] portion which is 2^32*abs(sin(i))
//uint32_t T[64] = {
//    3614090360, 3905402711, 606105819, 3250441967, 4118548399, 1200080427, 2821735955, 4249261313,
//    1770035416, 2336552880, 4294925233, 2304563135, 1804603682, 4254626196, 2792965006, 1236535329,
//    
//    4129170786, 3225465665, 643717714, 3921069995, 3593408606, 38016084, 3634488961, 3889429449,
//    568446438, 3275163606, 4107603335, 1163531501, 2850285829, 4243563513, 1735328473, 2368359562,
//    
//    4294588738, 2272392834, 1839030562, 4259657740, 2763975236, 1272893353, 4139469664, 3200236656,
//    681279175, 3936430074, 3572445317, 76029189, 3654602810, 3873151461, 530742521, 3299628645,
//    
//    4096336452, 1126891416, 2878612391, 4237533241, 1700485572, 2399980690, 4293915774, 2240044497,
//    1873313359, 4264355553, 2734768917, 1309151649, 4149444226, 3174756918, 718787260, 3951481746,
//};

uint T[64] = {
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
uint S[64] = {
    7, 12, 17, 22,  7, 12, 17, 22,
    7, 12, 17, 22,  7, 12, 17, 22,
    
    5, 9, 14, 20,  5, 9, 14, 20,
    5, 9, 14, 20,  5, 9, 14, 20,
    
    4, 11, 16, 23,  4, 11, 16, 23,
    4, 11, 16, 23,  4, 11, 16, 23,
    
    6, 10, 15, 21,  6, 10, 15, 21,
    6, 10, 15, 21,  6, 10, 15, 21
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
    uint blocks0[4];
    uint blocks1[4];
    uint blocks2[4];
    uint blocks3[4];
//    const __m128i message_avx;
//    const __m128i blocks_avx;
} MD5;

// Initialize struct elements
void md5_initialize(MD5 *md5)
{
    // LENGTH 0_3
    md5 -> msg_len0 = 0;
    md5 -> msg_len1 = 0;
    md5 -> msg_len2 = 0;
    md5 -> msg_len3 = 0;
    
    // BLOCK 0
    md5 -> blocks0[0] = ai;
    md5 -> blocks0[1] = bi;
    md5 -> blocks0[2] = ci;
    md5 -> blocks0[3] = di;
    
    // BLOCK 1
    md5 -> blocks1[0] = ai;
    md5 -> blocks1[1] = bi;
    md5 -> blocks1[2] = ci;
    md5 -> blocks1[3] = di;
    
    // BLOCK 2
    md5 -> blocks2[0] = ai;
    md5 -> blocks2[1] = bi;
    md5 -> blocks2[2] = ci;
    md5 -> blocks2[3] = di;
    
    // BLOCK 3
    md5 -> blocks3[0] = ai;
    md5 -> blocks3[1] = bi;
    md5 -> blocks3[2] = ci;
    md5 -> blocks3[3] = di;
}


// Set the input message to be in the struct
void md5_set(MD5 *md5, uchar pass0[], uchar pass1[], uchar pass2[], uchar pass3[], ulong length0, ulong length1, ulong length2, ulong length3){
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
void md5_pad(MD5 *md5){
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


void md5_manipulate(MD5 *md5, uchar message0[], uchar message1[], uchar message2[], uchar message3[]) {
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
    
    // Store all initial values of a,b,c,d into their respective variables for manipulation
    
    // Message 0
    a = md5 -> blocks0[0];
    b = md5 -> blocks0[1];
    c = md5 -> blocks0[2];
    d = md5 -> blocks0[3];
    
    FF(a, b, c, d, msg0[0],  S[0],  T[0]);
    FF(d, a, b, c, msg0[1],  S[1],  T[1]);
    FF(c, d, a, b, msg0[2],  S[2],  T[2]);
    FF(b, c, d, a, msg0[3],  S[3],  T[3]);
    FF(a, b, c, d, msg0[4],  S[4],  T[4]);
    FF(d, a, b, c, msg0[5],  S[5],  T[5]);
    FF(c, d, a, b, msg0[6],  S[6],  T[6]);
    FF(b, c, d, a, msg0[7],  S[7],  T[7]);
    FF(a, b, c, d, msg0[8],  S[8],  T[8]);
    FF(d, a, b, c, msg0[9],  S[9],  T[9]);
    FF(c, d, a, b, msg0[10], S[10], T[10]);
    FF(b, c, d, a, msg0[11], S[11], T[11]);
    FF(a, b, c, d, msg0[12], S[12], T[12]);
    FF(d, a, b, c, msg0[13], S[13], T[13]);
    FF(c, d, a, b, msg0[14], S[14], T[14]);
    FF(b, c, d, a, msg0[15], S[15], T[15]);
    
    GG(a, b, c, d, msg0[1],  S[16], T[16]);
    GG(d, a, b, c, msg0[6],  S[17], T[17]);
    GG(c, d, a, b, msg0[11], S[18], T[18]);
    GG(b, c, d, a, msg0[0],  S[19], T[19]);
    GG(a, b, c, d, msg0[5],  S[20], T[20]);
    GG(d, a, b, c, msg0[10], S[21], T[21]);
    GG(c, d, a, b, msg0[15], S[22], T[22]);
    GG(b, c, d, a, msg0[4],  S[23], T[23]);
    GG(a, b, c, d, msg0[9],  S[24], T[24]);
    GG(d, a, b, c, msg0[14], S[25], T[25]);
    GG(c, d, a, b, msg0[3],  S[26], T[26]);
    GG(b, c, d, a, msg0[8],  S[27], T[27]);
    GG(a, b, c, d, msg0[13], S[28], T[28]);
    GG(d, a, b, c, msg0[2],  S[29], T[29]);
    GG(c, d, a, b, msg0[7],  S[30], T[30]);
    GG(b, c, d, a, msg0[12], S[31], T[31]);
    
    HH(a, b, c, d, msg0[5],  S[32], T[32]);
    HH(d, a, b, c, msg0[8],  S[33], T[33]);
    HH(c, d, a, b, msg0[11], S[34], T[34]);
    HH(b, c, d, a, msg0[14], S[35], T[35]);
    HH(a, b, c, d, msg0[1],  S[36], T[36]);
    HH(d, a, b, c, msg0[4],  S[37], T[37]);
    HH(c, d, a, b, msg0[7],  S[38], T[38]);
    HH(b, c, d, a, msg0[10], S[39], T[39]);
    HH(a, b, c, d, msg0[13], S[40], T[40]);
    HH(d, a, b, c, msg0[0],  S[41], T[41]);
    HH(c, d, a, b, msg0[3],  S[42], T[42]);
    HH(b, c, d, a, msg0[6],  S[43], T[43]);
    HH(a, b, c, d, msg0[9],  S[44], T[44]);
    HH(d, a, b, c, msg0[12], S[45], T[45]);
    HH(c, d, a, b, msg0[15], S[46], T[46]);
    HH(b, c, d, a, msg0[2],  S[47], T[47]);
    
    II(a, b, c, d, msg0[0],  S[48], T[48]);
    II(d, a, b, c, msg0[7],  S[49], T[49]);
    II(c, d, a, b, msg0[14], S[50], T[50]);
    II(b, c, d, a, msg0[5],  S[51], T[51]);
    II(a, b, c, d, msg0[12], S[52], T[52]);
    II(d, a, b, c, msg0[3],  S[53], T[53]);
    II(c, d, a, b, msg0[10], S[54], T[54]);
    II(b, c, d, a, msg0[1],  S[55], T[55]);
    II(a, b, c, d, msg0[8],  S[56], T[56]);
    II(d, a, b, c, msg0[15], S[57], T[57]);
    II(c, d, a, b, msg0[6],  S[58], T[58]);
    II(b, c, d, a, msg0[13], S[59], T[59]);
    II(a, b, c, d, msg0[4],  S[60], T[60]);
    II(d, a, b, c, msg0[11], S[61], T[61]);
    II(c, d, a, b, msg0[2],  S[62], T[62]);
    II(b, c, d, a, msg0[9],  S[63], T[63]);
    
    md5->blocks0[0] += a;
    md5->blocks0[1] += b;
    md5->blocks0[2] += c;
    md5->blocks0[3] += d;
    
    // Message 1
    a = md5 -> blocks1[0];
    b = md5 -> blocks1[1];
    c = md5 -> blocks1[2];
    d = md5 -> blocks1[3];
    
    FF(a, b, c, d, msg1[0],  S[0],  T[0]);
    FF(d, a, b, c, msg1[1],  S[1],  T[1]);
    FF(c, d, a, b, msg1[2],  S[2],  T[2]);
    FF(b, c, d, a, msg1[3],  S[3],  T[3]);
    FF(a, b, c, d, msg1[4],  S[4],  T[4]);
    FF(d, a, b, c, msg1[5],  S[5],  T[5]);
    FF(c, d, a, b, msg1[6],  S[6],  T[6]);
    FF(b, c, d, a, msg1[7],  S[7],  T[7]);
    FF(a, b, c, d, msg1[8],  S[8],  T[8]);
    FF(d, a, b, c, msg1[9],  S[9],  T[9]);
    FF(c, d, a, b, msg1[10], S[10], T[10]);
    FF(b, c, d, a, msg1[11], S[11], T[11]);
    FF(a, b, c, d, msg1[12], S[12], T[12]);
    FF(d, a, b, c, msg1[13], S[13], T[13]);
    FF(c, d, a, b, msg1[14], S[14], T[14]);
    FF(b, c, d, a, msg1[15], S[15], T[15]);
    
    GG(a, b, c, d, msg1[1],  S[16], T[16]);
    GG(d, a, b, c, msg1[6],  S[17], T[17]);
    GG(c, d, a, b, msg1[11], S[18], T[18]);
    GG(b, c, d, a, msg1[0],  S[19], T[19]);
    GG(a, b, c, d, msg1[5],  S[20], T[20]);
    GG(d, a, b, c, msg1[10], S[21], T[21]);
    GG(c, d, a, b, msg1[15], S[22], T[22]);
    GG(b, c, d, a, msg1[4],  S[23], T[23]);
    GG(a, b, c, d, msg1[9],  S[24], T[24]);
    GG(d, a, b, c, msg1[14], S[25], T[25]);
    GG(c, d, a, b, msg1[3],  S[26], T[26]);
    GG(b, c, d, a, msg1[8],  S[27], T[27]);
    GG(a, b, c, d, msg1[13], S[28], T[28]);
    GG(d, a, b, c, msg1[2],  S[29], T[29]);
    GG(c, d, a, b, msg1[7],  S[30], T[30]);
    GG(b, c, d, a, msg1[12], S[31], T[31]);
    
    HH(a, b, c, d, msg1[5],  S[32], T[32]);
    HH(d, a, b, c, msg1[8],  S[33], T[33]);
    HH(c, d, a, b, msg1[11], S[34], T[34]);
    HH(b, c, d, a, msg1[14], S[35], T[35]);
    HH(a, b, c, d, msg1[1],  S[36], T[36]);
    HH(d, a, b, c, msg1[4],  S[37], T[37]);
    HH(c, d, a, b, msg1[7],  S[38], T[38]);
    HH(b, c, d, a, msg1[10], S[39], T[39]);
    HH(a, b, c, d, msg1[13], S[40], T[40]);
    HH(d, a, b, c, msg1[0],  S[41], T[41]);
    HH(c, d, a, b, msg1[3],  S[42], T[42]);
    HH(b, c, d, a, msg1[6],  S[43], T[43]);
    HH(a, b, c, d, msg1[9],  S[44], T[44]);
    HH(d, a, b, c, msg1[12], S[45], T[45]);
    HH(c, d, a, b, msg1[15], S[46], T[46]);
    HH(b, c, d, a, msg1[2],  S[47], T[47]);
    
    II(a, b, c, d, msg1[0],  S[48], T[48]);
    II(d, a, b, c, msg1[7],  S[49], T[49]);
    II(c, d, a, b, msg1[14], S[50], T[50]);
    II(b, c, d, a, msg1[5],  S[51], T[51]);
    II(a, b, c, d, msg1[12], S[52], T[52]);
    II(d, a, b, c, msg1[3],  S[53], T[53]);
    II(c, d, a, b, msg1[10], S[54], T[54]);
    II(b, c, d, a, msg1[1],  S[55], T[55]);
    II(a, b, c, d, msg1[8],  S[56], T[56]);
    II(d, a, b, c, msg1[15], S[57], T[57]);
    II(c, d, a, b, msg1[6],  S[58], T[58]);
    II(b, c, d, a, msg1[13], S[59], T[59]);
    II(a, b, c, d, msg1[4],  S[60], T[60]);
    II(d, a, b, c, msg1[11], S[61], T[61]);
    II(c, d, a, b, msg1[2],  S[62], T[62]);
    II(b, c, d, a, msg1[9],  S[63], T[63]);
    
    md5->blocks1[0] += a;
    md5->blocks1[1] += b;
    md5->blocks1[2] += c;
    md5->blocks1[3] += d;
    
    // Message 2
    a = md5 -> blocks2[0];
    b = md5 -> blocks2[1];
    c = md5 -> blocks2[2];
    d = md5 -> blocks2[3];
    
    FF(a, b, c, d, msg2[0],  S[0],  T[0]);
    FF(d, a, b, c, msg2[1],  S[1],  T[1]);
    FF(c, d, a, b, msg2[2],  S[2],  T[2]);
    FF(b, c, d, a, msg2[3],  S[3],  T[3]);
    FF(a, b, c, d, msg2[4],  S[4],  T[4]);
    FF(d, a, b, c, msg2[5],  S[5],  T[5]);
    FF(c, d, a, b, msg2[6],  S[6],  T[6]);
    FF(b, c, d, a, msg2[7],  S[7],  T[7]);
    FF(a, b, c, d, msg2[8],  S[8],  T[8]);
    FF(d, a, b, c, msg2[9],  S[9],  T[9]);
    FF(c, d, a, b, msg2[10], S[10], T[10]);
    FF(b, c, d, a, msg2[11], S[11], T[11]);
    FF(a, b, c, d, msg2[12], S[12], T[12]);
    FF(d, a, b, c, msg2[13], S[13], T[13]);
    FF(c, d, a, b, msg2[14], S[14], T[14]);
    FF(b, c, d, a, msg2[15], S[15], T[15]);
    
    GG(a, b, c, d, msg2[1],  S[16], T[16]);
    GG(d, a, b, c, msg2[6],  S[17], T[17]);
    GG(c, d, a, b, msg2[11], S[18], T[18]);
    GG(b, c, d, a, msg2[0],  S[19], T[19]);
    GG(a, b, c, d, msg2[5],  S[20], T[20]);
    GG(d, a, b, c, msg2[10], S[21], T[21]);
    GG(c, d, a, b, msg2[15], S[22], T[22]);
    GG(b, c, d, a, msg2[4],  S[23], T[23]);
    GG(a, b, c, d, msg2[9],  S[24], T[24]);
    GG(d, a, b, c, msg2[14], S[25], T[25]);
    GG(c, d, a, b, msg2[3],  S[26], T[26]);
    GG(b, c, d, a, msg2[8],  S[27], T[27]);
    GG(a, b, c, d, msg2[13], S[28], T[28]);
    GG(d, a, b, c, msg2[2],  S[29], T[29]);
    GG(c, d, a, b, msg2[7],  S[30], T[30]);
    GG(b, c, d, a, msg2[12], S[31], T[31]);
    
    HH(a, b, c, d, msg2[5],  S[32], T[32]);
    HH(d, a, b, c, msg2[8],  S[33], T[33]);
    HH(c, d, a, b, msg2[11], S[34], T[34]);
    HH(b, c, d, a, msg2[14], S[35], T[35]);
    HH(a, b, c, d, msg2[1],  S[36], T[36]);
    HH(d, a, b, c, msg2[4],  S[37], T[37]);
    HH(c, d, a, b, msg2[7],  S[38], T[38]);
    HH(b, c, d, a, msg2[10], S[39], T[39]);
    HH(a, b, c, d, msg2[13], S[40], T[40]);
    HH(d, a, b, c, msg2[0],  S[41], T[41]);
    HH(c, d, a, b, msg2[3],  S[42], T[42]);
    HH(b, c, d, a, msg2[6],  S[43], T[43]);
    HH(a, b, c, d, msg2[9],  S[44], T[44]);
    HH(d, a, b, c, msg2[12], S[45], T[45]);
    HH(c, d, a, b, msg2[15], S[46], T[46]);
    HH(b, c, d, a, msg2[2],  S[47], T[47]);
    
    II(a, b, c, d, msg2[0],  S[48], T[48]);
    II(d, a, b, c, msg2[7],  S[49], T[49]);
    II(c, d, a, b, msg2[14], S[50], T[50]);
    II(b, c, d, a, msg2[5],  S[51], T[51]);
    II(a, b, c, d, msg2[12], S[52], T[52]);
    II(d, a, b, c, msg2[3],  S[53], T[53]);
    II(c, d, a, b, msg2[10], S[54], T[54]);
    II(b, c, d, a, msg2[1],  S[55], T[55]);
    II(a, b, c, d, msg2[8],  S[56], T[56]);
    II(d, a, b, c, msg2[15], S[57], T[57]);
    II(c, d, a, b, msg2[6],  S[58], T[58]);
    II(b, c, d, a, msg2[13], S[59], T[59]);
    II(a, b, c, d, msg2[4],  S[60], T[60]);
    II(d, a, b, c, msg2[11], S[61], T[61]);
    II(c, d, a, b, msg2[2],  S[62], T[62]);
    II(b, c, d, a, msg2[9],  S[63], T[63]);
    
    md5->blocks2[0] += a;
    md5->blocks2[1] += b;
    md5->blocks2[2] += c;
    md5->blocks2[3] += d;
    
    // Message 3
    a = md5 -> blocks3[0];
    b = md5 -> blocks3[1];
    c = md5 -> blocks3[2];
    d = md5 -> blocks3[3];
    
    FF(a, b, c, d, msg3[0],  S[0],  T[0]);
    FF(d, a, b, c, msg3[1],  S[1],  T[1]);
    FF(c, d, a, b, msg3[2],  S[2],  T[2]);
    FF(b, c, d, a, msg3[3],  S[3],  T[3]);
    FF(a, b, c, d, msg3[4],  S[4],  T[4]);
    FF(d, a, b, c, msg3[5],  S[5],  T[5]);
    FF(c, d, a, b, msg3[6],  S[6],  T[6]);
    FF(b, c, d, a, msg3[7],  S[7],  T[7]);
    FF(a, b, c, d, msg3[8],  S[8],  T[8]);
    FF(d, a, b, c, msg3[9],  S[9],  T[9]);
    FF(c, d, a, b, msg3[10], S[10], T[10]);
    FF(b, c, d, a, msg3[11], S[11], T[11]);
    FF(a, b, c, d, msg3[12], S[12], T[12]);
    FF(d, a, b, c, msg3[13], S[13], T[13]);
    FF(c, d, a, b, msg3[14], S[14], T[14]);
    FF(b, c, d, a, msg3[15], S[15], T[15]);
    
    GG(a, b, c, d, msg3[1],  S[16], T[16]);
    GG(d, a, b, c, msg3[6],  S[17], T[17]);
    GG(c, d, a, b, msg3[11], S[18], T[18]);
    GG(b, c, d, a, msg3[0],  S[19], T[19]);
    GG(a, b, c, d, msg3[5],  S[20], T[20]);
    GG(d, a, b, c, msg3[10], S[21], T[21]);
    GG(c, d, a, b, msg3[15], S[22], T[22]);
    GG(b, c, d, a, msg3[4],  S[23], T[23]);
    GG(a, b, c, d, msg3[9],  S[24], T[24]);
    GG(d, a, b, c, msg3[14], S[25], T[25]);
    GG(c, d, a, b, msg3[3],  S[26], T[26]);
    GG(b, c, d, a, msg3[8],  S[27], T[27]);
    GG(a, b, c, d, msg3[13], S[28], T[28]);
    GG(d, a, b, c, msg3[2],  S[29], T[29]);
    GG(c, d, a, b, msg3[7],  S[30], T[30]);
    GG(b, c, d, a, msg3[12], S[31], T[31]);
    
    HH(a, b, c, d, msg3[5],  S[32], T[32]);
    HH(d, a, b, c, msg3[8],  S[33], T[33]);
    HH(c, d, a, b, msg3[11], S[34], T[34]);
    HH(b, c, d, a, msg3[14], S[35], T[35]);
    HH(a, b, c, d, msg3[1],  S[36], T[36]);
    HH(d, a, b, c, msg3[4],  S[37], T[37]);
    HH(c, d, a, b, msg3[7],  S[38], T[38]);
    HH(b, c, d, a, msg3[10], S[39], T[39]);
    HH(a, b, c, d, msg3[13], S[40], T[40]);
    HH(d, a, b, c, msg3[0],  S[41], T[41]);
    HH(c, d, a, b, msg3[3],  S[42], T[42]);
    HH(b, c, d, a, msg3[6],  S[43], T[43]);
    HH(a, b, c, d, msg3[9],  S[44], T[44]);
    HH(d, a, b, c, msg3[12], S[45], T[45]);
    HH(c, d, a, b, msg3[15], S[46], T[46]);
    HH(b, c, d, a, msg3[2],  S[47], T[47]);
    
    II(a, b, c, d, msg3[0],  S[48], T[48]);
    II(d, a, b, c, msg3[7],  S[49], T[49]);
    II(c, d, a, b, msg3[14], S[50], T[50]);
    II(b, c, d, a, msg3[5],  S[51], T[51]);
    II(a, b, c, d, msg3[12], S[52], T[52]);
    II(d, a, b, c, msg3[3],  S[53], T[53]);
    II(c, d, a, b, msg3[10], S[54], T[54]);
    II(b, c, d, a, msg3[1],  S[55], T[55]);
    II(a, b, c, d, msg3[8],  S[56], T[56]);
    II(d, a, b, c, msg3[15], S[57], T[57]);
    II(c, d, a, b, msg3[6],  S[58], T[58]);
    II(b, c, d, a, msg3[13], S[59], T[59]);
    II(a, b, c, d, msg3[4],  S[60], T[60]);
    II(d, a, b, c, msg3[11], S[61], T[61]);
    II(c, d, a, b, msg3[2],  S[62], T[62]);
    II(b, c, d, a, msg3[9],  S[63], T[63]);
    
    md5->blocks3[0] += a;
    md5->blocks3[1] += b;
    md5->blocks3[2] += c;
    md5->blocks3[3] += d;
    
}


void md5_bigendian(MD5 *md5, uchar final0[], uchar final1[], uchar final2[], uchar final3[]) {
    
    uint m[4],n[4],o[4],p[4];
    uint i,j;
    
    for(i = 0, j = 0; i < 4; i++, j += 4){
        m[i] = md5 -> blocks0[i];
        n[i] = md5 -> blocks0[i];
        o[i] = md5 -> blocks0[i];
        p[i] = md5 -> blocks0[i];
        final0[j] = (m[i] & 0x000000ff);
        final0[j+1] = ((n[i] >> 8) & 0x0000ff);
        final0[j+2] = ((o[i] >> 16) & 0x00ff);
        final0[j+3] = ((p[i] >> 24) & 0xff);
    }
    
    for(i = 0, j = 0; i < 4; i++, j += 4){
        m[i] = md5 -> blocks1[i];
        n[i] = md5 -> blocks1[i];
        o[i] = md5 -> blocks1[i];
        p[i] = md5 -> blocks1[i];
        final1[j] = (m[i] & 0x000000ff);
        final1[j+1] = ((n[i] >> 8) & 0x0000ff);
        final1[j+2] = ((o[i] >> 16) & 0x00ff);
        final1[j+3] = ((p[i] >> 24) & 0xff);
    }
    
    for(i = 0, j = 0; i < 4; i++, j += 4){
        m[i] = md5 -> blocks2[i];
        n[i] = md5 -> blocks2[i];
        o[i] = md5 -> blocks2[i];
        p[i] = md5 -> blocks2[i];
        final2[j] = (m[i] & 0x000000ff);
        final2[j+1] = ((n[i] >> 8) & 0x0000ff);
        final2[j+2] = ((o[i] >> 16) & 0x00ff);
        final2[j+3] = ((p[i] >> 24) & 0xff);
    }
    
    for(i = 0, j = 0; i < 4; i++, j += 4){
        m[i] = md5 -> blocks3[i];
        n[i] = md5 -> blocks3[i];
        o[i] = md5 -> blocks3[i];
        p[i] = md5 -> blocks3[i];
        final3[j] = (m[i] & 0x000000ff);
        final3[j+1] = ((n[i] >> 8) & 0x0000ff);
        final3[j+2] = ((o[i] >> 16) & 0x00ff);
        final3[j+3] = ((p[i] >> 24) & 0xff);
    }

}

void md5_print(unsigned char final[]) {
    int idx;
    for (idx=0; idx < 16; idx++)
        printf("%x",final[idx]);
    printf("\n");
}


#endif /* md5_h */

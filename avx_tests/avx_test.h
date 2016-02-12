
#ifndef avx_test_h
#define avx_test_h

#include "immintrin.h"
#include "emmintrin.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

// Used for shorter declarations
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

// Initial first block values
uint32_t ai = 0x67452301;
uint32_t bi = 0xefcdab89;
uint32_t ci = 0x98badcfe;
uint32_t di = 0x10325476;

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
    const __m128i message_avx;
    const __m128i blocks_avx;
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
void md5_set(MD5 *md5, uchar pass0[], uchar pass1[], uchar pass2[], uchar pass3[], ulong length0, ulong length1, ulong length2, ulong length3,){
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

void md5_manipulate(MD5 *md5, unsigned char message[]) {
    uint a,b,c,d;
    uint msg0[16], msg1[16], msg2[16], msg3[16];
    uint i,j;
    
    // For loop changes from big endian to little endian
    for (i = 0, j = 0; i < 16; i++, j += 4) {
        msg[i] = (message[j]) + (message[j + 1] << 8) + (message[j + 2] << 16) + (message[j + 3] << 24);
    }




  }


    
    // Store all initial values of a,b,c,d into their respective variables for manipulation
    a = md5 -> blocks[0];
    b = md5 -> blocks[1];
    c = md5 -> blocks[2];
    d = md5 -> blocks[3];









    void avx_and(unsigned* dst, const unsigned* src, unsigned block_size)
{
      const __m128i* wrd_ptr = (__m128i*)src;
      const __m128i* wrd_end = (__m128i*)(src + block_size);
      __m128i* dst_ptr = (__m128i*)dst;

      do
      {
           __m128i xmm1 = _mm_load_si128(wrd_ptr);
           __m128i xmm2 = _mm_load_si128(dst_ptr);
                
           __m128i xmm1 = _mm_and_si128(xmm1, xmm2);     //  AND  4 32-bit words
           _mm_store_si128(dst_ptr, xmm1);
           ++dst_ptr;
           ++wrd_ptr;

      } while (wrd_ptr < wrd_end);
}


#endif /* avx_test_h */


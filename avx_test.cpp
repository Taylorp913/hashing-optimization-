unsigned int as0,as1,as2,as3,as4,as5,as6,as7;
unsigned int s0,s1,s2,s3,s4,s5,s6,s7;


#define F(x, y, z) ((x & y) | (~x & z))
// #define G(x, y, z) ((x & z) | (y & ~z))
// #define H(x, y, z) ((x ^ y ^ z))
// #define I(x, y, z) ((y ^ (x | ~z)))
#define SHIFT(a, s) ((a << s) | (a >> (32 - s)))

// #define FF(a, b, c, d, m, s, t)\
// a = (a + F(b, c, d) + m + t);\
// a = (SHIFT(a, s));\
// a = (b + a);

#define JJ(a, b, c, d, m, s, t)\
a = (a + F(b, c, d) + m + t);\
as0 = a[0]; as1 = a[1]; as2 = a[2]; as3 = a[3]; as4 = a[4]; as5 = a[5]; as6 = a[6]; as7 = a[7];\
s0 = SHIFT(as0, S[0]); s1 = SHIFT(as1, S[0]); s2 = SHIFT(as2, S[0]); s3 = SHIFT(as3, S[0]);\
s4 = SHIFT(as4, S[0]); s5 = SHIFT(as5, S[0]); s6 = SHIFT(as6, S[0]); s7 = SHIFT(as7, S[0]);\
a = _mm256_setr_epi32(s0,s1,s2,s3,s4,s5,s6,s7);\
//a = (s0,s1,s2,s3,s4,s5,s6,s7);\
a = (b + a);

unsigned int S[64] = {
    7, 12, 17, 22,  7, 12, 17, 22,
    7, 12, 17, 22,  7, 12, 17, 22,
    
    5, 9, 14, 20,  5, 9, 14, 20,
    5, 9, 14, 20,  5, 9, 14, 20,
    
    4, 11, 16, 23,  4, 11, 16, 23,
    4, 11, 16, 23,  4, 11, 16, 23,
    
    6, 10, 15, 21,  6, 10, 15, 21,
    6, 10, 15, 21,  6, 10, 15, 21
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
//#include <immintrin.h>
#include <emmintrin.h>

using namespace std;

int main(int argc, char *argv[]) {

    // uint32_t ai = 0x67452301;
    // uint32_t bi = 0xefcdab89;
    // uint32_t ci = 0x98badcfe;
    // uint32_t di = 0x10325476;
    uint32_t bi = 4023233417; // 0xefcdab89
    uint32_t ci = 2562383102; // 0x98badcfe
    uint32_t tot;

    tot = (bi & ci);
    printf("Hex value 'b': %x\n",bi);
    printf("Int value 'b': %u\n",bi);
    printf("Hex value 'c': %x\n",ci);
    printf("Int value 'c': %u\n",ci);
    // printf("Hex total: %x\n",tot);
    // printf("Int total: %u\n",tot);

    __m128i b = _mm_setr_epi32 (4023233417,4023233417,4023233417,4023233417);
    __m128i c = _mm_setr_epi32 (2562383102,2562383102,2562383102,2562383102);
    __m128i a = _mm_and_si128 (b, c);

    // printf("Hex value 'b[0]': %llx %llx %llx %llx\n",b);
    // printf("Int value 'b[0]': %lli %lli %lli %lli\n",b);
    // printf("Hex value 'c[0]': %llx %llx %llx %llx\n",c);
    // printf("Int value 'c[0]': %lli %lli %lli %lli\n",c);

    printf("Hex value 'b[0]': %llx %llx %llx %llx\n",b[0],b[1],b[2],b[3]);
    printf("Int value 'b[0]': %lli %lli %lli %lli\n",b[0],b[1],b[2],b[3]);
    printf("Hex value 'c[0]': %llx %llx %llx %llx\n",c[0],c[1],c[2],c[3]);
    printf("Int value 'c[0]': %lli %lli %lli %lli\n",c[0],c[1],c[2],c[3]);

    // printf("Hex total: %llx\n",c[3]);
    // printf("Int total: %llu\n",c[3]);





    // uint32_t ai = 0x67452301;
    // uint32_t bi = 4023233417; // 0xefcdab89
    // uint32_t ci = 2562383102; // 0x98badcfe
    // uint32_t di = 0x10325476;
    // uint32_t T = 0xd76aa478;
    // uint32_t tot;
__m256i hd1, hd2, hd3, hd4, out1, out2, Sf, Sf1, f1, f2;
unsigned int as0,as1,as2,as3,as4,as5,as6,as7;
unsigned int s0,s1,s2,s3,s4,s5,s6,s7;


    // tot = (bi & ci);
    // printf("Hex value 'b': %x\n",bi);
    // printf("Int value 'b': %u\n",bi);
    // printf("Hex value 'c': %x\n",ci);
    // printf("Int value 'c': %u\n",ci);
    // printf("Hex total: %x\n",tot);
    // printf("Int total: %u\n",tot);

  __m256i a = _mm256_setr_epi32(0x67452301,0x67452301,0x67452301,0x67452301,0x67452301,0x67452301,0x67452301,0x67452301);
  __m256i b = _mm256_setr_epi32(0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89,0xefcdab89);
  __m256i c = _mm256_setr_epi32(0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe,0x98badcfe);
  __m256i d = _mm256_setr_epi32(0x10325476,0x10325476,0x10325476,0x10325476,0x10325476,0x10325476,0x10325476,0x10325476);
  __m256i T = _mm256_setr_epi32(0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478,0xd76aa478);
  //__m256i S = _mm256_setr_epi32(7,7,7,7,7,7,7,7);
  __m256i m = _mm256_setr_epi32(0x61616161,0x62616161,0x63616161,0x64616161,0x65616161,0x66616161,0x67616161,0x68616161);
  __m256i n = _mm256_setr_epi32(0x61616161,0x62616161,0x63616161,0x64616161,0x65616161,0x66616161,0x67616161,0x68616161);
  




  Sf = (a + F(b,c,d) + n + T);
  int* res1 = (int*)&Sf;
  printf("Sf_old: %x %x %x %x %x %x %x %x\n",res1[0],res1[1],res1[2],res1[3],res1[4],res1[5],res1[6],res1[7]);

  as0 = Sf[0];
  s0 = SHIFT(as0, S[0]);
  printf("as0_1st = %x\n", as0);
  printf("s0_1st = %x\n", s0);

  f1 = b + _mm256_setr_epi32(s0,0,0,0,0,0,0,0);
  int* res2 = (int*)&f1;
  printf("f1[0] = %x\n", res2[0]);

  //Sf1 = ((Sf[0] << S[0]) | (Sf[0] >> (32 - S[0])));








    return 0;
}

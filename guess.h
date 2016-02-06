//
//  guess.h
//  md5_project
//
//  Created by Taylor Peterson on 2/6/16.
//  Copyright © 2016 Taylor Peterson. All rights reserved.
//
// #ifndef md5_h
// #define md5_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <stdint.h>


//constructore for input data type
union Block
{
    uint64_t  _64[8];
    uint32_t  _32[16];
    uint8_t   _8[64];
    Block() // initialization
    {
        memset(&this->_8[0], 0, 64);
    };
};

#define transform_password( a,  b) {\
        hash._8[0x0] = (a>> 56) &0xff;\
        hash._8[0x1] = (a>> 48) &0xff;\
        hash._8[0x2] = (a>> 40) &0xff;\
        hash._8[0x3] = (a>> 32) &0xff;\
        hash._8[0x4] = (a>> 24) &0xff;\
        hash._8[0x5] = (a>> 16) &0xff;\
        hash._8[0x6] = (a>>  8) &0xff;\
        hash._8[0x7] = (a     ) &0xff;\
        hash._8[0x8] = (b>> 56) &0xff;\
        hash._8[0x9] = (b>> 48) &0xff;\
        hash._8[0xa] = (b>> 40) &0xff;\
        hash._8[0xb] = (b>> 32) &0xff;\
        hash._8[0xc] = (b>> 24) &0xff;\
        hash._8[0xd] = (b>> 16) &0xff;\
        hash._8[0xe] = (b>>  8) &0xff;\
        hash._8[0xf] = (b     ) &0xff;}
#define alph(a) ('a'+a)


void guess_print(union Block *in_block) {
    int idx;
    printf("%c",in_block->_8[0]);
    printf("%c",in_block->_8[1]);
    printf("%c",in_block->_8[2]);
    printf("%c",in_block->_8[3]);
    printf("%c",in_block->_8[4]);
    printf("%c",in_block->_8[5]);
    printf("%c",in_block->_8[6]);
    printf("%c",in_block->_8[7]);
    printf("\n");
}

void inc_guess() {
    
}




//The increment value for each alpha character in the password 1-26
// E10 = 26^10
#define E10 (uint64_t) 141167095653376
#define  E9 (uint64_t) 5429503678976
#define  E8 (uint64_t) 208827064576
#define  E7 (uint64_t) 8031810176
#define  E6 (uint64_t) 308915776
#define  E5 (uint64_t) 11881376
#define  E4 (uint64_t) 456976
#define  E3 (uint64_t) 17576
#define  E2 (uint64_t) 676
#define  E1 (uint64_t) 26

// D2 = E2+E1
#define D10 (uint64_t) 146813779497086
#define  D9 (uint64_t) 5646683843710
#define  D8 (uint64_t) 21718164734
#define  D7 (uint64_t) 8353082582
#define  D6 (uint64_t) 321272406
#define  D5 (uint64_t) 12356630
#define  D4 (uint64_t) 474552
#define  D3 (uint64_t) 18278
#define  D2 (uint64_t) 702
#define  D1 (uint64_t) 26

void write_pass(union Block *in_block, uint64_t i)
{
    int len;
    /*if (i < D1)
    {
        in_block->_8[0] = alph(i);
        len = 1;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D2)
    {
        in_block->_8[0] = alph((i - D1) % E1);
        in_block->_8[1] = alph((i - D1) / E1);
        len = 2;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D3)
    {
        in_block->_8[0] = alph((i - D2) % E1);
        in_block->_8[1] = alph((((i - D2) / E1) % E1) );
        in_block->_8[2] = alph((((i - D2) / E2) % E1));
        len = 3;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D4)
    {
        in_block->_8[0] = alph((i - D3) % E1);
        in_block->_8[1] = alph((((i - D3) / E1) % E1));
        in_block->_8[2] = alph((((i - D3) / E2) % E1));
        in_block->_8[3] = alph((((i - D3) / E3) % E1));
        len = 4;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D5)
    {
        in_block->_8[0] = alph((i - D4) % E1);
        in_block->_8[1] = alph((((i - D4) / E1) % E1));
        in_block->_8[2] = alph((((i - D4) / E2) % E1));
        in_block->_8[3] = alph((((i - D4) / E3) % E1));
        in_block->_8[4] = alph((((i - D4) / E4) % E1));
        len = 5;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }*/
    if (i < D6)
    {
        in_block->_8[0] = alph((i - D5) % E1);
        in_block->_8[1] = alph((((i - D5) / E1) % E1));
        in_block->_8[2] = alph((((i - D5) / E2) % E1));
        in_block->_8[3] = alph((((i - D5) / E3) % E1));
        in_block->_8[4] = alph((((i - D5) / E4) % E1));
        in_block->_8[5] = alph((((i - D5) / E5) % E1));
        len = 6;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D7)
    {

        in_block->_8[0] = alph((i-D6) % E1);
        in_block->_8[1] = alph((((i-D6) / E1) % E1));
        in_block->_8[2] = alph((((i-D6) / E2) % E1));
        in_block->_8[3] = alph((((i-D6) / E3) % E1));
        in_block->_8[4] = alph((((i-D6) / E4) % E1));
        in_block->_8[5] = alph((((i-D6) / E5) % E1));
        in_block->_8[6] = alph((((i-D6) / E6) % E1));
        len = 7;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D8)
    {
        in_block->_8[0] = alph((i - D7) % E1);
        in_block->_8[1] = alph((((i - D7) / E1) % E1));
        in_block->_8[2] = alph((((i - D7) / E2) % E1));
        in_block->_8[3] = alph((((i - D7) / E3) % E1));
        in_block->_8[4] = alph((((i - D7) / E4) % E1));
        in_block->_8[5] = alph((((i - D7) / E5) % E1));
        in_block->_8[6] = alph((((i - D7) / E6) % E1));
        in_block->_8[7] = alph((((i - D7) / E7) % E1));
        len = 8;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
    else if (i < D9)
    {
        in_block->_8[0] = alph((i - D8) % E1);
        in_block->_8[1] = alph((((i - D8) / E1) % E1));
        in_block->_8[2] = alph((((i - D8) / E2) % E1));
        in_block->_8[3] = alph((((i - D8) / E3) % E1));
        in_block->_8[4] = alph((((i - D8) / E4) % E1));
        in_block->_8[5] = alph((((i - D8) / E5) % E1));
        in_block->_8[6] = alph((((i - D8) / E6) % E1));
        in_block->_8[7] = alph((((i - D8) / E7) % E1));
        in_block->_8[8] = alph((((i - D8) / E8) % E1));
        len = 9;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
    else
    {
        in_block->_8[0] = alph((i - D9) % E1);
        in_block->_8[1] = alph((((i - D9) / E1) % E1));
        in_block->_8[2] = alph((((i - D9) / E2) % E1));
        in_block->_8[3] = alph((((i - D9) / E3) % E1));
        in_block->_8[4] = alph((((i - D9) / E4) % E1));
        in_block->_8[5] = alph((((i - D9) / E5) % E1));
        in_block->_8[6] = alph((((i - D9) / E6) % E1));
        in_block->_8[7] = alph((((i - D9) / E7) % E1));
        in_block->_8[8] = alph((((i - D9) / E8) % E1));
        in_block->_8[9] = alph((((i - D9) / E9) % E1));
        len = 10;
        in_block->_8[len] = 0x80;
        memset(&in_block->_8[len + 1], 0, 63 - len);
        in_block->_64[7] = len * 8;
    }
}

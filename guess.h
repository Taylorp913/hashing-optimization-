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
union Guess
{
    uint8_t   _8[64];
	uint32_t  _32[16];
	uint64_t  _64[8];

    Guess() // initialization
    {
        memset(&this->_8[0], 0, 64);
    };
};

#define alph(a) ('a'+a)


void guess_print(union Guess *guess) {
    int idx;
    printf("%c",guess->_8[0]);
    printf("%c",guess->_8[1]);
    printf("%c",guess->_8[2]);
    printf("%c",guess->_8[3]);
    printf("%c",guess->_8[4]);
    printf("%c",guess->_8[5]);
    printf("%c",guess->_8[6]);
    printf("%c",guess->_8[7]);
    printf("\n");
}

void inc_guess() {
    
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

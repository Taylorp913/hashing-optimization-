//
//  main.cpp
//  md5_project
//
//  Created by Danny Froerer on 1/26/16.
//  Copyright © 2016 Danny Froerer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include "avx_test_4.h"
#include "immintrin.h"
#include "emmintrin.h"

using namespace std;


int main(int argc, char *argv[]) {
    
    unsigned char hash0[16];
    unsigned char hash1[16];
    unsigned char hash2[16];
    unsigned char hash3[16];
    unsigned char pass0[] = "abcd"; // e2fc714c4727ee9395f324cd2e7f331f
    unsigned char pass1[] = "efgh"; // 1f7690ebdd9b4caf8fab49ca1757bf27
    unsigned char pass2[] = "ijkl"; // 09a0877d04abf8759f99adec02baf579
    unsigned char pass3[] = "mnop"; // e132e96a5ddad6da8b07bba6f6131fef
    
    MD5 md5;
    
    avx_initialize(&md5);
    avx_set(&md5,pass0,pass1,pass2,pass3,strlen((char*)pass0),strlen((char*)pass1),strlen((char*)pass2),strlen((char*)pass3));
    avx_pad(&md5);
    // avx_print(&md5,md5.message0);
    // avx_print(&md5,md5.message1);
    // avx_print(&md5,md5.message2);
    // avx_print(&md5,md5.message3);
    avx_manipulate_p1(&md5,md5.message0,md5.message1,md5.message2,md5.message3);
    avx_manipulate_p2(&md5);

    avx_bigendian(&md5,hash0,hash1,hash2,hash3);
    avx_print_char(hash0);
    avx_print_char(hash1);
    avx_print_char(hash2);
    avx_print_char(hash3);
    
    
    
    return 0;
}







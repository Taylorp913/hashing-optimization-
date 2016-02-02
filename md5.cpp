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
#include "md5.h"

using namespace std;


int main(int argc, char *argv[]) {
    
    unsigned char hash[16];
    unsigned char pass[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    MD5 md5;
    
    md5_initialize(&md5);
    md5_set(&md5,pass,strlen((char*)pass));
    md5_pad(&md5);
    md5_manipulate(&md5,md5.message);
    md5_bigendian(&md5,hash);
    md5_print(hash);
    
    //printf("Enter password: ");
    
    return 0;
}

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
#include <time.h>

using namespace std;

union Guess guess;

int main(int argc, char *argv[]) {
    uint64_t start = Digit5;//Digit5 is the start of the 6 digit space
	uint64_t end = Digit5+2000000;//Digit6 is end of 6 digit space
	uint64_t hashes = end - start;
	unsigned char hash[16];
    //unsigned char pass[] = "abcdefghijklmnopqrstuvwxyz";
    // Hash is: c3fcd3d76192e4007dfb496cca67e13b
    
    clock_t start_time, final_time;
    start_time = clock();

    MD5 md5;
    //md5_initialize(&md5);

    //for(uint64_t i = Digit5; i < Digit6; i++){//full test
    for(uint64_t i = start; i < end; i++){//short test
        increment_pass(&guess, i);
        //guess_print(&guess);
        //md5_set(&md5,pass,strlen((char*)pass));
        //md5_pad(&md5);
        //md5_initialize(&md5);
        md5_manipulate(&md5,&guess);
        md5_bigendian(&md5,hash);
        //md5_print(hash);
    }



    final_time = clock();
    //had to multiply by ten since the system had an incorect CLOCKS_PER_SEC value, possibly due to virtual machine
	printf("%i hashes\n", hashes);
	//printf("%i clocks per sec\n", CLOCKS_PER_SEC);
	printf("%f seconds\n",((float)difftime(final_time,start_time))/CLOCKS_PER_SEC);
	printf("%f hashes/seconds\n", hashes/(((float)difftime(final_time, start_time)) / CLOCKS_PER_SEC));

    return 0;
}

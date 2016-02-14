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
#include "md5.h"
#include <time.h>


//using namespace std;

union Guess guess;
union Guess output;
union Guess input;

#define input1 0x453e41d218e071cc//zzzzzz
#define input2 0xfb2d1c99ce23906a

//#define input1 0x035286ce31b311a5
//#define input2 0x08c2102022e3faa8

int main(int argc, char *argv[]) {
	uint64_t start = Digit6-1;//Digit5 is the start of the 6 digit space
	uint64_t end = Digit6;//Digit6 is end of 6 digit space
	uint64_t hashes = end - start;
	uint64_t cmp1, cmp2;
	uint64_t i;
	transform_input(input1, input2);


	clock_t start_time, final_time;
	start_time = clock();


	for (i = start; i < end; i++) {
		increment_pass(&guess, i);
		md5_manipulate(&output, &guess);
		//printf("  %s\n", (char *)guess._8);	
		
		cmp1 = output._64[0] ^ input._64[0];
		cmp2 = output._64[1] ^ input._64[1];
		
		if ((cmp1 | cmp2) == 0)
		{
			printf("Found the hash!\n");
			printf("  %s\n", (char *)guess._8);
			//exit(1);
		}

	}

	final_time = clock();
	//had to multiply by ten since the system had an incorect CLOCKS_PER_SEC value, possibly due to virtual machine
	printf("%f seconds\n", ((float)difftime(final_time, start_time)) / CLOCKS_PER_SEC);
	printf("%f hashes/seconds\n", hashes / (((float)difftime(final_time, start_time)) / CLOCKS_PER_SEC));



	return 0;
}

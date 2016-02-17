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
#include "md5_AVX.h"
#include <time.h>
#include <pthread.h>


union Guess guess;
union Guess guess2;
union Guess guess3;
union Guess guess4;
union Guess output;
union Guess input;

#define input1 0x453e41d218e071cc //zzzzzz
#define input2 0xfb2d1c99ce23906a

// Use for 4 threads
// #define  tbegin_1 (uint64_t) 12356630
// #define  tstop_1 (uint64_t) 89585574
// #define  tbegin_2 (uint64_t) 89585574
// #define  tstop_2 (uint64_t) 166814518
// #define  tbegin_3 (uint64_t) 166814518
// #define  tstop_3 (uint64_t) 244043462
// #define  tbegin_4 (uint64_t) 244043462
// #define  tstop_4 (uint64_t) 321272406

#define  tbegin_1 (uint64_t) 12356630
#define  tstop_1 (uint64_t) 50971102
#define  tbegin_2 (uint64_t) 50971102
#define  tstop_2 (uint64_t) 89585574
#define  tbegin_3 (uint64_t) 89585574
#define  tstop_3 (uint64_t) 128200046
#define  tbegin_4 (uint64_t) 128200046
#define  tstop_4 (uint64_t) 166814518
#define  tbegin_5 (uint64_t) 166814518
#define  tstop_5 (uint64_t) 205428990
#define  tbegin_6 (uint64_t) 205428990
#define  tstop_6 (uint64_t) 244043462
#define  tbegin_7 (uint64_t) 244043462
#define  tstop_7 (uint64_t) 282657934
#define  tbegin_8 (uint64_t) 282657934
#define  tstop_8 (uint64_t) 321272406

void *md5_thread_1();
void *md5_thread_2();
void *md5_thread_3();
void *md5_thread_4();
void *md5_thread_5();
void *md5_thread_6();
void *md5_thread_7();
void *md5_thread_8();


int main(int argc, char *argv[]) {
	uint64_t hashes = Digit6 - Digit5;
	uint64_t cmp1, cmp2, i;
	transform_input(input1, input2);

	time_t start_time, final_time;

	pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8;

	start_time = clock();
	
	(void) pthread_create(&thread1, NULL, md5_thread_1, NULL);
	(void) pthread_create(&thread2, NULL, md5_thread_2, NULL);
	(void) pthread_create(&thread3, NULL, md5_thread_3, NULL);
	(void) pthread_create(&thread4, NULL, md5_thread_4, NULL);
	(void) pthread_create(&thread5, NULL, md5_thread_5, NULL);
	(void) pthread_create(&thread6, NULL, md5_thread_6, NULL);
	(void) pthread_create(&thread7, NULL, md5_thread_7, NULL);
	(void) pthread_create(&thread8, NULL, md5_thread_8, NULL);

	(void) pthread_join(thread1, NULL);
	(void) pthread_join(thread2, NULL);
	(void) pthread_join(thread3, NULL);
	(void) pthread_join(thread4, NULL);
	(void) pthread_join(thread5, NULL);
	(void) pthread_join(thread6, NULL);
	(void) pthread_join(thread7, NULL);
	(void) pthread_join(thread8, NULL);

	final_time = clock();

	printf("%f seconds\n", (((float)difftime(final_time, start_time)) / (CLOCKS_PER_SEC)) / 8);
	printf("%f hashes/seconds\n", (hashes / (((float)difftime(final_time, start_time)) / CLOCKS_PER_SEC)) * 8);

	pthread_exit(NULL);
}

void *md5_thread_1(){
		uint64_t start = tbegin_1;
		uint64_t end = tstop_1;
		uint64_t cmp1, i;

		for (i = start; i < end; i+=4) {
		increment_pass(&guess, i);
		increment_pass(&guess2, i+1);
		increment_pass(&guess3, i+2);
		increment_pass(&guess4, i+3);

		md5_manipulate(&output, &guess,&guess2,&guess3,&guess4);

	}
	pthread_exit(NULL);
}

void *md5_thread_2(){
		uint64_t start = tbegin_2; 
		uint64_t end = tstop_2; 
		uint64_t cmp1, i;

		for (i = start; i < end; i+=4) {
		increment_pass(&guess, i);
		increment_pass(&guess2, i+1);
		increment_pass(&guess3, i+2);
		increment_pass(&guess4, i+3);

		md5_manipulate(&output, &guess,&guess2,&guess3,&guess4);

	}
	pthread_exit(NULL);
}

void *md5_thread_3(){
		uint64_t start = tbegin_3;
		uint64_t end = tstop_3;
		uint64_t cmp1, i;

		for (i = start; i < end; i+=4) {
		increment_pass(&guess, i);
		increment_pass(&guess2, i+1);
		increment_pass(&guess3, i+2);
		increment_pass(&guess4, i+3);

		md5_manipulate(&output, &guess,&guess2,&guess3,&guess4);

	}
	pthread_exit(NULL);
}

void *md5_thread_4(){
		uint64_t start = tbegin_4;
		uint64_t end = tstop_4;
		uint64_t cmp1, i;

		for (i = start; i < end; i+=4) {
		increment_pass(&guess, i);
		increment_pass(&guess2, i+1);
		increment_pass(&guess3, i+2);
		increment_pass(&guess4, i+3);

		md5_manipulate(&output, &guess,&guess2,&guess3,&guess4);

	}
	pthread_exit(NULL);
}

void *md5_thread_5(){
		uint64_t start = tbegin_5;
		uint64_t end = tstop_5;
		uint64_t cmp1, i;

		for (i = start; i < end; i+=4) {
		increment_pass(&guess, i);
		increment_pass(&guess2, i+1);
		increment_pass(&guess3, i+2);
		increment_pass(&guess4, i+3);

		md5_manipulate(&output, &guess,&guess2,&guess3,&guess4);

	}
	pthread_exit(NULL);
}

void *md5_thread_6(){
		uint64_t start = tbegin_6;
		uint64_t end = tstop_6;
		uint64_t cmp1, i;

		for (i = start; i < end; i+=4) {
		increment_pass(&guess, i);
		increment_pass(&guess2, i+1);
		increment_pass(&guess3, i+2);
		increment_pass(&guess4, i+3);

		md5_manipulate(&output, &guess,&guess2,&guess3,&guess4);

	}
	pthread_exit(NULL);
}

void *md5_thread_7(){
		uint64_t start = tbegin_7;
		uint64_t end = tstop_7;
		uint64_t cmp1, i;

		for (i = start; i < end; i+=4) {
		increment_pass(&guess, i);
		increment_pass(&guess2, i+1);
		increment_pass(&guess3, i+2);
		increment_pass(&guess4, i+3);

		md5_manipulate(&output, &guess,&guess2,&guess3,&guess4);

	}
	pthread_exit(NULL);
}

void *md5_thread_8(){
		uint64_t start = tbegin_8;
		uint64_t end = tstop_8;
		uint64_t cmp1, i;

		for (i = start; i < end; i+=4) {
		increment_pass(&guess, i);
		increment_pass(&guess2, i+1);
		increment_pass(&guess3, i+2);
		increment_pass(&guess4, i+3);

		md5_manipulate(&output, &guess,&guess2,&guess3,&guess4);
		
		cmp1 = output._32[0] ^ input._32[0];
		
		if ((cmp1) == 0)
		{
			printf("Found the hash!\n");
			printf("  %s\n", (char *)guess._8);
		}
		cmp1 = output._32[4] ^ input._32[0];
		
		if ((cmp1) == 0)
		{
			printf("Found the hash!\n");
			printf("  %s\n", (char *)guess2._8);
		}
		cmp1 = output._32[8] ^ input._32[0];
		
		if ((cmp1) == 0)
		{
			printf("Found the hash!\n");
			printf("  %s\n", (char *)guess3._8);
		}
		cmp1 = output._32[12] ^ input._32[0];
		
		if ((cmp1) == 0)
		{
			printf("Found the hash!\n");
			printf("  %s\n", (char *)guess4._8);
		}

	}
	pthread_exit(NULL);
}


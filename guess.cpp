#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
//#include "md5.h"
#include "guess.h"
#include <time.h>

using namespace std;

union Guess guess;


int main() {
    
    clock_t start_time, final_time;
    start_time = clock();

    
    for(uint64_t i = Digit6-10; i < Digit6; i++){
    //for(uint64_t i = Digit5; i < Digit5+100000; i++){    
        increment_pass(&guess, i);
        guess_print(&guess);
    }

    final_time = clock();
    //had to multiply by ten since the system had an incorect CLOCKS_PER_SEC value, possibly due to virtual machine
    printf("%f seconds\n",((float)difftime(final_time,start_time))/CLOCKS_PER_SEC*10);
    
    return 0;
}



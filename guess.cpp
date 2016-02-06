#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
//#include "md5.h"
#include "guess.h"
#include <time.h>

using namespace std;

union Block in_block;


int main() {
    
    clock_t start_time, final_time;
    start_time = clock();

    
    //for(uint64_t i = D6; i < D7-1; i++){
    for(uint64_t i = D6; i < D6+100000; i++){    
        write_pass(&in_block, i);
        //guess_print(&in_block);
    }

    final_time = clock();
    //had to multiply by ten since the system had an incorect CLOCKS_PER_SEC value, possibly due to virtual machine
    printf("%f seconds\n",((float)difftime(final_time,start_time))/CLOCKS_PER_SEC*10);



    printf("END\n");
    
    return 0;
}



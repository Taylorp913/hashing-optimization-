#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <stdint.h>
#include "md5.h"

using namespace std;


int main(int argc, char *argv[]) {

    char message[64] = {0};             // Set length of message to 64 bytes
    int msg_length = 0;                 // Message length variable
    int i;                              // Loop variable
    printf("Enter password: ");         // Input password from terminal

    msg_length = strlen(message);       // Set length of message
    message[msg_length + 1] = 0x1;      // Start padding with 1 then 0s in following for loop

    // Start from end of message, skip '1' (first pad number), start adding 0s
    for(i = msg_length + 2; i < 56; i++){
        message[i] = 0x0;
    }

    message[56] = msg_length * 8;       // Last 8 bytes are for the length of the message given in number of bits



    scanf("%[^\n]s", message);
    printf("Your password is: %s\n", message);
    cout << "The size of your password is " << strlen(message) << " bytes.\n";
    copy(message, message + sizeof(message) / sizeof(message[0]), ostream_iterator<char>(cout));

    return 0;
}
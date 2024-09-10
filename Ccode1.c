#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Ensure the command buffer is large enough
    char cmd[BUFSIZE];
    snprintf(cmd, BUFSIZE, "wc -c < %s", argv[1]);

    // Execute the command
    if (system(cmd) == -1) {
        perror("system");
        return -1;
    }

    return 0;
}

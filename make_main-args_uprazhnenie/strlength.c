#include "mystrings.h"
#include <stdio.h>

int main(int argc, char **argv){
    if (argc != 2){
        printf("\n Main argument should be 1!");
        return 0;
    }
    
    printf("strlength: %d \n", strlength(argv[1]));
    return 0;
}
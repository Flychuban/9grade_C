#include "mystrings.h"
#include <stdio.h>

int main(int argc, char **argv){
    if (argc != 3){
        printf("\n Main arguments should be 2!");
        return 0;
    }
    printf("strcompare: %d \n", strcompare(argv[1], argv[2]));
    return 0;
}
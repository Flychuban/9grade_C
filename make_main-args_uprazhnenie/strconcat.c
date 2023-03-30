#include "mystrings.h"
#include <stdio.h>

int main(int argc, char **argv){
    if (argc != 3){
        printf("\n Main arguments should be 2!");
        return 0;
    }

    int len1 = strlength(argv[1]);
    int len2 = strlength(argv[2]);

    int error = 0;
    if (len1 > 50 || len2 > 50)
    {
        printf("\n The length of an argument should be < 50!");
        error = 1;
    }
    
    if (!error)
    {
        strconcat(argv[1], argv[2], len1, len2);
        printf("strconcat: %s \n", argv[1]);
    }
    return 0;
}
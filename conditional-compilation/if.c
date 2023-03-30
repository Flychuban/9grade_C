#include <stdio.h>

#define WINDOWS 1

void printosinfo()
{
    printf("Info about your os:\n");

    #if WINDOWS == 1
        printf("You are under Windows");
    #endif
}

int main()
{
    printosinfo();
    return 0;
}
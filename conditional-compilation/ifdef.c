#include <stdio.h>

#define WINDOWS -1

void printosinfo(){
    printf("Info about your os:\n");
    #ifdef WINDOWS
    printf("You are under windows");
    #endif
}

int main(){
    printosinfo();
    return 0;
}
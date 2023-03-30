#include <stdio.h>

#define WINDOWS 0

// __linux__ if defined we are under linux
// _WIN32 if defined we are under windows
// __APPLE__ if defined you are under macOS
void printosinfo()
{
    printf("Info about your os:\n");

    #if defined __WIN32
        printf("You are under Windows");
    #elif defined __linux__
        printf("You are under Linux");
    #elif defined __APPLE__
        printf("You are under macOs");
    #else
        printf("You are under other OS");
    #endif
}

int main()
{
    printosinfo();
    return 0;
}
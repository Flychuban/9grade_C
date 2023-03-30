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
#else
    printf("You are not under Windows");
#endif
}

int main()
{
    printosinfo();
    return 0;
}
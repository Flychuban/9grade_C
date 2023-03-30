#include <stdio.h>

#define WINDOWS 1
#define OS_BIT_VERSION_64 1
#define BUFFER_SIZE 1024

void printosinfo()
{
    printf("Info about your os:\n");
#if defined WINDOWS
    printf("You are under windows\n");
#endif

#if defined WINDOWS && defined OS_BIT_VERSION_64
printf("You are under 64 bit Windows!\n");
#endif

#if defined BUFFER_SIZE && BUFFER_SIZE > 1024
printf("There is buffer size greather than 1024! \n");
#endif
}

int main()
{
    printosinfo();
    return 0;
}
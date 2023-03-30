#include <stdio.h>
#include <limits.h>

int main(){
    printf("Short max: %hd \n", SHRT_MAX);
    printf("Short min: %hd \n", SHRT_MIN);
    printf("Unsigned short max: %hu \n", USHRT_MAX);

    printf("Unsigned long long max: %llu \n", ULLONG_MAX);
    printf("Long long min: %lld \n", LLONG_MIN);
    printf("Unsigned long max: %lu \n", ULONG_MAX);

    short a = SHRT_MAX;
    a++; // overflow
    printf("A: %hd \n", a);

    return 0;
}
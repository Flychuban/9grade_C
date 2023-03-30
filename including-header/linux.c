#include <stdio.h>
#include <string.h>

#include "osinfo.h"

int main(){
    struct osinfo info = getInfo();
    printf("OS system: %s \n", info.name);
    printf("Biteversion: %d \n", info.bitversion);
    return 0;
}

struct osinfo getInfo(){
    struct osinfo info;
    strcpy(info.name, "Linux");
    info.bitversion = 32;

    return info;
}
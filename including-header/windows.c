#include <stdio.h>
#include <string.h>

#include "osinfo.h"


int main(){
    struct osinfo info = getInfo();
    printf("OS system: %s \n", info.name);
    printf("Bitversion: %d \n", info.bitversion);
    return 0;
}


struct osinfo getInfo(void){
    struct osinfo info;
    strcpy(info.name, "Windows");
    info.bitversion = 64;

    return info;
}
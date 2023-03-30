#include <stdio.h>

#define BIGGER(x, y) x > y ? x : y 

int main(){
    printf("%d ", BIGGER(6, 4));
    return 0;
}
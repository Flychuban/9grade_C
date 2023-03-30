#include <stdio.h>
#include "singleinclude.h"

int main(){
    printf("%d", add(5, 6));
    return 0;
}

int add(int a, int b){
    return a + b;
}
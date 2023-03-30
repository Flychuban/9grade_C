#include <stdio.h>

typedef struct{
    char a;
    char b;
    char c;
    int d[5];
} test;

int main(){
    size_t size = sizeof(test);
    printf("Size of struct: %zu", size); 

    return 0;
}
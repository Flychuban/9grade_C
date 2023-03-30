#include <stdio.h>

long double square(long double x){
    return (x * x);
}


int main(){
    int a = 5;
    float a1 = a;
    printf("%f \n", a1);

    float b = 6.7;
    int b1 = b;
    printf("%d \n", b1);
    
    int c = 123123;
    unsigned char c1 = c;
    printf("%d \n", c1);

    // char -> unsigned char -> short -> unsigned short -> int -> unsigned int -> long -> unsigned 
    // long -> long -> unsigned long -> float -> double -> long double

    char d = -127;
    unsigned char d1 = d;
    printf("%d \n", d1);

    int e = 5;
    int e1 = 2;
    float e2 = e / e1;
    printf("%f \n", e2);

    int e3 = 5;
    float e4 = 2.0;
    float e5 = e3 / e4;
    printf("%f \n", e5);

    long double result = square(5);
    printf("%Lf \n", result);

    result = square(1);
    printf("%Lf \n", result);

    return 0;
}
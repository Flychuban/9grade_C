#include <stdio.h>

int main(){
    char b = 'a'; // max: 126
    printf("%c \n", b);
    unsigned char b1 = 'z'; // max: 255
    
    short f = 19;
    printf("%hd \n", f);

    unsigned short f1 = 19;
    printf("%hu \n", f1);

    int a = 5;
    printf("%d \n", a);

    unsigned int a1 = 5;
    printf("%u \n", a1);

    long d = 123321987456;
    printf("%ld \n", d);

    unsigned long d1 = 123321987456;
    printf("%lu \n", d1);

    long long g = 4454444544779971454;
    printf("%lld \n", g);

    unsigned long long g1 = 4454444544779971454;
    printf("%llu \n", g1);

    float e = 7.42;
    printf("%f \n", e);

    double c = 23.178965445522;
    printf("%lf \n", c);

    long double h = 448779632147.4569321789;
    printf("%Lf \n", h);
    return 0;
}
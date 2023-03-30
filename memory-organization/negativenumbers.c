#include <stdio.h>

int main(void){
    // 0000 0110 (6 in binary) (min: 0, max: 255)
    signed short int a = 40000;
    printf("%hd \n", a);

    // 1's complement - обратен код (negates the number) (min: -126, max: 126)
    // 0000 0110 (6 in binary)
    // 1111 1001 (-6 in 1's complement)

    // 2's complement - допълнителен код (min: -127, max: 126)
    // 0000 0110 (6 in binary)
    // 1111 1001 (-6 in 1's complement)
    // 1111 1010 (-6 in 2's complement)

    // sign magnitute representation (SMR) (min: -126, max: 126)
    // 0000 0110 (6 in binary)
    // 1000 0110 (-6 in binary)

    return 0;


}
#include <stdio.h>
    // mathematical operators: *, /, +, -, %
    // logical operators: &&, ||, !
    // assignment operators: =, +=, -=, /=, *=, ++, --
    // comparision operators: <=, >=, ==, !=, >, <
    // ternery operator: (a > b ? a  : b)
    // bitwise operators:
    // & - bitwise AND
    // | - bitwise OR
    // ~ - bitwise NOT(negation)
    // ^ - bitwise XOR (сума по модул 2)
    // << leftwise bit shift
    // >> rightwise bit shift     

int main(){
    // 0000 0110 - 6
    int a = 6;
    printf("%d\n", a);

    // 0000 0111 - 7
    char b = 7;
    printf("%d\n", b);

    // 0000 0110 - 6
    char c = a & b;
    printf("%d\n", c);

    // 0000 0111 - 7
    char d = a | b;
    printf("%d\n", d);

    // 1111 1001 - 249
    unsigned char e = ~a;
    printf("%d\n", e);

    // 0000 0001 - 1
    char f = a ^ b;
    printf("%d\n", f);

    // 0000 0100 - 4
    char g = f << 2;
    printf("%d\n", g);

    // 0000 0010 - 2
    char h = g >> 1;
    printf("%d\n", h);


    int n = 5;
    // 2 ^ n
    // 0000 0001 << 1 -> 0000 0010 = 2
    // 0000 0001 << 2 -> 0000 0100 = 4
    // 0000 0001 << 3 -> 0000 1000 = 8
    // 0000 0001 << 4 -> 0001 0000 = 16
    // 0000 0001 << 5 -> 0010 0000 = 32
    // 0000 0001 << 6 -> 0100 0000 = 64
    // 0000 0001 << 7 -> 1000 0000 = 128

    int twotothepowerofn = 2 << (n - 1);
    printf("%d\n", twotothepowerofn);
    return 0;
}
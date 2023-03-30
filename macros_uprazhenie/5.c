#include <stdio.h>

// CHECKTYPE is used for checking the formater of printf for ex. char: %c, float: %f 
#define CHECKTYPE(my_type) _Generic((my_type), char:"%c", int:"%d", long:"%ld", float: "%f",default: 0)
// #define SWAP(A, B, TYPE) TYPE c = A; A = B; B = c 

// #define SWAP(A, B, TYPE) \
//     TYPE c = A;          \
//     A = B;               \
//     B = c

// int main()
// {
//     float a = 3.14;
//     float b = 1.72;
//     /*typeof() finds type of variable*/ SWAP(a, b, float);
//     printf("%f - %f", a, b);
//     char type[3] = CHECKTYPE(a);
//     // printf(type, result[0]);
//     // printf(" ");
//     // printf(type, result[1]);
//     return 0;
// }

#define SWAP(A, B) B, A

int main(){
    float a = 3.14;
    float b = 1.72;
    /*typeof() finds type of variable*/typeof(a) result[2] = {SWAP(a, b)};
    char type[3] = CHECKTYPE(a);
    printf(type, result[0]);
    printf(" ");
    printf(type, result[1]);
    return 0;
}
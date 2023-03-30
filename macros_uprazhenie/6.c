#include <stdio.h>

// CHECKTYPE is used for checking the formater of printf for ex. char: %c, float: %f

#define MAXBR 6
#define CHECKTYPE(my_type) _Generic((my_type), char:"%c", int:"%d", long:"%ld", float: "%f",default: 0)

#define SWAP(A, B) B, A

#define SORT(ARRAY, SIZE, TYPE, COMPARE) ({ \
    if (COMPARE == '>') \
    { \
        for (int i = 1; i < SIZE; i++) \
        {  \
            int j = i; \
            while (ARRAY[j] < ARRAY[j - 1] && j>0) \
            { \
                TYPE result[2] = {SWAP(ARRAY[j], ARRAY[j-1])}; \
                ARRAY[j] = result[0]; \
                ARRAY[j-1] = result[1];  \
                j--; \
            } \
        } \
    } \
    else{ \
        for (int i = 1; i < SIZE; i++) \
        {  \
            int j = i; \
            while (ARRAY[j] > ARRAY[j - 1] && j > 0) \
            { \
                TYPE result[2] = {SWAP(ARRAY[j], ARRAY[j - 1])}; \
                ARRAY[j] = result[0]; \
                ARRAY[j - 1] = result[1]; \
                j--; \
            } \
        } \
    } \
    for (int i = 0; i < SIZE; i++) \
    { \
        char type[3] = CHECKTYPE(ARRAY[0]); \  
        printf(type, ARRAY[i]); \
        printf(" "); \
    } \
}); \

int main(){
    char array[MAXBR] = {'q', 'e', 'a', 'z', 'a', 'k'};
    // typedef char my_type;
    // my_type type;

    SORT(array, MAXBR, char, '<');
    return 0;
}
#include <stdio.h>

#define OBJECT_LIKE_MACROS printf("Hello world \n")
#define PRINT() printf("Hello world 2 \n")
#define PRINT_MESSAGE(MESSAGE) printf(MESSAGE)

int main(){
    OBJECT_LIKE_MACROS;
    PRINT();
    PRINT_MESSAGE("Hello world 3\n");
    return 0;
}
#include <stdio.h>

#define SQUARE(X) X*X

#define SQUARE_SAFE(X) ((X)*(X))

int main(){
    printf("\n %d", SQUARE(2+1));
    printf("\n %d", SQUARE_SAFE(2+1));
    
    return 0;
}
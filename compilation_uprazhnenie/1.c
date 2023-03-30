#include <stdio.h>


#define STEPENUVANE(a, b) (a + b)*(a + b) 

int main(){
    int result = STEPENUVANE(3, 5);
    printf("%d ", result);
    return 0;
}
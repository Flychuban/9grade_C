#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 8

int main(){
    #if defined ARRAY_SIZE && ARRAY_SIZE > 0 && ARRAY_SIZE < 10
        double newArray[ARRAY_SIZE];
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            newArray[i] = pow(2, i);
        }
    #else
        printf("Index out of range!");    
    #endif    
    return 0;
}
#include <stdio.h>
#include <math.h>

#define SIZE 100

int main(){
    long my_arr[SIZE] = {0, -1, 2, -3, 4};
    for (int i = 0; i < 5; i++){
        my_arr[i] = pow(my_arr[i], 4);
        printf("%ld ", my_arr[i]);
    }
    
    return 0;
}
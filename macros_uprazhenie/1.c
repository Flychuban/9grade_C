#include <stdio.h>

#define MYARR 4, 8, 5, 6, 7
#define SIZE 5

int main(){
    int main_arr[SIZE] = {MYARR};

    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d ", main_arr[i]);
    }
    
    return 0;
}
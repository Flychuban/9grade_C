#include <stdio.h>

#define ARR_SIZE 5

typedef unsigned long long ull;

ull add(ull a, ull b)
{
    return a + b;
}

typedef ull (*ADD)(ull, ull);

ull reduce(ull arr[], ull arr_range, ADD fptr, ull start_value){
    ull result = start_value;
    for (int i = 0; i < arr_range; i++)
    {
        result = fptr(result, arr[i]);
    }
    return result;
}

int main(){
    ull myarr[ARR_SIZE] = {5, 4, 3, 5, 4};
    ADD fptr = add;
    ull result = reduce(myarr, ARR_SIZE, fptr, 7);
    printf("\n Result: %llu", result);
    return 0;
}
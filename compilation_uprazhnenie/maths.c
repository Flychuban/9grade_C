#include "maths.h"
#include <stdio.h>

long int findFactorial(int n){
    long int result = n;
    for(int i=n-1; i>1; i--){
        result = result * i;
    }
    return result;
}

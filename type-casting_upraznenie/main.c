#include <stdio.h>
#include "quadraticroots.h"
#include <math.h>

int main(){
    QuadraticRootsResult result = findroots(1, -7, 12);
    QuadraticRootsResult result2 = findroots(3.5, 5.5, -6.2);
    QuadraticRootsResult result3 = findroots(3.145698, 5.178964, 1.452136);
    if (result.norealroots == 1){
        printf("Not have real numbers result! \n");
    }
    else{
        printf("x1: %.10Lf  x2: %.10Lf \n", result.x1, result.x2);
    }

    if (result2.norealroots == 1){
        printf("Not have real numbers result! \n");
    }
    else{
        printf("x1: %.10Lf  x2: %.10Lf \n", result2.x1, result2.x2);
    }

    if (result3.norealroots == 1){
        printf("Not have real numbers result! \n");
    }
    else{
        printf("x1: %.10Lf  x2: %.10Lf \n", result3.x1, result3.x2);
    }
    return 0;
}
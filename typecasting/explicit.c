#include <stdio.h>

int main(){
    int a = 5;
    float a1 = (float) a;

    double b = 5.2;
    printf("%d \n", (int) b); 

    int c = 5;
    int c1 = 2;
    float c2 = (float)c / (float)c1;
    printf("%f \n", c2);

    return 0;
}
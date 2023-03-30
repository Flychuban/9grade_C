#include <stdio.h>

int main(){
    int number;
    printf("Number?: ");
    scanf("%d", &number);
    int result = 1;
    while (number)
    {
        result *= number % 10;
        number = number / 10; 
    }
    printf("\n RESULT: %d" ,result);
    return 0;
}
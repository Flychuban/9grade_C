#include <stdio.h>

long long int rekToBinary(int decimal_number);

long long int binary_number = 0;
int c = 1; 

int main(){
    int decimal_number;
    printf("Number?: ");
    scanf("%d", &decimal_number);
    long long int binary_number = rekToBinary(decimal_number);
    printf("\n %lld", binary_number);
    return 0;
}

long long int rekToBinary(int decimal_number){
    if (decimal_number)
    {
        binary_number = binary_number + (decimal_number%2) * c;
        c *= 10;
        decimal_number /= 2; 
        rekToBinary(decimal_number);
    }
    return binary_number;
}
#include <stdio.h>
#include <stdlib.h>

double pow2(double number){
    return number * number;
}

double pow4(double number){
    return pow2(number) * pow2(number);
}

void map(double *arr, int n, double (*funptr)(double)){
    for(int i = 0; i < n; i++){
        arr[i] = funptr(arr[i]);
    }
}

int main(){
    int n;
    do{
        printf("Enter a length of an array: ");
        scanf("%d", &n);
    }while(n < 0);

    double *arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL)
    {
        printf("Error!");
        return 1;
    }
    

    for(int i = 0; i < n; i++){
        printf("Enter a number[%d]: ", i+1);
        scanf("%lf", &arr[i]);
    }
    int choice;
    do
    {
        printf("\n 0. Pow2");
        printf("\n 1. Pow4");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 1);
    if (choice == 1)
    {
        map(arr, n, pow4);
    }
    else if (choice == 0)
    {
        map(arr, n, pow2);
    }
    
    printf("\nNew array: ");
    for(int i = 0; i < n; i++){
        printf("%lf ", arr[i]);
    }
    if (arr != NULL)
    {
        free(arr);
    }
    
    return 0;
}
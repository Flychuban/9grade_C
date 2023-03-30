#include <stdio.h>

union Number_types{
    long odd;
    short even;
};

int main(){
    union Number_types my_union_arr[10];
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            my_union_arr[i].even = i;
        }else{
            my_union_arr[i].odd = i;
        }
    }

    printf("\nOdd numbers: ");
    for(int i = 1; i<10; i=i+2){
        printf("%d ", my_union_arr[i].odd);
    }

    printf("\nEven numbers: ");
    for(int i = 0; i<10; i=i+2){
        printf("%d ", my_union_arr[i].even);
    }

    return 0;
}
#include <stdio.h>

void swap(int * p1, int * p2){
    int c = *p1;
    *p1 = *p2;
    *p2 = c;
}


void sort_arr(int * myarr, int arr_size){
    for (int i = 1; i < arr_size; i++)
    {
        int j = i;
        while (*(myarr + j - 1) > *(myarr + j) && j > 0)
        {
            swap((myarr + j - 1), (myarr + j));
            j--;
        }
    }
}

int main(){
    int myarr[5] = {4, 2, 3, 1, 5};
    sort_arr(myarr, 5);

    for(int i = 0; i < 5; i++){
        printf("%d ", myarr[i]);
    }
    
    return 0;
}
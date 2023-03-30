#include <stdio.h>

int chisloPoIndex(int arr[], int length);

int main(){
    int arr[6] = {1, 7, 3, 4, 9, 2};
    for (int i = 0; i < 6; i++)
    {
        int j = i;
        while (arr[j] < arr[j-1] && j>0)
        {
            int c = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = c;
            j--;
        }
    }
    int sum =  chisloPoIndex(arr, 6);
    printf("SUM: %d", sum);
    return 0;
}


int chisloPoIndex(int arr[], int length){
    int sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += arr[i] * i;
    }
    return sum;
}
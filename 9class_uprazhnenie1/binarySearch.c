#include <stdio.h>

int binarySearch(int arr[], int length, int turseno);

int main(){
    int arr[6] = {4, 8, 7, 1, 3, 5};
    int turseno = 6;
    for (size_t i = 1; i < 6; i++)
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
    printf("%d", binarySearch(arr, 6, turseno));
    return 0;
}

int binarySearch(int arr[], int length, int turseno){
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] == turseno)
        {
            return middle;
        }
        else if(arr[middle] > turseno){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }
    return 0;
}
#include <stdio.h>

#define ROWS 6
#define COLUMNS 4

void printTable(int myarr[ROWS][COLUMNS], int columns){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%5d", *(*(myarr + i) + j));   
        }
        printf("\n");
    }
}

int main(){
    int myarr[ROWS][COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}    
    };
    
    printTable(myarr, COLUMNS);

    return 0;
}
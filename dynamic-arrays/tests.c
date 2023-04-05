#include <stdio.h>
#include "dynarr.h"

void printdynarr(DynamicArray *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%7lf ", getel(arr, i));
    }

    printf("\n");
}

int main(void)
{
    DynamicArray arr = init(3);
    printdynarr(&arr);

    pushback(&arr, 5);
    pushback(&arr, 1);
    pushback(&arr, 7);
    pushback(&arr, 3);
    printdynarr(&arr);

    setel(&arr, 1, 2.54);
    setel(&arr, 7, 9);
    printdynarr(&arr);

    double result = popback(&arr);
    printf("Last element: %7lf\n", result);
    printdynarr(&arr);

    push(&arr, 2, 11);
    pushfront(&arr, 13);
    printdynarr(&arr);

    printf("Pop front: %7lf", popfront(&arr));
    printf("\n");
    printdynarr(&arr);

    pop(&arr, 4);
    printdynarr(&arr);

    int find_index = findelement(&arr, 2.54);
    printf("\nIndex of 2.54: %d", find_index);

    releasedynarr(&arr);
    return 0;
}
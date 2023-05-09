#include <stdio.h>
#include <stdlib.h>
#include "dynamic.h"

void printdynarr(DynamicArray *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%s ", arr->buffer[i].students->name);
        printf("%d ", arr->buffer[i].students->number);
        printf("\n");
    }

    printf("\n");
}

int main(){
    DynamicArray arr = init(3);

    arr.buffer->class_number = 9;
    printf("\n%d\n", arr.buffer->class_number);

    pushback(&arr, "Ivan", 1);
    pushback(&arr, "Pesho", 2);
    printf("\n After pushback: \n");
    printdynarr(&arr);

    return 0;
}
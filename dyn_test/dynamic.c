#include <stdio.h>
#include <stdlib.h>
#include "dynamic.h"
#include <string.h>

static void resize(DynamicArray *arr, int newsize)
{
    if (newsize > arr->capacity)
    {
        arr->capacity *= 2;
        arr->buffer = (StudentsClass *)realloc(arr->buffer, sizeof(StudentsClass) * arr->capacity);
        if (arr->buffer == NULL)
        {
            printf("Error allocating memory \n");
            exit(1);
        }
    }
    else if (newsize <= arr->capacity / 2)
    {
        arr->capacity /= 2;
        arr->buffer = (StudentsClass *)realloc(arr->buffer, sizeof(StudentsClass) * arr->capacity);
        if (arr->buffer == NULL)
        {
            printf("Error allocating memory \n");
            exit(1);
        }
    }
    arr->size = newsize;
}

DynamicArray init(unsigned int capacity){
    DynamicArray arr = {
        capacity : capacity,
        size : 0,
        buffer : NULL
    };
    arr.buffer = (StudentsClass *)calloc(arr.capacity, sizeof(StudentsClass));
    if (arr.buffer == NULL)
    {
        printf("Error allocating memory \n");
        exit(1);
    }
    
    return arr;
}

void pushback(DynamicArray *arr, char student_name[30], int student_number)
{
    int newsize = arr->size + 1;
    resize(arr, newsize);
    arr->buffer[arr->size - 1].students->number = student_number;
    strcpy(arr->buffer[arr->size - 1].students->name, student_name);
}
#include "dynarr.h"
#include <stdio.h>
#include <stdlib.h>

#define ASSERT_MEMORY_ALLOC(PTR)              \
    if ((PTR) == NULL)                        \
    {                                         \
        printf("Error allocating memory \n"); \
        exit(1);                              \
    }

static void resize(DynamicArray *arr, int newsize)
{
    if (newsize > arr->capacity)
    {
        arr->capacity *= 2;
        arr->buffer = (double *)realloc(arr->buffer, sizeof(double) * arr->capacity);
        ASSERT_MEMORY_ALLOC(arr->buffer);
    }
    else if (newsize <= arr->capacity / 2)
    {
        arr->capacity /= 2;
        arr->buffer = (double *)realloc(arr->buffer, sizeof(double) * arr->capacity);
        ASSERT_MEMORY_ALLOC(arr->buffer);
    }
    arr->size = newsize;
}

DynamicArray init(unsigned int capacity)
{
    DynamicArray arr = {
        capacity : capacity,
        size : 0,
        buffer : NULL
    };

    arr.buffer = (double *)calloc(arr.capacity, sizeof(double));
    ASSERT_MEMORY_ALLOC(arr.buffer);

    return arr;
}

double getel(DynamicArray *arr, int index)
{
    return arr->buffer[index];
}

void setel(DynamicArray *arr, int index, double value)
{
    int oldsize = arr->size;
    int newsize = arr->size;
    if (index > newsize - 1)
    {
        newsize = index + 1;
    }
    resize(arr, newsize);
    
    for (int i = oldsize; i < newsize - 1; i++)
    {
        arr->buffer[i] = 0;
    }

    arr->buffer[index] = value;
}

void pushback(DynamicArray *arr, double value)
{
    int newsize = arr->size + 1;
    resize(arr, newsize);
    arr->buffer[arr->size - 1] = value;
}

double popback(DynamicArray *arr)
{
    int newsize = arr->size - 1;
    double result = arr->buffer[newsize];

    resize(arr, newsize);
    arr->buffer[arr->size] = 0;
    return result;
}

void push(DynamicArray *arr, int index, double value)
{
    int newsize = arr->size + 1;
    resize(arr, newsize);
    for (int i = arr->size - 1; i > index; i--)
    {
        arr->buffer[i] = arr->buffer[i - 1];
    }
    arr->buffer[index] = value;
}

void pushfront(DynamicArray *arr, double value)
{
    push(arr, 0, value);
}

double popfront(DynamicArray *arr){
    int newsize = arr->size - 1;
    double result = arr->buffer[0];
    for (int i = 0; i < arr->size - 1; i++)
    {
        arr->buffer[i] = arr->buffer[i + 1];
    }
    resize(arr, newsize);
    return result;
}

void pop(DynamicArray *arr, int index)
{
    int newsize = arr->size - 1;
    resize(arr, newsize);
    for (int i = index; i < arr->size; i++)
    {
        arr->buffer[i] = arr->buffer[i + 1];
    }
    
}

void releasedynarr(DynamicArray *arr)
{
    if (arr->buffer != NULL)
    {
        free(arr->buffer);
        arr->buffer = NULL;
    }
    arr->capacity = 0;
    arr->size = 0;
}

int findelement(DynamicArray *arr, double value)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->buffer[i] == value)
        {
            return i;
        }
    }
    return -1;
}
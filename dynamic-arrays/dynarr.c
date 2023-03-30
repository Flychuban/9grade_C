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
        arr->buffer = (int *)realloc(arr->buffer, sizeof(int) * arr->capacity);
        ASSERT_MEMORY_ALLOC(arr->buffer);
    }
    else if (newsize <= arr->capacity / 2)
    {
        arr->capacity /= 2;
        arr->buffer = (int *)realloc(arr->buffer, sizeof(int) * arr->capacity);
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

    arr.buffer = (int *)calloc(arr.capacity, sizeof(int));
    ASSERT_MEMORY_ALLOC(arr.buffer);

    return arr;
}

int getel(DynamicArray *arr, int index)
{
    return arr->buffer[index];
}

void setel(DynamicArray *arr, int index, int value)
{
    int newsize = arr->size;
    if (index > newsize - 1)
    {
        newsize = index + 1;
    }
    resize(arr, newsize);

    arr->buffer[index] = value;
}

void pushback(DynamicArray *arr, int value)
{
    int newsize = arr->size + 1;
    resize(arr, newsize);
    arr->buffer[arr->size - 1] = value;
}

int popback(DynamicArray *arr)
{
    int newsize = arr->size - 1;
    int result = arr->buffer[newsize];

    resize(arr, newsize);
    arr->buffer[arr->size] = 0;
    return result;
}

void push(DynamicArray *arr, int index, int value)
{
    int newsize = arr->size + 1;
    resize(arr, newsize);
    for (int i = arr->size - 1; i > index; i--)
    {
        arr->buffer[i] = arr->buffer[i - 1];
    }
    arr->buffer[index] = value;
}

void pushfront(DynamicArray *arr, int value)
{
    push(arr, 0, value);
}

int popfront(DynamicArray *arr){
    int newsize = arr->size - 1;
    int result = arr->buffer[0];
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
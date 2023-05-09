#ifndef DYNARR_H
#define DYNARR_H

typedef struct{
    char name[30];
    int number;
} Student;

typedef struct{
    Student *students;
    int class_number;
} StudentsClass;

typedef struct
{
    StudentsClass *buffer;
    unsigned int capacity;
    unsigned int size;
} DynamicArray;

DynamicArray init(unsigned int capacity);

void pushback(DynamicArray *arr, char student_name[30], int student_number);

#endif
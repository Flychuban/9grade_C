#ifndef TRANSFORMATION
#define TRANSFORMATION

typedef struct{
    long result;
    char error[100];
} transformation;

transformation strToInt(char *my_str);

#endif
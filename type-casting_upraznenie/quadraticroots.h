#ifndef GUARD
#define GUARD

typedef struct{
    long double x1;
    long double x2;
    char norealroots;
} QuadraticRootsResult;

QuadraticRootsResult findroots(double a, double b, double c);

#endif
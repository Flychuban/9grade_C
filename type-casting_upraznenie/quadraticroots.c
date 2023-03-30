#include <stdio.h>
#include <math.h>
#include "quadraticroots.h"


QuadraticRootsResult findroots(double a, double b, double c){
    QuadraticRootsResult p;
    p.norealroots = 0;

    double discriminata = (b * b) + ((-4) * a * c);
    long double findx1 = (((-b) - sqrtl(discriminata)) / 2 * a);
    long double findx2 = (((-b) + sqrtl(discriminata)) / 2 * a);

    printf("D= %lf \n", discriminata);
    printf("SQRTL= %lf \n", sqrtl(16.0));

    if (discriminata < 0)
    {
        p.norealroots = 1;
    }

    else if (discriminata == 0)
    {
        p.x1 = findx1;
        p.x2 = p.x1;
    }
    else{
        p.x1 = findx1;
        p.x2 = findx2;
    }

    return p;
}
#include <stdio.h>

#include "chemistry.h"
#include "physics.h"

int main(void)
{
    struct real number;
    printf("Calpath: %d", calpath(number.numerator = 99, number.denominator = 3));
    printf("Calcmass: %d", calcmass(number.numerator = 66, number.denominator = 6));
    return 0;
}

struct real calpath(struct real velocity, struct real time){
    return velocity / time;
}

struct real calcmass(struct real volume, struct real density){
    return volume * density;
}
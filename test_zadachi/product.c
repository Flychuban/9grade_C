#include "product.h"

long product = 1;

static long nexteven(){
    static int a = 0;
    a = a + 2; 
    return a;
} 

long multiplayproductwitheven(){
    long new_num = nexteven();
    product = product * new_num;
    return product;
}
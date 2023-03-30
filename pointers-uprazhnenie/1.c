#include <stdio.h>

int main(){
    int a, b;
    printf("a: ");
    scanf("%d", &a);

    printf("\nb: ");
    scanf("%d", &b);

    int *p1 = &a;
    int *p2 = &b;

    printf("\n&p1= %p\n", p1);
    printf("p1= %d\n", *p1);
    printf("&p2= %p\n", p2);
    printf("p2= %d\n", *p2);
    return 0;
}
#include <stdio.h>
#include <limits.h>

int main(){
    printf("%-10s -- %-4s -- %-zu -- %-20d -- %-20d -- %-20u -- %d\n", "char", "%c", sizeof(char), CHAR_MAX, CHAR_MIN, UCHAR_MAX, 0);

    printf("%-10s -- %-4s -- %-zu -- %-20d -- %-20d -- %-20hu -- %d\n", "short", "%hd", sizeof(short), SHRT_MAX, SHRT_MIN, USHRT_MAX, 0);

    printf("%-10s -- %-4s -- %-zu -- %-20d -- %-20d -- %-20u -- %d\n", "int", "%d", sizeof(int), INT_MAX, INT_MIN, UINT_MAX, 0);

    printf("%-10s -- %-4s -- %-zu -- %-20d -- %-20d -- %-20lu -- %d\n", "long", "%ld", sizeof(long), LONG_MAX, LONG_MIN, ULONG_MAX, 0);

    printf("%-10s -- %-4s -- %-zu -- %-20lld -- %-20d -- %-20llu -- %d\n", "long long", "%lld", sizeof(long long), LLONG_MAX, LLONG_MIN, ULLONG_MAX, 0);
    return 0;
}
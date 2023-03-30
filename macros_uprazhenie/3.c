#include <stdio.h>

#define VARINFO(name, value, file, line) printf("%s --- %s --- %s --- %d", #name, value, file, line)

int main(){
    char a[15] = "asdfghjkl";

    VARINFO(a, a , __FILE__ , __LINE__);
    return 0;
}
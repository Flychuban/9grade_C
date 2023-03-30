#include <stdio.h>

struct Node
{
    struct Node *next;
    int value;
};

int main(void)
{
    struct Node node1 = {next : NULL, value : 5};
    struct Node node2 = {next : NULL, value : 7};

    node1.next = &node2;
    printf("\n%d", node1.next->value);
    

    return 0;
}
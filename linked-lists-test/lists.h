#ifndef LISTS_H
#define LISTS_H

struct ListNode{
    double value;
    struct ListNode *next;
};

typedef struct{
    struct ListNode *head;
    int size;
} LinkedList;

LinkedList init();

struct ListNode *get(LinkedList *list, int index);
void pushfront(LinkedList *list, double value);
double popfront(LinkedList *list);
void set(LinkedList *list, int index, double value);

#endif
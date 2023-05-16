#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

struct BookInfo{
    char title[100];
    char author[30];
    char esbn_number[10];
    int year_published;
    char genre[30];
    struct BookInfo *next;
};


typedef struct
{
    struct BookInfo *head;
    int size;
} LinkedList;

LinkedList init();

void pushfront(LinkedList *list, struct BookInfo book);
struct BookInfo *get(LinkedList *list, int index);
void push(LinkedList *list, struct BookInfo book, int index);
void pop(LinkedList *list, char esbn_number[10]);
void release(LinkedList *list);
#endif
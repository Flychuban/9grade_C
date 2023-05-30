#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

enum Education{
    NOEDUCATION,
    PRIMARY,
    SECONDARY,
    MASTER
};

enum Family{
    SINGLE,
    MARRIED
};

enum Work{
    UNEMPLOYED,
    WORKING
};


struct PersonInfo{
    int ID;
    int age;
    char name[255];
    enum Education education;
    enum Family family;
    enum Work work;
    struct PersonInfo *next;
};


typedef struct
{
    struct PersonInfo *head;
    int size;
} LinkedList;

LinkedList init();

void pushfront(LinkedList *list, struct PersonInfo person);
struct PersonInfo *get(LinkedList *list, int index);
void push(LinkedList *list, struct PersonInfo person, int index);
void pop(LinkedList *list, int ID);
void release(LinkedList *list);
#endif
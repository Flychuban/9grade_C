#ifndef GUARD
#define GUARD

typedef struct{
    unsigned long long int ID;
    char nameProcess[30];
} Process;


static Process processes[5];

static unsigned long long nextprocessesid();
extern unsigned long long createnewprocesses(char * name);
extern void printprocesses();
extern void stopprocess(unsigned long long asked_id);
extern int quitprogram();

#endif
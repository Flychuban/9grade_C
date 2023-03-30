#include "processes.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>

int processescount = 0;

static Process processes[5];

static unsigned long long nextprocessesid();
unsigned long long createnewprocesses(char *name);
void printprocesses();
void stopprocess(unsigned long long asked_id);
int quitprogram();

static unsigned long long nextprocessesid(){
    static unsigned long long id = 0;
    if (id >= ULLONG_MAX){
        return 0;
    }
    id++;
    return id;
}

unsigned long long createnewprocesses(char *name){
    if(processescount <= 4){
        processes[processescount].ID = nextprocessesid();
        if (processes[processescount].ID == 0){
            return 0;
        }
        strcpy(processes[processescount].nameProcess, name);
        processescount++;
        return processes[processescount].ID;
    }
    return 0;
}

void stopprocess(unsigned long long asked_id){
    for (int i = 0; i <= processescount; i++){
        if (asked_id == processes[i].ID){
            strcpy(processes[i].nameProcess, "/0");
            processes[i].ID = 0;
            for (int j = i + 1; j <= 4; j++)
            {
                char c[30];
                strcpy(c, processes[j - 1].nameProcess);
                strcpy(processes[j - 1].nameProcess, processes[j].nameProcess);
                strcpy(processes[j].nameProcess, c);
                unsigned long long d = processes[j - 1].ID;
                processes[j - 1].ID = processes[j].ID;
                processes[j].ID = d;
            }
            processescount--;
            break;
        }  
    }
}

void printprocesses(){
    for (int i = 0; i < processescount; i++)
    {
        printf("%s --- %llu \n", processes[i].nameProcess, processes[i].ID);
    }
}

int quitprogram(){
    return 0;
}

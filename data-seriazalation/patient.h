#ifndef PATIENT_H
#define PATIENT_H

#define PATIENT_NAME_MAX_LENGTH 255
#define SYMPTOMS_MAX_LENGTH 2056

typedef struct
{
    char name[PATIENT_NAME_MAX_LENGTH];
    unsigned long EGN;
    unsigned char age;
    char symptoms[SYMPTOMS_MAX_LENGTH];
} Patient;

void printPatient(Patient *patient);

#endif
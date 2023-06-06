#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    char name[100];
    int number_employees;
    struct Employee **employees;
}

int main(){
    struct Employee director = {"Ivan", 2, NULL};
    struct Employee manager_1 = {"Pesho", 3, NULL};
    struct Employee manager_2 = {"Gosho", 3, NULL};
    struct Employee employee_1 = {"Marin", 0, NULL};
    struct Employee employee_2 = {"Kaloyan", 0, NULL};
    struct Employee employee_3 = {"Hristo", 0, NULL};
    struct Employee employee_4 = {"Pavel", 0, NULL};
    struct Employee employee_5 = {"Dimo", 0, NULL};
    struct Employee employee_6 = {"Stefan", 0, NULL};

    director.employees = (struct Employee **)malloc(sizeof(struct Employee *) * director.number_employees);
    director.employees[0] = &manager_1;
    director.employees[1] = &manager_2;

    manager_1.employees = (struct Employee **)malloc(sizeof(struct Employee *) * manager_1.number_employees);
    manager_1.employees[0] = &employee_1;
    manager_1.employees[1] = &employee_2;
    manager_1.employees[2] = &employee_3;

    manager_2.employees = (struct Employee **)malloc(sizeof(struct Employee *) * manager_2.number_employees);
    manager_2.employees[0] = &employee_4;
    manager_2.employees[1] = &employee_5;
    manager_2.employees[2] = &employee_6;

    FILE *fp = fopen("employees.bin", "wb");
    if (fp == NULL)
    {
        printf("Error opening file \n");
        exit(1);
    }
    
    for (int i = 0; i < director.number_employees; i++)
    {
        char *cur_man_name = director.employees[i]->name;
        char *cur_man_number_employees = director.employees[i]->number_employees;
        fwrite(&cur_man_name, sizeof(char), 100, fp);
        fwrite(&cur_man_number_employees, sizeof(int), 1, fp);
        for (int j = 0; j < cur_man_number_employees; j++)
        {
            char *cur_emp_name = director.employees[i]->employees[j]->name;
            char *cur_emp_number_employees = director.employees[i]->employees[j]->number_employees;
            fwrite(&cur_emp_name, sizeof(char), 100, fp);
            fwrite(&cur_emp_number_employees, sizeof(int), 1, fp);
        }   
    }
    
    fclose(fp);

    return 0;
}

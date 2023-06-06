#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("employees.bin", "rb");
    if (fp == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    char cur_dir_name[100];
    int cur_dir_number_employees;

    fread(&cur_dir_name, sizeof(char), 100, fp);
    fread(&cur_dir_number_employees, sizeof(int), 1, fp);
    printf("%s\n", cur_dir_name);

    for (int i = 0; i < cur_dir_number_employees; i++)
    {
        char cur_man_name[100];
        int cur_man_number_employees;

        fread(&cur_man_name, sizeof(char), 100, fp);
        fread(&cur_man_number_employees, sizeof(int), 1, fp);
        printf("   %s\n", cur_man_name);
        for (int j = 0; j < cur_man_number_employees; j++)
        {
            char cur_emp_name[100];
            int cur_emp_number_employees;

            fread(&cur_emp_name, sizeof(char), 100, fp);
            fread(&cur_emp_number_employees, sizeof(int), 1, fp);
            printf("      %s\n", cur_emp_name);
        }
    }
    fclose(fp);

    return 0;
}
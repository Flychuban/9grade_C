#include <stdio.h>

#define SIZE 6
#define ARRAY_SIZE 9

void sortOS(int *my_arr);
void printOnNewLine(int *my_arr);

int main(){
    int my_arr[SIZE] = {4, 7, 1, 2, 9, 1};
    sortOS(my_arr);
    return 0;
}

void sortOS(int *my_arr){
    #if defined ARRAY_SIZE && ARRAY_SIZE > 0 && ARRAY_SIZE < 10
        #if defined __WIN32
            for (int i = 0; i < SIZE - 1; i++)
            {
                int sorted = 0;
                for (int j = 0; j < SIZE - 1; j++)
                {
                    if (my_arr[j] > my_arr[j + 1])
                    {
                        int c = my_arr[j];
                        my_arr[j] = my_arr[j + 1];
                        my_arr[j + 1] = c;
                        sorted = 1;
                    }
                }
                if (!sorted)
                {
                    break;
                }
            }
            printOnNewLine(my_arr);

        #elif defined __linux__
            for (i = 0; i < SIZE - 1; i++)
            {
                min = my_arr[i];
                mini = i;
                for (j = i + 1; j < SIZE; j++)
                {
                    if (my_arr[j] < min)
                    {
                        min = my_arr[j];
                        mini = j;
                    }
                }
                my_arr[mini] = my_arr[i];
                my_arr[i] = min;
            }
            printOnNewLine(my_arr);

        #elif defined __APPLE__
            for (int i = 1; i < SIZE; i++)
            {
                int j = i;
                while (my_arr[j] < my_arr[j-1] && j>0)
                {
                    int c = my_arr[j];
                    my_arr[j] = my_arr[j + 1];
                    my_arr[j + 1] = c;
                    j--;
                }
            }
            printOnNewLine(my_arr);

        #else
            int half = SIZE / 2;
            int j = SIZE - 1;
            for (int i = 0; i < half; i++)
            {
                int c = my_arr[i];
                my_arr[i] = my_arr[j];
                my_arr[j] = c;
                j--;
            }
            printOnNewLine(my_arr);

        #endif

    #else
        printf("Size is invalid!");
    #endif 
}

void printOnNewLine(int *my_arr){
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n ", my_arr[i]);
    }
}
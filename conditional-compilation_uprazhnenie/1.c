#include <stdio.h>

#define SIZE 100

#define DEBUG


int main(){
    int my_arr[SIZE] = {4, 7, 9, 1, 6, 1};
    int length = 6;
    int sum = Sort(my_arr, length);
    printf("\nSUM: %d", sum);
    return 0;
}

int Sort(int *my_arr, int length){                          
    int sum = 0;                                   
    {                                                  
        for (int i = 0; i < length; i++)               
        {                                              
            int j = i;                                 
            while (my_arr[j] < my_arr[j - 1] && j > 0) 
            {                                          
                int c = my_arr[j];                     
                my_arr[j] = my_arr[j - 1];             
                my_arr[j - 1] = c;                     
                j--;                                   
            }                                          
        }
        for (int i = 3; i < length; i++)           
        {                                                        
            if (i % 3 == 0)                        
            {                                      
                sum += my_arr[i];                  
            }                                      
        }
        #ifdef DEBUG
            for (int i = 0; i < length; i++)
            {
                printf("%d ", my_arr[i]);
            }
            printf("\n Index kraten na 3: ");
            for (int i = 3; i < length; i++)
            {
                if (i%3 == 0)
                {
                    printf("%d ", my_arr[i]);
                }
            }
        #endif
    }                                              
    return sum;                                           
}                                                  
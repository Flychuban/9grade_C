#include <stdio.h>

int main(){
    int arr[8] = {1, 7, 10, 15, 16, 13, 23, 30};
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        int flag = 0;
        if (arr[i] == 1 || arr[i] == 0)
        {
            continue;
        }
        
        for (int delitel = 2; delitel < arr[i]; delitel++)
        {
            if (arr[i] % delitel == 0 )
            {
                flag = 1;
                break;
            }
        }    
        if(flag == 0){
            sum += arr[i];
        }   
    }
    printf("SUM: %d", sum);
     
    return 0;
}
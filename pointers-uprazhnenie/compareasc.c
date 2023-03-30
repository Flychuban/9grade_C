#include <stdio.h>

int compareasc(void *ptr1, void *ptr2){
    int p1 = *(int *)ptr1;
    int p2 = *(int *)ptr2;

    if (p1 > p2)
    {
        return 1;
    }
    else if (p1 == p2)
    {
        return 0;
    }
    else{
        return -1;
    }
}

int comparedsc(void *ptr1, void *ptr2)
{
    int p1 = *(int *)ptr1;
    int p2 = *(int *)ptr2;

    if (p1 < p2)
    {
        return 1;
    }
    else if (p1 == p2)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void bubblesort(int myarr[], int size, int (*fptr)(void *, void *))
{
    for (int i = 0; i < size - 1; i++)
    {
        int sorted = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            int result = (*fptr)((void *)(myarr + j), (void *)(myarr + j +1));
            if (result == 1)
            {
                int c =  myarr[j];
                myarr[j] = myarr[j+1];
                myarr[j+1] = c;
                sorted = 1;
            }
        }
        if (!sorted)
        {
            break;
        }      
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", myarr[i]);
    }
}

int main(){
    float a = 2.17;
    float b = 3.17;

    void *ptr1 = &a;
    void *ptr2 = &b;

    int (*fptrAsc)(void *, void *) = compareasc;
    int (*fptrDsc)(void *, void *) = comparedsc;

    int myarr[6] = {7, 4, 12, 2, 1, 6};
    bubblesort(myarr, 6, compareasc);

    return 0;
}
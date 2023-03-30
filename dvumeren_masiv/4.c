#include <stdio.h>
#include <string.h>

int main()
{
    char board[8][8] =
        {
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', 'p', '.', '.', '.', '.'},
            {'.', '.', '.', 'p', '.', '.', '.', '.'},
            {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', 'B', '.', '.', '.', '.'},
            {'.', '.', '.', 'p', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.'}};
    int mqsto, broqch = 0, i, j, height, width;
    int rookFound = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board[i][j] == 'R')
            {
                height = i;
                width = j;
                rookFound=1;
                break;
            }
        }
        if (roodFound)
        {
            break;
        }
        
    }

    for (i = width - 1; i >= 0; i--)
    {
        if (board[height][i] == 'p')
        {
            broqch++;
            break;
        }
        else if (board[height][i] == 'B')
        {
            break;
        }
    }
    for (i = width + 1; i < 8; i++)
    {
        if (board[height][i] == 'p')
        {
            broqch++;
            break;
        }
        else if (board[height][i] == 'B')
        {
            break;
        }
    }
    for (i = height - 1; i >= 0; i--)
    {
        if (board[i][width] == 'p')
        {
            broqch++;
            break;
        }
        else if (board[i][width] == 'B')
        {
            break;
        }
    }
    for (i = height + 1; i < 8; i++)
    {
        if (board[i][width] == 'p')
        {
            broqch++;
            break;
        }
        else if (board[i][width] == 'B')
        {
            break;
        }
    }
    printf("\n Topa mozhe da vzeme %d peshki.", broqch);
    return 0;
}
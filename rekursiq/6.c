#include <stdio.h>

#define maxSize 100

int isPath(int board[maxSize][maxSize], int i, int j, int rows, int columns);

int rows = 5;
int columns = 6;
int main()
{
    // 2- PUT
    // 1- Stena
    int board[maxSize][maxSize] = {
        {2, 1, 1, 2, 1, 2},
        {2, 2, 1, 1, 2, 1},
        {2, 2, 2, 1, 1, 2},
        {1, 1, 2, 2, 1, 2},
        {2, 1, 1, 2, 2, 2}};

    /*int rows;
    int columns;
    for ( rows = 0; rows < maxSize; rows++)
    {
        for ( columns = 0; columns < maxSize; columns++)
        {
            if (board[rows][columns]!=2 && board[rows][columns]!=1)
            {

                continue;
            }

        }

    }
    */
    int i = 0;
    int j = 0;
    int rows = 5;
    int columns = 6;
    if (isPath(board, i, j, rows, columns))
    {
        printf("\n Ima put do kraq!");
    }
    else
    {
        printf("\n NQMA put do kraq!");
    }
    return 0;
}

int isPath(int board[maxSize][maxSize], int i, int j, int rows, int columns)
{
    if (board[i][j] == 1)
    {
        return 0;
    }
    if (i == rows - 1 && j == columns - 1)
    {
        return 1;
    }
    if (i < 0 || j < 0 || i >= rows || j >= columns)
    {
        return 0;
    }
    board[i][j] = 1;
    int up = isPath(board, i - 1, j, rows, columns);
    int down = isPath(board, i + 1, j, rows, columns);
    int left = isPath(board, i, j - 1, rows, columns);
    int right = isPath(board, i, j + 1, rows, columns);
    return up || down || left || right;
}
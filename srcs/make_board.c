#include "tetris.h"

char *make_board(int size)
{
    char *board;
    int i;
    int j;
    int k;

    board = (char *)malloc(sizeof(char) * size * (size + 1) + 1);
    i = 0;
    k = 0;
    while (k < size)
    {
        j = 0;
        while (j < size)
        {
            board[i] = '.';
            i++;
            j++;
        }
        board[i] = '\n';
        i++;
        k++;
    }
    board[i] = '\0';
    return (board);
}
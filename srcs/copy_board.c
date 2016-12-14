#include "tetris.h"

char *copy_board(char *board)
{
    int i;
    char *copy;
    i = 0;
    while (board[i])
        i++;
    copy = (char *)malloc(sizeof(char) * i + 1);
    i = 0;
    while (board[i])
    {
        copy[i] = board[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
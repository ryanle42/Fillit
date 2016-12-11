#include "tetris.h"

int get_board_size(char *board)
{
    int i;
    
    i = 0;
    while (board[i] != '\n')
        i++;
    return (i);
}

int     is_safe(char *board, char **piece, int pos, int size)
{
    int block;
    int i;
    int j;
    int k;
    block = 4;

    i = 0;
    j = 0;
    k = 0;
    while (piece[i][j] != '#')
    {
        j++;
        if (j == 4)
        { 
            j = 0;
            i++;
        }
    }
    //printf("pos: %i\n", pos);
    if (board[pos] != '.')
        return (0);
    block--;
    while (block > 0 && (pos < ((size + 1) * size)))
    {
        if (j == 3)
            k--;
        j++;
        while (piece[i][j] != '#')
        {
            j++;
            k++;
            if (j >= 4)
            { 
                j = 0;
                i++;
                k++;
                pos += (size - 4);
           }
        }
        pos += (k + 1);
        if (board[pos] != '.')
            return (0);
        k = 0;
        block--;
    } 
    return (1);
}
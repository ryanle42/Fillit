#include "tetris.h"

char    *place_piece(char *board, char **piece, int pos, int order)
{
    int block;
    int i;
    int j;
    int k;
    int size;

    block = 4;
    i = 0;
    j = 0;
    k = 0;
    size = get_board_size(board);
    while (piece[i][j] != '#')
    {
        j++;
        if (j == 4)
        { 
            j = 0;
            i++;
        }
    }
    board[pos] = order + 64;
    block--;
    while (block > 0 && (pos < ((size * size) + size)))
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
        //printf("k: %i\n", k);
        pos += (k + 1);
        //printf("pos: %i\n", pos);
        board[pos] = order + 64;
        k = 0;
        block--;
    } 
    return (board);
}
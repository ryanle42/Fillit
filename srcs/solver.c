#include "tetris.h"

char *ft_board_solver(char ***pieces, int start, int max, int pos, int size)
{
    int j;
    char *board;

    board = make_board(size);
    j = 0;
    while ((pos < ((size + 1)*size)) && j == 0)
    {
        if (is_safe(board, pieces[start], pos, size))
        {
            board = place_piece(board, pieces[start], pos, start + 1);
            pos = 0;
            j++;
        }
        else
            pos++;
    }
    j = 0;
    //((size + 1) * size)
    while ((pos < ((size + 1)*size)) && j < max)
    {
        if (j == start)
            j++;
        if (is_safe(board, pieces[j], pos, size))
        {
            board = place_piece(board, pieces[j], pos, j + 1);
            pos = 0;
            j++;
        }
        else
            pos++;
    }
    if (j == max)
        return (board);
    return (NULL);
}
/*
char *board_solver(char ***pieces, int max)
{

    int size;
    int start;
    char *board;
    int pos;
    size = 0;
    while (1)
    {
        size++;
        start = 0;
        while (start < max)
        {
            pos = 0;
            while (pos < ((size + 1) * size))
            {
                if ((board = ft_board_solver(pieces, start, max, pos, size)))
                    return (board);
                pos++;
            }
            start++;
        }
    }
    return (NULL);
}*/
char *board_solver(char ***pieces, int max)
{

    int size;
    int start;
    char *board;
    int pos;
    size = 0;
    while (1)
    {
        size++;
        pos = 0;
        while (pos < ((size + 1) * size))
        {
            start = 0;
            while (start < max)
            {
                if ((board = ft_board_solver(pieces, start, max, pos, size)))
                    return (board);
                start++;
            }
            pos++;
        }
    }
    return (NULL);
}


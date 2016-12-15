#include "tetris.h"

char    *fill_board(char *board, char ***pieces, int num_pieces, int size)
{
	int		current_piece;
    char **save_board;
    int *save_pos;
    int pos;

    save_pos = (int *)malloc(sizeof(int) * num_pieces);
    save_board = (char **)malloc(sizeof(char *) * num_pieces);
	current_piece = 0;
    pos = 0;
	while ((pos < (size + 1) *size - 1) || current_piece != 0)
	{
		if ((board[pos] == '.') && (is_safe(board, pieces[current_piece], pos, size))) // is safe
		{
            save_board[current_piece] = copy_board(board); // save board pre-place
            save_pos[current_piece] = pos;                 // safe pos pre-place
			board = place_piece(board, pieces[current_piece], pos, current_piece + 1);
			if (++current_piece == num_pieces) // board solved!!
				return (board);
            pos = -1;
		}
        pos++;
        if ((pos >= (size + 1) *size - 1) && current_piece == 0) // All possibilities fail
        {
            free(board);
            free(save_board);
            free(save_pos);
            return (NULL);
        }
        if ((pos >= (size + 1) * size - 1)) // backtrack piece
        {
            current_piece--;
            pos = (save_pos[current_piece] + 1);
            free(board);
            board = (save_board[current_piece]);
        }
    }
    return (NULL);
}

char *board_solver(char ***pieces, int max)
{

    int size;
    int start;
    char *board;
    char *tmp;
    int pos;

    size = max / 3;
    while (1)
    {
        size++;
        board = make_board(size);
        if ((tmp = fill_board(board, pieces, max, size)))
            return (tmp);
    }
    return (board);
    return (NULL);
}


#include "tetris.h"

char    *fill_board(char *board, char ***pieces, int num_pieces, int size)
{
	int		current_piece;
    char **save_board;
    int *save_pos;
    int pos;

    save_pos = (int *)malloc(sizeof(int) * num_pieces);
    save_board = (char **)malloc(sizeof(char *) * num_pieces);
    memset(save_pos, 0, num_pieces);
    memset(save_board, 0, num_pieces);
	current_piece = 0;
    pos = 0;
	while (1)
	{
		if ((board[pos] == '.') && is_safe(board, pieces[current_piece], pos, size))
		{
            save_board[current_piece] = copy_board(board);
            save_pos[current_piece] = pos;
			board = place_piece(board, pieces[current_piece], pos, current_piece + 1);
            //printf("%s\n", board);
			if (++current_piece == num_pieces) // board solved!!
				return (board);
            pos = -1;
		}
        pos++;
        if (pos >= (size + 1) *size && current_piece == 0)
        {
            free(board);
            free(save_board);
            free(save_pos);
            return (NULL);
        }
        if (pos >= (size + 1) * size)
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

    size = 0;
    while (1)
    {
        size++;
        board = make_board(size);
        if ((tmp = fill_board(board, pieces, max, size)))
            return (tmp);
    }
    return (NULL);
}


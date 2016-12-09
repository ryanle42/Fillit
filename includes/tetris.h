#ifndef TETRIS_H
# define TETRIS_H

#include <stdio.h>
#include <stdlib.h>

int	valid_file(char *file);
int	valid_box(char **box);
char *place_piece(char *board, char **piece, int pos, int size, int order);
int	get_board_size(char *board);
int	is_safe(char *board, char **piece, int pos, int size);
int	valid_all_box(char ***box, int box_count);
int	count_box(char *file);
char ***file_to_block(char ***box, char *file);
char	***make_box(char *file);

#endif

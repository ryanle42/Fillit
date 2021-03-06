#ifndef TETRIS_H
# define TETRIS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int	valid_file(char *file);
int valid_box(char **box, int flag, int dub_touch, int touch);
char *place_piece(char *board, char **piece, int pos, int order);
int	get_board_size(char *board);
int	is_safe(char *board, char **piece, int pos, int size);
int	valid_all_box(char ***box, int box_count);
int	count_box(char *file);
char ***make_3d_box(char *file);
char **rand_piece();
char *d2_to_d1(char **box);
char **make_two_Dim(char *onedim, int i);
int		file_len(char *path);
char	*filetostr(char *path);
//test
char *make_board(int size);
char *board_solver(char ***pieces, int max);
char    *fill_board(char *board, char ***pieces, int num_pieces, int size);
char *copy_board(char *board);
#endif

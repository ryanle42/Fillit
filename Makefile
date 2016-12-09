NAME = tetris 

CC = gcc -Wall -Werror -Wextra -I ./includes

CFILES = ./srcs/place_piece.c ./srcs/is_safe.c ./srcs/valid_box.c ./srcs/valid_file.c ./srcs/main.c ./srcs/make_3d_boxes.c

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(CFILES)

clean:
	rm -rf $(NAME)

re: clean
	make all
 

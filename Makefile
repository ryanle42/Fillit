NAME = tetris 

CC = gcc -I includes

OFILES = ./place_piece.o ./is_safe.o ./valid_box.o ./valid_file.o ./main.o ./make_3d_boxes.o \
			./2d_to_1d.o ./make_2d_box.o ./file_reader.o ./solver.o ./make_board.o \
			./copy_board.o

all: $(NAME)

$(NAME): $(OFILES)
	rm -rf bin
	mkdir bin
	$(CC) -o $(NAME) $(OFILES)
	mv *.o bin

./place_piece.o: ./srcs/place_piece.c
	$(CC) -c ./srcs/place_piece.c

./is_safe.o: ./srcs/is_safe.c
	$(CC) -c ./srcs/is_safe.c

./valid_box.o: ./srcs/valid_box.c
	$(CC) -c ./srcs/valid_box.c

./valid_file.o: ./srcs/valid_file.c
	$(CC) -c ./srcs/valid_file.c

./main.o: ./srcs/main.c
	$(CC) -c ./srcs/main.c

./make_3d_boxes.o: ./srcs/make_3d_boxes.c
	$(CC) -c ./srcs/make_3d_boxes.c

./2d_to_1d.o: ./srcs/2d_to_1d.c
	$(CC) -c ./srcs/2d_to_1d.c

./make_2d_box.o: ./srcs/make_2d_box.c
	$(CC) -c ./srcs/make_2d_box.c

./file_reader.o: ./srcs/file_reader.c
	$(CC) -c ./srcs/file_reader.c

./solver.o: ./srcs/solver.c
	$(CC) -c ./srcs/solver.c

./make_board.o: ./srcs/make_board.c
	$(CC) -c ./srcs/make_board.c

./copy_board.o: ./srcs/copy_board.c
	$(CC) -c ./srcs/copy_board.c

clean:
	rm -rf ./bin

fclean: clean
	rm tetris
	rm tetriminos_file

re: fclean
	make all

bin: re
	make clean
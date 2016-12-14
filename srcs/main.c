#include "tetris.h"

int main()
{
    int i;
    int j;
    char *file;
    char ***box;
    int box_count;
    //char *path = "tetriminos_file";
    //char newboard[100] = "....##\n.#.#..\n.###..\n..#...\n.....#\n";

    file = filetostr("tetriminos_file");
    i = 0;
    if (valid_file(file))
    {
        box_count = count_box(file);
        printf("valid file\n");
        box = make_3d_box(file);
        /*while (i < box_count)
        {
            j = 0;
            while (j < 4)
            {
                printf("%s\n", box[i][j]);
                j++;
            }
            printf("\n");
            if (valid_all_box(box, i + 1))
                printf("box %i\n", i + 1);
            else
                printf("box %i is invalid\n", i + 1);
            i++;
        }
    }
    else{
        printf("invalid file\n");
    }*/
        printf("\nSolvedBoard:\n%s\n", board_solver(box, 11));
    }
    return (1);
}

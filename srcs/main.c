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
        while (i < box_count)
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
    }
    printf("\nSolvedBoard:\n%s\n", board_solver(box, 10));
    //place_piece
    /*int f;
    int pos;

    char *tmp;
    printf("Pos: ");
    scanf("%i", &pos);
    printf("Box: ");
    scanf("%i", &f);
    if (is_safe(newboard, box[f], pos, 6))
    {
        printf("piece is safe\n");
        place_piece(newboard, box[f], pos, f + 1);
    }
    else
    {
        printf("piece is not safe\n");
    }
    tmp = d2_to_d1(box[f]);
    newboard[pos] = '$';
    printf("board:\n%s\npiece:\n%s", newboard, tmp);*/
    return (1);
}
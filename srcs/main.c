#include "../includes/tetris.h"
int main()
{
    int i;
    int j;
    char ***box;

    i = 0;
    char *file = "...#\n.###\n....\n....\n\n....\n...#\n...#\n..##\n\n....\n.##.\n.##.\n....\n\n.#..\n###.\n....\n....\n\n";
    //char newboard[100] = "...\n...\n...\n";
    //char    newboard[100] = "#####\n##.##\n##.##\n#..##\n#####\n";
    char newboard[100] = ".....\n.....\n.....\n.....\n.....\n";
    if (valid_file(file))
    {
        box = make_box(file);
        while (i < 4)
        {
            j = 0;
            while (j < 4)
            {
                printf("%s\n", box[i][j]);
                j++;
            }
            printf("\n");
            i++;
        }
        //printf("%i\n", valid_all_box(box, 2));
    }
    else{
        printf("invalid file\n");
    }
    int f;
    scanf("%i", &f);
    if (is_safe(newboard, box[f], 8, 5))
        printf("%s\n", place_piece(newboard, box[f], 8, 5, 1));
    newboard[8] = '%';
    printf("%s", newboard);
    return (1);
}
#include "tetris.h"
/*
    DOES NOT WORK!!
    DO NOT USE!!
*/

char **rand_piece()
{
    int i;
    int block;
    char **twod;
    i = 4;
    int j = 0;
    srand(time(NULL));
    while (j < 2) 
    {
        char box[26] = "....\n....\n....\n....\n";
        block = 4;
        while (block > 0)
        {
            while (i != 4 && i != 9 && i != 14 && i != 19)
                i = (rand() % 19); 
            box[i] = '#';
            block--;
        }
        printf("%s\n", box);
        twod = make_two_Dim(box);
        if (valid_box(twod))
            return (twod);
        else
        {
            j++;
            free(twod);
            continue;
        }
    }
    return (NULL);
}
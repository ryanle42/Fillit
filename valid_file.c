#include <stdio.h>
#include "make_3d_block.c"
#include "valid_box.c"

int     valid_file(char *file)
{
    int lcount;
    int nlcount;
    int bcount;
    int i;

    i = 0;
    if (!file[i])
        return (0);    
    while (file[i])
    {
        nlcount = 0;
        bcount = 0;
        while (nlcount < 4)
        {
            lcount = 0;
            while (lcount < 4)
            {
                if (file[i] == '.' || file[i] == '#')
                {
                    if (file[i] == '#')
                        bcount++;
                    i++;
                    lcount++;
                }
                else
                    return (0);
            }
            if (file[i] == '\n')
            {
                i++;
                nlcount++;
            }
            else
                return (0);
        }
        if (bcount != 4)
            return (0);
        if (file[i] == '\n')
            i++;
        else
            return (0);
    }
    return (1);
}

int main()
{
    int i;
    int j;
    char ***box;

    i = 0;
    char *file = "...#\n.#.#\n....\n.#..\n\n....\n..#.\n..#.\n.##.\n\n";
    if (valid_file(file))
    {
        box = make_box(file);
        while (i < 2)
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
        printf("%i\n", valid_all_box(box, 2));
    }
    return (1);
}
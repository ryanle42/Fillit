#include "../includes/tetris.h"

int count_box(char *file)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (file[i])
    {
        if (file[i] == '\n')
            count++;
        i++;
    }
    return ((count + 1) / 5);
}

char ***make_3d_box(char *file)
{
    int i;
    int l;
    char ***box;
    int box_count;

    box_count = count_box(file);
    box = (char ***)malloc(sizeof(char **) * box_count);
    i = 0;
    l = 0;
   while (l < box_count)
    {
        box[l] = make_two_Dim(file, i);
        i += 21;
        l++;
    }
    return (box);
}
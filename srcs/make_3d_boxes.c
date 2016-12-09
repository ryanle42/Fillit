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

char ***file_to_block(char ***box, char *file)
{
    int i;
    int j;
    int k;
    int l;

    i = 0;
    l = 0;
   while (file[i])
    {
        j = 0;
        while (j < 4)
        {
            k = 0;
            while (k < 4)
            {
                box[l][j][k] = file[i];
                i++;
                k++;
            }
            box[l][j][k] = '\0';
            i++;
            j++;
        }
        while (file[i] == '\n')
            i++;
        l++;
    }
    return (box);
}

char ***make_box(char *file)
{
    char ***box;
    int i;
    int j;
    int box_count;

    box_count = count_box(file);
    box = (char ***)malloc(sizeof(char **) * box_count);
    i = 0;
    while (i < box_count)
    {
        box[i] = (char **)malloc(sizeof(char *) * 4);
        j = 0;
        while (j < 5)
        {
            box[i][j] = (char *)malloc(sizeof(char) * 5);
            j++;
        }
        i++;
    }
  return (file_to_block(box, file));
}
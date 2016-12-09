#include "tetris.h"

char **make_two_Dim(char *onedim)
{
    char **box;
    int i;
    int j;
    int k;
    
    i = 0;
    k = 0;
    box = (char **)malloc(sizeof(char *) * 4);
    while (i < 4)
    {
        j = 0;
        box[i] = (char *)malloc(sizeof(char) * 5);
        while (j < 4)
        {
            box[i][j] = onedim[k];
            j++;
            k++;
        }
        box[i][j] = '\0';
        while (onedim[k] == '\n')
            k++;
        i++;
    }
    return (box);
}
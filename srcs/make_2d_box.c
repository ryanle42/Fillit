#include "tetris.h"

char **make_two_Dim(char *onedim, int i)
{
    char **box;
    int k;
    int j;
    
    k = 0;
    box = (char **)malloc(sizeof(char *) * 4);
    while (k < 4)
    {
        j = 0;
        box[k] = (char *)malloc(sizeof(char) * 5);
        while (j < 4)
        {
            box[k][j] = onedim[i];
            j++;
            i++;
        }
        box[k][j] = '\0';
        while (onedim[i] == '\n')
            i++;
        k++;
    }
    return (box);
}
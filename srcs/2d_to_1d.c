#include "tetris.h"

char *d2_to_d1(char **box)
{
    int i;
    int j;
    char *a;
    int k;

    i = 0;
    j = 0;
    k = 0;
    a = (char *)malloc(sizeof(char)* 26);
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            a[k] = box[i][j];
            j++;
            k++;
        }
        a[k] = '\n';
        k++;
        i++;
    }
    a[k] = '\0';
    return (a);
}
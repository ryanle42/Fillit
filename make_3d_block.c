#include <stdlib.h>
#include <stdio.h>

int count_blocks(char *file)
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
    return (count / 5);
}

char ***file_to_block(char ***blocks, char *file, int block_num)
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
                blocks[l][j][k] = file[i];
                i++;
                k++;
            }
            blocks[l][j][k] = '\0';
            i++;
            j++;
        }
        while (file[i] == '\n')
            i++;
        l++;
    }
    return (blocks);
}

char ***make_blocks(char *file)
{
    char ***blocks;
    int i;
    int j;
    int k;
    int block_num;

    block_num = count_blocks(file);
    blocks = (char ***)malloc(sizeof(char **) * block_num);
    i = 0;
    while (i < block_num)
    {
        blocks[i] = (char **)malloc(sizeof(char *) * 4);
        j = 0;
        while (j < 5)
        {
            blocks[i][j] = (char *)malloc(sizeof(char) * 5);
            j++;
        }
        i++;
    }
  return (file_to_block(blocks, file, block_num));
}
int get_board_size(char *board)
{
    int i;
    
    i = 0;
    while (board[i] != '\n')
        i++;
    return (i);
}

int     is_safe(char *board, char **piece, int pos, int size)
{
    int block;
    int i;
    int j;
    int k;
    block = 4;

    i = 0;
    j = 0;
    k = 0;
    while (piece[i][j] != '#')
    {
        j++;
        if (j == 4)
        { 
            j = 0;
            i++;
        }
    }
    printf("pos: %i\n", pos);
    if (board[pos] != '.')
        return (0);
    block--;
    int l = 1;
    while (block > 0 && (pos < ((size * size) + size)))
    {
        if (j == 3)
            k--;
        j++;
        while (piece[i][j] != '#')
        {
            j++;
            k++;
            if (j >= 4)
            { 
                j = 0;
                i++;
                k++;
                pos += (size - 4);
           }
        }
        printf("k: %i\n", k);
        pos += (k + 1);
        printf("pos: %i\n", pos);
        if (board[pos] != '.')
            return (0);
        k = 0;
        block--;
    } 
    return (1);
}
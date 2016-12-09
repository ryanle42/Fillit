char    *place_piece(char *board, char **piece, int pos, int size)
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
    board[pos] = '$';
    block--;
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
        //printf("k: %i\n", k);
        pos += (k + 1);
        //printf("pos: %i\n", pos);
        board[pos] = '$';
        k = 0;
        block--;
    } 
    return (board);
}
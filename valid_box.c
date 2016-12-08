int valid_box(char **box)
{
    int i;
    int k;
    int dub_touch;
    int touch;
    int flag;

    flag = 0;
    dub_touch = 0;
    i = 0;
    while (i < 4)
    {
        k = 0;
        while (k < 4)
        {
            if (box[i][k] == '#')
            {
                touch = 0;
                if (k > 1 && box[i][k - 1] == '#')
                    touch++;
                if (k < 3 && box[i][k + 1] == '#')
                    touch++;
                if (i > 0 && box[i - 1][k] == '#')
                    touch++;
                if (i < 3 && box[i + 1][k] == '#')
                    touch++;
                if (touch > 1)
                {
                    dub_touch++;
                    flag++;
                }
                else if (touch == 1)
                    flag++;
                else if (touch == 0)
                    return (0);
            }
            k++;
        }
        i++;
    }
    return ((flag == 4 && dub_touch > 0) ? 1: 0);
}

int valid_all_box(char ***box, int box_count)
{
    int i;

    i = 0;
    while (i < box_count)
    {
        if (!valid_box(box[i]))
            return (0);
        i++;
    }
    return (1);
}
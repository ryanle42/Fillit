#include "tetris.h"

static int touch_check(char **box, int i, int k)
{
    int touch;

    touch = 0;
    if (k > 0 && box[i][k - 1] == '#')
        touch++;
    if (k < 3 && box[i][k + 1] == '#')
        touch++;
    if (i > 0 && box[i - 1][k] == '#')
        touch++;
    if (i < 3 && box[i + 1][k] == '#')
        touch++;
    return (touch);
}

int valid_box(char **box, int flag, int dub_touch, int touch)
{
    int i;
    int k;

    i = 0;
    while (i < 4)
    {
        k = 0;
        while (k < 4)
        {
            if (box[i][k] == '#')
            {
                touch = touch_check(box, i, k);
                if (touch > 1)
                    dub_touch++;
                if (touch >= 1)
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
        if (!valid_box(box[i], 0, 0, 0))
            return (0);
        i++;
    }
    return (1);
}
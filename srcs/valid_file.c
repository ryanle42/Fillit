#include "tetris.h"

int     valid_file(char *file)
{
    int lcount;
    int nlcount;
    int bcount;
    int i;

    i = 0;
    if (!file[i])
        return (0);    
    while (file[i])
    {
        nlcount = 0;
        bcount = 0;
        while (nlcount < 4)
        {
            lcount = 0;
            while (lcount < 4)
            {
                if (file[i] == '.' || file[i] == '#')
                {
                    if (file[i] == '#')
                        bcount++;
                    i++;
                    lcount++;
                }
                else
                    return (0);
            }
            if (file[i] == '\n')
            {
                i++;
                nlcount++;
            }
            else
                return (0);
        }
        if (bcount != 4)
            return (0);
        if (!file[i])
            return (1);
        if (file[i] == '\n' && !file[i + 1])
            return (0);
        if (file[i] == '\n')
            i++;
        else
            return (0);
    }
    return (1);
}
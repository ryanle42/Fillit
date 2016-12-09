#include "tetris.h"

int		file_len(char *path)
{
	int		fd;
	char	buf;
	int		len;
	int		status;

	fd = open(path, O_RDONLY);
	len = 0;
	while ((status = read(fd, &buf, 1)) > 0)
	{
		len++;
	}
	close(fd);
	if (status != 0)
		return (-1);
	return (len);
}
char	*filetostr(char *path, int file_length)
{
	int		fd;
	char	buf;
	int		i;
    char *file;

	file = (char*)malloc(file_length + 1);
	fd = open(path, O_RDONLY);
	i = 0;
	while (read(fd, &buf, 1))
	{
		file[i] = buf;
		i++;
	}
	file[i] = '\0';
	close(fd);
    return (file);
}
int main()
{
    int i;
    int j;
    char *file;
    char ***box;
    int box_count;
    char *path = "tetriminos_file";
    i = 0;
    //char *file = "...#\n.###\n....\n....\n\n....\n...#\n...#\n..##\n\n....\n.##.\n.##.\n....\n\n.#..\n###.\n....\n....\n";
    //char *file = "##..\n##..\n....\n....\n\n##..\n#...\n#...\n....\n";
    //char newboard[100] = "...\n...\n...\n";
    //char    newboard[100] = "#####\n##.##\n##.##\n#..##\n#####\n";
    //char newboard[100] = ".....\n.....\n.....\n.....\n.....\n";
    int file_length = file_len(path);
    //printf("%i", file_length);
    file = filetostr(path, file_length);
    //printf("%s", file);
    if (valid_file(file))
    {
        box_count = count_box(file);
        printf("valid file\n");
        box = make_box(file);
        while (i < box_count)
        {
            j = 0;
            while (j < 4)
            {
                printf("%s\n", box[i][j]);
                j++;
            }
            printf("\n");
            if (valid_all_box(box, i + 1))
                printf("box %i is valid\n", i + 1);
            else
                printf("box %i is invalid\n", i + 1);
            i++;
        }
    }
    else{
        printf("invalid file\n");
    }
 /*   int f;
    scanf("%i", &f);
    if (is_safe(newboard, box[f], 8, 5))
        printf("%s\n", place_piece(newboard, box[f], 8, 5, 1));
    printf("random num: \n");
    int k;
    for (k = 0; k < 4; k++)
    {
        printf("%i\n", rand() % 19);
    }
    //char **y = rand_piece();
    //char *z = d2_to_d1(y);
    //printf("%s\n", z);
  //  char **z;
   // z = rand_piece();
   // printf("%s\n", d2_to_d1(z));*/
    return (1);
}
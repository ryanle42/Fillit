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
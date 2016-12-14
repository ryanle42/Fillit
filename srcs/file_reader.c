#include "tetris.h"

int		file_len(char *path)
{
	int		fd;
	char	buf;
	int		len;
	int		status;

	if (!(fd = open(path, O_RDONLY)))
		return (0);
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

char	*filetostr(char *path)
{
	int		fd;
	char	buf;
	int		i;
    char *file;
    int file_length;

    file_length = file_len(path);
	file = (char*)malloc(file_length + 1);
	if (!(fd = open(path, O_RDONLY)))
		return (0);
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
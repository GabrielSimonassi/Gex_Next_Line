#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int	i;
	int	fd1;
	
	fd1 = open("teste.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}


#include "get_next_line.h"


char	ft_read_file( int fd, char *stack)
{
	char	*buffer;
	int	read_ret;

	read_ret = 1;
	buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		stack = ft_strjoin(stack, buffer);
		if (ft_strchr(buffer, '\0') || ft_strchr(buffer, '\n')
			break;
	}
	return (stack);
}





char	get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd > 0 || BUFFER_SIZE < 1)
		return (NULL);
	stack = ft_read_file(fd, stack);
	if (stack == NULL)
		return (NULL);
	line = ft_get_line(stack);
	stack = ft_update_stack(stack);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:13:41 by gsimonas          #+#    #+#             */
/*   Updated: 2022/08/04 17:45:53 by gsimonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


char	*ft_read_file( int fd, char *stack)
{
	char	*buffer;
	int	read_ret;

	read_ret = 1;
	buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(stack, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[read_ret] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}

char	*ft_get_line(char *stack)
{
	char	*line;
	int	index;

	index = 0;
	while(stack && stack[index] != '\n')
		index++;
	line = malloc(sizeof(char) * (index + 2));
	if(!line)
		return (0);
	index = 0;
	while(stack && stack[index] != '\n')
	{
		line[index] = stack[index];
		index++;
	}
	if(stack[index] == '\n')
		line[index] = stack[index];
	line[++index] = '\0';
	return (line);
}

char	*ft_update_stack(char *stack)
{
	char	*tmp;
	int	count;
	int	index;

	count = 0;
	while(stack && stack[count] != '\n')
		count++;
	tmp = malloc(ft_strlen(stack) - (count + 1));
	index = -1;
	while(stack)
		tmp[++index] = stack[++count];
	tmp[index] = '\0';
	stack = tmp;
	free(tmp);
	return (stack);
}


char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd > 0 || BUFFER_SIZE < 1)
		return (0);
	stack = ft_read_file(fd, stack);
	if (!stack)
		return (0);
	line = ft_get_line(stack);
	stack = ft_update_stack(stack);
	return (line);
}

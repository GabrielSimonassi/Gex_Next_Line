/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:13:41 by gsimonas          #+#    #+#             */
/*   Updated: 2022/08/08 14:44:31 by gsimonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


char	*ft_read_file(int fd, char *stack)
{
	char	*buffer;
	int	read_ret;

	buffer = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	read_ret = 1;
	while (read_ret != 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[read_ret] = '\0';
		stack = ft_strjoin(stack, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (stack);
}

char	*ft_get_line(char *stack)
{
	char	*line;
	int	index;

	index = 0;
	if (stack[index] == '\0')
		return (0);
	while(stack[index] && stack[index] != '\n')
		index++;
	line = malloc(sizeof(char) * (index + 2));
	if(!line)
		return (0);
	index = 0;
	while(stack[index] && stack[index] != '\n')
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
	if (stack[count] == '\0')
	{
		free(stack);
		return (0);
	}
	while(stack[count] && stack[count] != '\n')
		count++;
	tmp = malloc(sizeof(char) * (ft_strlen(stack) - count + 1));
	index = 0;
	count++;
	while(stack[count])
		tmp[index++] = stack[count++];
	tmp[index] = '\0';
	free(stack);
	return (tmp);
}


char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <=0)
		return (0);
	stack = ft_read_file(fd, stack);
	if (!stack)
		return (0);
	line = ft_get_line(stack);
	stack = ft_update_stack(stack);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:13:59 by gsimonas          #+#    #+#             */
/*   Updated: 2022/08/08 13:14:12 by gsimonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
{
        while (*s)
        {
                if (*s == (char)c)
                        return ((char *)s);
                s++;
        }
        if (c == 0)
                return ((char *)s);
        return (0);
}

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{       
	char	*ptr;
        size_t	index_1;
        size_t	index_2;

       	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (0);
	ptr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
        if (!ptr)
                return (0);
        index_1 = 0;
        index_2 = 0;
        while (s1[index_1] != '\0')
        {
                ptr[index_1] = ((char *)s1)[index_1];
                index_1++;
        }
        while (s2[index_2] != '\0')
        {
                ptr[index_1] = ((char *)s2)[index_2];
                index_1++;
                index_2++;
        }
        ptr[index_1] = '\0';
        return (ptr);
}

char    *ft_strdup(const char *s1)
{
        char    *ptr;
        char    *src;
        int     i;
        int     j;

        src = (char *)s1;
        i = ft_strlen(src) + 1;
        j = 0;
        if (i == 0)
                i = 1;
        ptr = (char *) malloc (i);
        if (!ptr)
                return (0);
        while (src[j] != '\0')
        {
                ptr[j] = src[j];
                j++;
        }
        ptr[j] = '\0';
        return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:13:59 by gsimonas          #+#    #+#             */
/*   Updated: 2022/08/04 17:19:46 by gsimonas         ###   ########.fr       */
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

char    *ft_strjoin(char const *s1, char const *s2)
{       
	char	*ptr;
        int	i;
        int	j;
        int	c;

        if (s1[0] == '\0')
		s1 = ft_strdup("");
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
        ptr = (char *) malloc((i + 1) * sizeof(char));
        if (!ptr)
                return (0);
        j = 0;
        c = 0;
        while (s1[j] != '\0')
        {
                ptr[j] = ((char *)s1)[j];
                j++;
        }
        while (s2[c] != '\0')
        {
                ptr[j] = ((char *)s2)[c];
                c++;
                j++;
        }
        ptr[j] = 0;
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

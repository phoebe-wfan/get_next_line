/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:14:09 by wfan              #+#    #+#             */
/*   Updated: 2022/12/22 17:14:24 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_1(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	else if (z == 1)
	{
		while (str[i])
			i++;
	}
	return (i);
}

size_t	ft_strlen_2(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen_1(src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen_1(src));
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*s;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = 0;
	}
	if (!line || !buffer)
		return (NULL);
	s = (char *)malloc(ft_strlen_1(line) + ft_strlen_1(buffer) + 1);
	if (!s)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(s, line, ft_strlen_1(line) + 1);
	ft_strlcpy(s + ft_strlen_1(line), buffer, ft_strlen_1(buffer) + 1);
	free(line);
	return (s);
}

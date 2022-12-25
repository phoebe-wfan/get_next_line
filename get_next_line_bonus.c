/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:20:14 by wfan              #+#    #+#             */
/*   Updated: 2022/12/25 16:44:50 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_end_line(char *str_rest)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen_1(str_rest);
	while (i < j)
	{
		if (str_rest[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*line_next(char *str_rest)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = ft_strlen_2(str_rest);
	if (!str_rest[j])
	{
		free((void *)str_rest);
		return (NULL);
	}
	next = (char *)malloc(ft_strlen_1(str_rest) - j + 1);
	if (!next)
		return (NULL);
	while (str_rest[j])
		next[i++] = str_rest[j++];
	next[i] = '\0';
	free((void *)str_rest);
	return (next);
}

char	*line_cpy(char *str_rest)
{
	int			i;
	char		*the_line;

	i = 0;
	if (!*str_rest)
		return (NULL);
	the_line = (char *)malloc(ft_strlen_2(str_rest) + 1);
	if (!the_line)
		return (NULL);
	while (str_rest[i] && str_rest[i] != '\n')
	{
		the_line[i] = str_rest[i];
		i++;
	}
	if (str_rest[i] == '\n')
	{
		the_line[i] = '\n';
		i++;
	}
	the_line[i] = '\0';
	return (the_line);
}

char	*line_read(int fd, char *str_rest)
{
	ssize_t			len;
	char			*str_buffer;

	len = 1;
	str_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!str_buffer)
		return (NULL);
	while (len && !check_end_line(str_rest))
	{
		len = read(fd, str_buffer, BUFFER_SIZE);
		if (len == -1)
		{
			if (str_rest)
				free(str_rest);
			free(str_buffer);
			return (NULL);
		}
		str_buffer[len] = '\0';
		str_rest = ft_strjoin(str_rest, str_buffer);
	}
	free(str_buffer);
	return (str_rest);
}

char	*get_next_line_bonus(int fd)
{
	static char	*str_rest[FD_NBR];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	str_rest[fd] = line_read(fd, str_rest[fd]);
	if (!str_rest[fd])
		return (NULL);
	line = line_cpy(str_rest[fd]);
	str_rest[fd] = line_next(str_rest[fd]);
	return (line);
}

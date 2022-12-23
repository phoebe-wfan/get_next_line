/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:04:51 by wfan              #+#    #+#             */
/*   Updated: 2022/12/23 15:47:09 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen_2(str_rest);
	if (!str_rest[j])
	{
		free(str_rest);
		return (NULL);
	}
	new = malloc(ft_strlen_1(str_rest) - j + 1);
	if (!new)
		return (NULL);
	while (str_rest[j])
		new[i++] = str_rest[j++];
	new[i] = 0;
	free(str_rest);
	return (new);
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
	while (str_rest[i] && str_rest[i] != '\0')
	{
		the_line[i] = str_rest[i];
		i++;
	}
	if (str_rest[i] == '\n')
		the_line[i++] = '\n';
	the_line[i] = '\0';
	return (the_line);
}

char	*line_read(int fd, char *str_rest)
{
	ssize_t				len;
	char			*str_buffer;

	len = 1;
	str_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!str_buffer)
		return (NULL);
	while (len && !endline_check(str_rest))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			if (str_rest)
				free(str_rest);
			free(str_buffer);
			return (NULL);
		}
		str_buffer[len] = 0;
		str_rest = ft_strjoin(str_rest, str_buffer);
	}
	free(str_buffer);
	return (str_rest);
}

char	*get_next_line(int fd)
{
	static char	*str_rest;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	str_rest = line_read(fd, str_rest);
	if (!str_rest)
		return (NULL);
	line = line_cpy(str_rest);
	str_rest = line_next(str_rest);
	return (line);
}

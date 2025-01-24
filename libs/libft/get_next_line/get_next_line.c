/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:24:54 by mmaksymi          #+#    #+#             */
/*   Updated: 2024/12/13 13:08:03 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_buffer(int fd, char *buffer)
{
	ssize_t	count;

	count = ft_strlen(buffer);
	if (count > 0)
		return (count);
	count = read(fd, buffer, BUFFER_SIZE);
	if (count > 0)
		buffer[count] = '\0';
	return (count);
}

int	append_buffer(char *buffer, char **line, int length)
{
	char	*new_line;
	int		size;

	size = ft_strlen(*line);
	new_line = malloc(size + length + 1);
	if (!new_line)
	{
		free(*line);
		return (1);
	}
	ft_memcpy(new_line, *line, size);
	ft_memcpy(new_line + size, buffer, length);
	new_line[size + length] = '\0';
	free(*line);
	*line = new_line;
	ft_memcpy(buffer, buffer + length, BUFFER_SIZE - length + 1);
	return (0);
}

char	*ft_cutgnl(int count, char *buffer, char *line)
{
	if (count < 0)
	{
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
		free(line);
		return (NULL);
	}
	if (count == 0)
	{
		if (ft_strlen(line) != 0)
			return (line);
		free(line);
		return (NULL);
	}
	return (NULL);
}

char	*ft_findnl(char *buffer, int *length, int count)
{
	char	*out;

	out = ft_strchr(buffer, '\n');
	if (out)
		*length = out - buffer + 1;
	else
		*length = count;
	return (out);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*nlstart;
	int			length;
	ssize_t		count;

	line = malloc(1);
	if (!line)
		return (NULL);
	*line = '\0';
	while (1)
	{
		count = read_buffer(fd, buffer);
		if (count <= 0)
		{
			line = ft_cutgnl(count, buffer, line);
			return (line);
		}
		nlstart = ft_findnl(buffer, &length, count);
		if (append_buffer(buffer, &line, length))
			return (NULL);
		else if (nlstart)
			break ;
	}
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:34:42 by jwozniak          #+#    #+#             */
/*   Updated: 2024/03/20 20:34:44 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *buffer, char *buf)
{
	char	*res;

	res = ft_strjoin(buffer, buf);
	free(buffer);
	return (res);
}

char	*make_new(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	res = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!res)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	free(buffer);
	return (res);
}

char	*make_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	int		reading;
	char	*read_buffer;

	read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (free(buffer), NULL);
	reading = read(fd, read_buffer, BUFFER_SIZE);
	while (reading >= 0)
	{
		read_buffer[reading] = '\0';
		buffer = join_free(buffer, read_buffer);
		if (!res)
			return (free(read_buffer), NULL);
		if (ft_strchr(read_buffer, '\n') || reading == 0)
			break ;
		reading = read(fd, read_buffer, BUFFER_SIZE);
	}
	free(read_buffer);
	if (reading == -1)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = make_line(buffer);
	buffer = make_new(buffer);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

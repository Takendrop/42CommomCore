/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:37:44 by jwozniak          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:45 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	make_path(char *relative_path, t_so_long *so_long)
{
	int	path_len;

	path_len = ft_strlen(relative_path);
	if (path_len < 4)
		return (0);
	if (ft_strcmp(&relative_path[path_len - 4], ".ber") != 0)
		return (0);
	so_long->map_path = ft_strdup(relative_path);
	return (1);
}

int	open_and_allocate_map(t_so_long *so_long, int line_count)
{
	so_long->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	so_long->map_fd = open(so_long->map_path, O_RDONLY);
	if (so_long->map_fd < 0 || !so_long->map)
		return (0);
	return (1);
}

int	read_and_process_line(t_so_long *so_long, char *line, int i, int line_count)
{
	if (so_long->w == -1)
		so_long->w = ft_strlen(line) - 1;
	if (i == line_count - 1)
		so_long->map[i] = ft_substr(line, 0, ft_strlen(line));
	else
		so_long->map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	return (i + 1);
}

int	finalize_map(t_so_long *so_long, int i)
{
	if (so_long->w == -1)
	{
		close(so_long->map_fd);
		return (0);
	}
	so_long->h = i;
	so_long->map[i] = NULL;
	close(so_long->map_fd);
	return (1);
}

int	fill_map_array(t_so_long *so_long)
{
	char	*line;
	int		i;
	int		line_count;

	line = NULL;
	i = 0;
	line_count = count_lines(so_long);
	if (!open_and_allocate_map(so_long, line_count))
		return (0);
	while (1)
	{
		line = get_next_line(so_long->map_fd);
		if (line == NULL)
			return (finalize_map(so_long, i));
		i = read_and_process_line(so_long, line, i, line_count);
		free(line);
	}
}

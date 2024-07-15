/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:58:10 by jwozniak          #+#    #+#             */
/*   Updated: 2024/06/26 13:58:11 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	init_so_long(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		return (0);
	so_long->last_timestamp = 0;
	so_long->game_width = -1;
	so_long->game_height = -1;
	so_long->player = ft_calloc(sizeof(t_player), 1);
	if (!so_long->player)
		exit(EXIT_FAILURE);
	so_long->window = mlx_new_window(so_long->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
		WINDOW_TITLE);
	if (!so_long->window)
		return (0);
	mlx_hook(so_long->window, 17, 0, close_window, so_long);
	load_sprites(so_long);
	return (1);
}

static void	print_map(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->game_height)
	{
		ft_printf("%s\n", so_long->map[i]);
		i++;
	}
}

int	init_map(int argc, char *argv[], t_so_long *so_long)
{
	if (argc != 2)
		return (0);
	if (!make_path(argv[1], so_long))
		return (0);
	if (!fill_map_array(so_long))
	{
		close(so_long->map_fd);
		return (0);
	}
	close(so_long->map_fd);
	print_map(so_long);
	draw(so_long);
	return (1);
}

int	make_path(char *relative_path, t_so_long *so_long)
{
	int	path_len;

	path_len = ft_strlen(relative_path);
	if (path_len < 4)
		return (0);
	if (ft_strcmp(&relative_path[path_len - 4], ".ber") != 0)
		return (0);
	so_long->map_path = relative_path;
	ft_printf("%s\n", so_long->map_path);
	return (1);
}

static int	count_lines(t_so_long *so_long)
{
	char	*line;
	int	count;

	count = 0;
	so_long->map_fd = open(so_long->map_path, O_RDONLY);
	if (so_long->map_fd < 0)
		return (0);
	while ((line = get_next_line(so_long->map_fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(so_long->map_fd);
	return (count);
}

int	fill_map_array(t_so_long *so_long)
{
	char	*line;
	int		i;
	int		line_count;

	line = "";
	i = 0;
	line_count = count_lines(so_long);
	so_long->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!so_long->map)
		return (0);
	so_long->map_fd = open(so_long->map_path, O_RDONLY);
	if (so_long->map_fd < 0)
		return (0);
	while (line)
	{
		line = get_next_line(so_long->map_fd);
		if (line == NULL)
		{
			if (so_long->game_width == -1)
				return (0);
			so_long->game_height = i;
			so_long->map[i] = NULL;
			return (1);
		}
		if (so_long->game_width == -1)
			so_long->game_width = ft_strlen(line) - 1;
		if (i == line_count - 1)
			so_long->map[i] = ft_substr(line, 0, ft_strlen(line));
		else
			so_long->map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		i++;
		free(line);
	}
	return (1);
}

// TO ADD:
/*
	if (!convert_lst(so_long))
		error;
	if (!size_check(so_long))
		error;
	if (!allowed_char(so_long))
		error;
	if (!sides_is_wall(so_long))
		error;
	if (!required_char(so_long))
		error;
*/


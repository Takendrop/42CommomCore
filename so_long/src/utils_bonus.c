/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:38:01 by jwozniak          #+#    #+#             */
/*   Updated: 2024/07/23 18:38:01 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	print_map(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->h)
	{
		ft_printf("%s\n", so_long->map[i]);
		i++;
	}
}

void	print_map_copy(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	count_lines(t_so_long *so_long)
{
	char	*line;
	int		count_lines;

	count_lines = 0;
	so_long->map_fd = open(so_long->map_path, O_RDONLY);
	if (so_long->map_fd < 0)
		return (0);
	line = get_next_line(so_long->map_fd);
	while (line != NULL)
	{
		count_lines++;
		free(line);
		line = get_next_line(so_long->map_fd);
	}
	close(so_long->map_fd);
	return (count_lines);
}

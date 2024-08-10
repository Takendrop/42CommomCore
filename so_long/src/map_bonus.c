/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:41:00 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/07 20:41:01 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	flood_fill(t_so_long *so_long, int x, int y)
{
	if (x < 0 || x >= so_long->h || y < 0 || y >= so_long->w
		|| so_long->map_copy[x][y] == '1' || so_long->map_copy[x][y] == 'V')
		return ;
	if (so_long->map_copy[x][y] == 'C')
		so_long->c_count++;
	if (so_long->map_copy[x][y] == 'E')
		so_long->exit_found = 1;
	so_long->map_copy[x][y] = 'V';
	flood_fill(so_long, x + 1, y);
	flood_fill(so_long, x - 1, y);
	flood_fill(so_long, x, y + 1);
	flood_fill(so_long, x, y - 1);
}

int	validate_map(t_so_long *so_long)
{
	int		i;

	i = 0;
	so_long->map_copy = (char **)malloc(sizeof(char *) * so_long->h);
	while (i < so_long->h)
	{
		so_long->map_copy[i] = ft_strdup(so_long->map[i]);
		i++;
	}
	flood_fill(so_long, so_long->p->pos[0], so_long->p->pos[1]);
	i = 0;
	while (i < so_long->h)
	{
		free(so_long->map_copy[i]);
		i++;
	}
	free(so_long->map_copy);
	so_long->map_copy = NULL;
	return (so_long->c_count == so_long->c_total && so_long->exit_found);
}

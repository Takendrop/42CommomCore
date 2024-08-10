/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:36:56 by jwozniak          #+#    #+#             */
/*   Updated: 2024/07/23 18:36:57 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	draw_walls(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->h)
	{
		j = 0;
		while (j < so_long->w)
		{
			if (so_long->map[i][j] == '1')
			{
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->sprites[0], j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}

static void	draw_collectibles(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->h)
	{
		j = 0;
		while (j < so_long->w)
		{
			if (so_long->map[i][j] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->sprites[1], j * TILE_SIZE, i * TILE_SIZE);
			else if (so_long->map[i][j] == 'c')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->sprites[2], j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

static void	draw_gate(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->h)
	{
		j = 0;
		while (j < so_long->w)
		{
			if (so_long->map[i][j] == 'E')
			{
				if (so_long->c_total == 0)
					mlx_put_image_to_window(so_long->mlx, so_long->win,
						so_long->sprites[4], j * TILE_SIZE, i * TILE_SIZE);
				else
					mlx_put_image_to_window(so_long->mlx, so_long->win,
						so_long->sprites[3], j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}

static void	draw_player(t_so_long *so_long)
{
	int		x;
	int		y;
	void	*current;

	x = so_long->p->pos[0] * TILE_SIZE;
	y = so_long->p->pos[1] * TILE_SIZE;
	if (so_long->p->is_facing_right)
		current = so_long->p->idle_right;
	else
		current = so_long->p->idle_left;
	mlx_put_image_to_window(so_long->mlx, so_long->win, current, x, y);
}

void	draw_all(t_so_long *so_long)
{
	draw_walls(so_long);
	draw_collectibles(so_long);
	draw_gate(so_long);
	draw_player(so_long);
}

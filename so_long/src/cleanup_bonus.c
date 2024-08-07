/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:49:56 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/04 17:49:57 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	cleanup_player(t_so_long *so_long)
{
	int	i;

	if (so_long->p)
	{
		i = 0;
		while (i < N_WALK_FRAMES)
		{
			if (so_long->p->walk_right[i])
			{
				mlx_destroy_image(so_long->mlx, so_long->p->walk_right[i]);
				so_long->p->walk_right[i] = NULL;
			}
			if (so_long->p->walk_left[i])
			{
				mlx_destroy_image(so_long->mlx, so_long->p->walk_left[i]);
				so_long->p->walk_left[i] = NULL;
			}
			i++;
		}
		free(so_long->p);
		so_long->p = NULL;
	}
}

void	cleanup_map_and_path(t_so_long *so_long)
{
	int	i;

	if (so_long->map)
	{
		i = 0;
		while (i < so_long->h)
		{
			if (so_long->map[i])
			{
				free(so_long->map[i]);
				so_long->map[i] = NULL;
			}
			i++;
		}
		free(so_long->map);
		so_long->map = NULL;
	}
	if (so_long->map_path)
	{
		free(so_long->map_path);
		so_long->map_path = NULL;
	}
}

void	cleanup_window_and_display(t_so_long *so_long)
{
	if (so_long->win)
	{
		mlx_destroy_window(so_long->mlx, so_long->win);
		so_long->win = NULL;
	}
	if (so_long->mlx)
	{
		mlx_destroy_display(so_long->mlx);
		free(so_long->mlx);
		so_long->mlx = NULL;
	}
}

static void	cleanup_sprites(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < N_SPRITES)
	{
		if (so_long->sprites[i])
		{
			mlx_destroy_image(so_long->mlx, so_long->sprites[i]);
			so_long->sprites[i] = NULL;
		}
		i++;
	}
	if (so_long->p)
	{
		i = 0;
		if (so_long->p->idle_right && so_long->p->idle_left)
		{
			mlx_destroy_image(so_long->mlx, so_long->p->idle_right);
			so_long->p->idle_right = NULL;
			mlx_destroy_image(so_long->mlx, so_long->p->idle_left);
			so_long->p->idle_left = NULL;
		}
	}
}

void	cleanup(t_so_long *so_long)
{
	if (so_long)
	{
		cleanup_map_and_path(so_long);
		cleanup_sprites(so_long);
		cleanup_player(so_long);
		cleanup_window_and_display(so_long);
	}
}

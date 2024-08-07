/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:37:34 by jwozniak          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:35 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_map(t_so_long *so_long)
{
	if (!wall_check(so_long))
		return (0);
	if (!collectible_check(so_long))
		return (0);
	if (!gate_check(so_long))
		return (0);
	if (!player_check(so_long))
		return (0);
	if (!validate_map(so_long))
		return (0);
	return (1);
}

int	init_so_long(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		return (0);
	so_long->win = NULL;
	so_long->w = -1;
	so_long->h = -1;
	so_long->game_over = 0;
	so_long->p = ft_calloc(1, sizeof(t_player));
	if (!so_long->p)
		return (0);
	so_long->p->moves = 0;
	so_long->p->cf = 0;
	so_long->p->is_walking = 0;
	so_long->p->is_facing_right = 1;
	gettimeofday(&so_long->p->lft, NULL);
	so_long->map = NULL;
	so_long->map_path = NULL;
	so_long->c_count = 0;
	so_long->exit_found = 0;
	return (1);
}

int	init_map(int argc, char *argv[], t_so_long *so_long)
{
	if (argc != 2)
	{
		error_msg(1);
		return (0);
	}
	if (!make_path(argv[1], so_long))
		return (0);
	if (!fill_map_array(so_long))
	{
		error_msg(2);
		return (0);
	}
	if (!check_map(so_long))
	{
		error_msg(3);
		return (0);
	}
	return (1);
}

int	init_window(t_so_long *so_long)
{
	int	win_width;
	int	win_height;

	win_width = so_long->w * TILE_SIZE;
	win_height = so_long->h * TILE_SIZE;
	so_long->win = mlx_new_window(so_long->mlx, win_width,
			win_height, WINDOW_TITLE);
	if (!so_long->win)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:37:39 by jwozniak          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:40 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	update_player_animation(t_so_long *so_long, double elapsed_time)
{
	if (so_long->p->is_walking)
	{
		if (elapsed_time >= FRAME_DURATION)
		{
			so_long->p->cf = (so_long->p->cf + 1) % N_WALK_FRAMES;
			if (so_long->p->cf == 0)
				so_long->p->is_walking = 0;
			gettimeofday(&so_long->p->lft, NULL);
		}
	}
	else
	{
		so_long->p->cf = 0;
		gettimeofday(&so_long->p->lft, NULL);
	}
}

static void	draw_scene(t_so_long *so_long)
{
	if (so_long->win)
	{
		mlx_clear_window(so_long->mlx, so_long->win);
		draw_all(so_long);
	}
}

static int	game_loop(t_so_long *so_long)
{
	struct timeval		c_time;
	double				elapsed_time;

	if (so_long->game_over)
		return (0);
	gettimeofday(&c_time, NULL);
	elapsed_time = (c_time.tv_sec - so_long->p->lft.tv_sec)
		+ (c_time.tv_usec - so_long->p->lft.tv_usec) / 1000000.0;
	draw_scene(so_long);
	update_player_animation(so_long, elapsed_time);
	return (1);
}

static int	initialize_game(t_so_long *so_long, int argc, char *argv[])
{
	if (!init_so_long(so_long))
		return (0);
	if (!init_map(argc, argv, so_long))
	{
		cleanup_player(so_long);
		cleanup_map_and_path(so_long);
		cleanup_window_and_display(so_long);
		return (0);
	}
	if (!init_window(so_long))
	{
		cleanup_map_and_path(so_long);
		cleanup_player(so_long);
		cleanup_window_and_display(so_long);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_so_long	so_long;

	if (!initialize_game(&so_long, argc, argv))
		exit(EXIT_FAILURE);
	if (!load_sprites(&so_long))
	{
		cleanup(&so_long);
		exit(EXIT_FAILURE);
	}
	draw_all(&so_long);
	mlx_hook(so_long.win, 17, 0, handle_close, &so_long);
	mlx_key_hook(so_long.win, key_hook, &so_long);
	mlx_loop_hook(so_long.mlx, game_loop, &so_long);
	mlx_loop(so_long.mlx);
	cleanup(&so_long);
	exit(EXIT_SUCCESS);
}

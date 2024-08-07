/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:37:56 by jwozniak          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:56 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_move_valid(t_so_long *so_long, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= so_long->w || new_y >= so_long->h)
		return (0);
	if (new_x == so_long->p->pos[0] && new_y == so_long->p->pos[1])
		return (0);
	if (so_long->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	update_player_position(t_so_long *so_long, int new_x, int new_y)
{
	so_long->p->is_walking = 1;
	gettimeofday(&so_long->p->lft, NULL);
	so_long->p->pos[0] = new_x;
	so_long->p->pos[1] = new_y;
	so_long->p->moves++;
	ft_printf("Move count: %d\n", so_long->p->moves);
}

static void	handle_collectible(t_so_long *so_long, int new_x, int new_y)
{
	if (so_long->map[new_y][new_x] == 'C')
	{
		so_long->c_total--;
		so_long->map[new_y][new_x] = 'c';
		if (so_long->c_total == 0)
			ft_printf("Exit has opened\n");
		else
			ft_printf("Collectibles to pick up: %d\n", so_long->c_total);
	}
}

static void	handle_exit(t_so_long *so_long, int new_x, int new_y)
{
	if (so_long->map[new_y][new_x] == 'E' && so_long->c_total == 0)
	{
		so_long->game_over = 1;
		ft_printf("Congratulations! You finished in %d moves!\n",
			so_long->p->moves);
		mlx_loop_end(so_long->mlx);
	}
}

void	handle_move(t_so_long *so_long, int new_x, int new_y)
{
	if (!is_move_valid(so_long, new_x, new_y))
		return ;
	update_player_position(so_long, new_x, new_y);
	handle_collectible(so_long, new_x, new_y);
	handle_exit(so_long, new_x, new_y);
	if (!so_long->game_over)
		draw_all(so_long);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:37:30 by jwozniak          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:31 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	handle_close(t_so_long *so_long)
{
	mlx_loop_end(so_long->mlx);
	return (1);
}

int	key_hook(int keycode, t_so_long *so_long)
{
	int	new_x;
	int	new_y;

	new_x = so_long->p->pos[0];
	new_y = so_long->p->pos[1];
	if (keycode == 119)
		new_y -= 1;
	else if (keycode == 115)
		new_y += 1;
	else if (keycode == 97)
	{
		new_x -= 1;
		so_long->p->is_facing_right = 0;
	}
	else if (keycode == 100)
	{
		new_x += 1;
		so_long->p->is_facing_right = 1;
	}
	else if (keycode == 65307)
		mlx_loop_end(so_long->mlx);
	handle_move(so_long, new_x, new_y);
	return (1);
}

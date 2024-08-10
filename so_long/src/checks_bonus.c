/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:38:41 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/07 20:38:46 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	player_check(t_so_long *so_long)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
			{
				player_count++;
				so_long->p->pos[0] = j;
				so_long->p->pos[1] = i;
			}
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

int	wall_check(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->w)
	{
		if (so_long->map[0][i] != '1' ||
		so_long->map[so_long->h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < so_long->h)
	{
		if (so_long->map[i][0] != '1' ||
		so_long->map[i][so_long->w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	collectible_count(t_so_long *so_long)
{
	int	i;
	int	j;
	int	c_count;

	c_count = 0;
	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}

int	collectible_check(t_so_long *so_long)
{
	int	count;

	count = collectible_count(so_long);
	if (count < 1)
		return (0);
	so_long->c_total = count;
	return (1);
}

int	gate_check(t_so_long *so_long)
{
	int	i;
	int	j;
	int	gate_count;

	gate_count = 0;
	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E')
				gate_count++;
			j++;
		}
		i++;
	}
	return (gate_count == 1);
}

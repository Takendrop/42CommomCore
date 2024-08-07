/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:01:56 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/04 18:01:57 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	load_idle_sprites(t_so_long *so_long, int *width, int *height)
{
	so_long->sprites[0] = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/wall.xpm", width, height);
	so_long->sprites[1] = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/collectible_close.xpm", width, height);
	so_long->sprites[2] = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/collectible_open.xpm", width, height);
	so_long->sprites[3] = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/gate_close.xpm", width, height);
	so_long->sprites[4] = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/gate_open.xpm", width, height);
	so_long->p->idle_right = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/right.xpm", width, height);
	so_long->p->idle_left = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/left.xpm", width, height);
}

static void	load_player_walk_right(t_so_long *so_long, int *width, int *height)
{
	int		i;
	char	*path;
	char	*full_path;
	char	*itoa_res;

	i = 0;
	while (i < N_WALK_FRAMES)
	{
		itoa_res = ft_itoa(i);
		path = ft_strjoin("./assets/right", itoa_res);
		free(itoa_res);
		full_path = ft_strjoin(path, ".xpm");
		free(path);
		so_long->p->walk_right[i] = mlx_xpm_file_to_image(so_long->mlx,
				full_path, width, height);
		free(full_path);
		i++;
	}
}

static void	load_player_walk_left(t_so_long *so_long, int *width, int *height)
{
	int		i;
	char	*path;
	char	*full_path;
	char	*itoa_res;

	i = 0;
	while (i < N_WALK_FRAMES)
	{
		itoa_res = ft_itoa(i);
		path = ft_strjoin("./assets/left", itoa_res);
		free(itoa_res);
		full_path = ft_strjoin(path, ".xpm");
		free(path);
		so_long->p->walk_left[i] = mlx_xpm_file_to_image(so_long->mlx,
				full_path, width, height);
		free(full_path);
		i++;
	}
}

static int	check_sprites_loaded(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < N_SPRITES)
	{
		if (!so_long->sprites[i])
			return (0);
		i++;
	}
	if (!so_long->p->idle_right || !so_long->p->idle_left)
		return (0);
	i = 0;
	while (i < N_WALK_FRAMES)
	{
		if (!so_long->p->walk_right[i] || !so_long->p->walk_left[i])
			return (0);
		i++;
	}
	return (1);
}

int	load_sprites(t_so_long *so_long)
{
	int	width;
	int	height;

	load_idle_sprites(so_long, &width, &height);
	load_player_walk_right(so_long, &width, &height);
	load_player_walk_left(so_long, &width, &height);
	if (!check_sprites_loaded(so_long))
	{
		error_msg(4);
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:43:27 by jwozniak          #+#    #+#             */
/*   Updated: 2024/06/26 15:43:28 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	draw_block(int x, int y, void *sprite, t_so_long *so_long)
{
	if (x < -TILE_SIZE || y < -TILE_SIZE || x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return ;
	mlx_put_image_to_window(so_long->mlx, so_long->window, sprite, x, y);
}

void	draw(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->game_height)
	{
		j = 0;
		while (j < so_long->game_width)
		{
			if (so_long->map[i][j] == '0' || so_long->map[i][j] == 'P'
			|| so_long->map[i][j] == 'C')
			{
				mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->sprites[0], j * TILE_SIZE, i * TILE_SIZE);
			}
			else if (so_long->map[i][j] == '1')
			{
				mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->sprites[1], j * TILE_SIZE, i * TILE_SIZE);
			}
			else if (so_long->map[i][j] == 'E')
			{
				mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->sprites[3], j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}

void    load_sprites(t_so_long *so_long)
{
	int width;
	int height;

	so_long->sprites[0] = mlx_xpm_file_to_image(so_long->mlx, "./assets/background.xpm", &width, &height);
	so_long->sprites[1] = mlx_xpm_file_to_image(so_long->mlx, "./assets/wall.xpm", &width, &height);
	so_long->sprites[2] = mlx_xpm_file_to_image(so_long->mlx, "./assets/collectible.xpm", &width, &height);
	so_long->sprites[3] = mlx_xpm_file_to_image(so_long->mlx, "./assets/gate_close.xpm", &width, &height);
	if (!so_long->sprites[0] || !so_long->sprites[1] || !so_long->sprites[2] || !so_long->sprites[3])
	{
		ft_printf("Error loading sprites");
		exit(EXIT_FAILURE);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:01:21 by jwozniak          #+#    #+#             */
/*   Updated: 2024/06/26 13:01:22 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	game_loop()
{
	return (1);
}

int	main(int argc, char *argv[])
{
	t_so_long	so_long;

	init_so_long(&so_long);
	mlx_put_image_to_window(so_long.mlx, so_long.window, so_long.sprites[0], 0, 0);
	init_map(argc, argv, &so_long);
	mlx_loop_hook(so_long.mlx, game_loop, &so_long);
	mlx_loop(so_long.mlx);
}

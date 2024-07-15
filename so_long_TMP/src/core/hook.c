/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:43:38 by jwozniak          #+#    #+#             */
/*   Updated: 2024/06/26 15:43:40 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	close_window(t_so_long *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->window);
	exit(EXIT_SUCCESS);
	return (0);
}


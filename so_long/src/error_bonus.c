/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:39:48 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/07 20:39:52 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	error_msg(int error_n)
{
	if (error_n == 1)
		ft_printf("Error: You must pass only one map path !\n");
	if (error_n == 2)
		ft_printf("Error: Unable to open the map file !\n");
	if (error_n == 3)
		ft_printf("Error: The map is not valid !\n");
	if (error_n == 4)
		ft_printf("Error: Unable to open sprites !\n");
}

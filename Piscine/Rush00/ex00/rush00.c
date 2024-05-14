/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:46:17 by slamb             #+#    #+#             */
/*   Updated: 2023/11/25 18:47:11 by slamb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	firstlast(int x)
{
	int	counterfl;

	ft_putchar('o');
	counterfl = 0;
	while (counterfl < x -2)
	{
		ft_putchar('-');
		counterfl++;
	}
	if (x != 1)
	{
		ft_putchar('o');
	}
}

void	middle(int x)
{
	int	counterm;

	ft_putchar('|');
	counterm = 0;
	while (counterm < x -2)
	{
		ft_putchar(' ');
		counterm++;
	}
	if (x != 1)
	{
		ft_putchar('|');
	}
}

void	rush(int x, int y)
{
	int	counter;

	if (x >= 1 && y >= 1)
	{
		firstlast(x);
		ft_putchar('\n');
		counter = 0;
		while (counter < y -2)
		{
			middle(x);
			ft_putchar('\n');
			counter++;
		}
		if (y != 1)
		{
			firstlast(x);
		}
	}
}

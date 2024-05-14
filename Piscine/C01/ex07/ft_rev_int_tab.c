/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:28:52 by jwozniak          #+#    #+#             */
/*   Updated: 2023/11/28 10:28:55 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	mid;
	int	i;
	int	tmp;

	if (size % 2 == 0)
	{
		mid = size / 2;
	}
	else
	{
		mid = (size - 1) / 2;
	}
	i = 0;
	while (i < mid)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

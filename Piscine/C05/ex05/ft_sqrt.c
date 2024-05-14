/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <jwozniak@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:43:22 by jwozniak          #+#    #+#             */
/*   Updated: 2023/12/10 16:43:23 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	mid;
	
	mid = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	while (mid <= nb / mid)
	{
		if (mid * mid == nb)
			return (mid);
		mid++;
	}
	return (0);
}
#include<stdio.h>
int	main(void)
{
	printf("%i", ft_sqrt(1000000006)); 
}

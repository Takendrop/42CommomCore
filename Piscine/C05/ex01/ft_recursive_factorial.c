/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <jwozniak@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:41:20 by jwozniak          #+#    #+#             */
/*   Updated: 2023/12/10 16:41:24 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 0;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	if (nb >= 2)
	{
		result = nb * ft_recursive_factorial(nb - 1);
	}
	return (result);
}

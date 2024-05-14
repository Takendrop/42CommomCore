/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:17:51 by jwozniak          #+#    #+#             */
/*   Updated: 2024/03/05 22:17:51 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_digits_recursive(int n)
{
	int	count;

	count = 0;
	if (n / 10 != 0)
	{
		count = print_digits_recursive(n / 10);
		ft_putchar('0' + (n % 10));
	}
	else
		ft_putchar('0' + n);
	return (count + 1);
}

int	ft_print_id(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	count += print_digits_recursive(n);
	return (count);
}

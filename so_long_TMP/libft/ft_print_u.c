/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:45:00 by jwozniak          #+#    #+#             */
/*   Updated: 2024/03/05 22:45:01 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_digits_recursive(unsigned int n)
{
	int	count;

	count = 0;
	if (n / 10 != 0)
		count += print_digits_recursive(n / 10);
	ft_putchar('0' + (n % 10));
	return (count + 1);
}

int	ft_print_u(unsigned int n)
{
	if (n == 0)
		return (ft_putchar('0'));
	else
		return (print_digits_recursive(n));
}

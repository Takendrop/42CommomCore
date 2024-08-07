/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:52:31 by jwozniak          #+#    #+#             */
/*   Updated: 2024/03/05 21:52:32 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_digits(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	put_hex(unsigned int num, const char format)
{
	char	*hex_digits;

	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		put_hex(num / 16, format);
	ft_putchar(hex_digits[num % 16]);
}

int	ft_print_x(unsigned int num, const char format)
{
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		put_hex(num, format);
		return (hex_digits(num));
	}
}

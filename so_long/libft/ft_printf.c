/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:34:05 by jwozniak          #+#    #+#             */
/*   Updated: 2024/03/05 20:34:07 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_s(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_print_p(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_id(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_x(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_len += formats(args, format[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:58:14 by jwozniak          #+#    #+#             */
/*   Updated: 2024/02/29 14:58:16 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n)
{
	int	sign;

	if (n < 0)
		sign = 1;
	else
		sign = 0;
	return (sign);
}

static int	get_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, int n, int len)
{
	int	i;
	int	digit;

	i = len - 1;
	while (n != 0)
	{
		digit = n % 10;
		str[i] = digit + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_length(n);
	sign = is_negative(n);
	str = (char *)malloc((len + sign + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len + sign] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		if (sign)
		{
			n *= -1;
			str[0] = '-';
		}
		fill_str(str + sign, n, len);
	}
	return (str);
}

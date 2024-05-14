/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:29:37 by jwozniak          #+#    #+#             */
/*   Updated: 2023/12/03 16:29:39 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	const char	*h;
	const char	*n;

	if (!*to_find)
	{
		return (str);
	}
	while (*str)
	{
		h = str;
		n = to_find;
		while (*n && *h == *n)
		{
			h++;
			n++;
			if (!*n)
			{
				return (str);
			}
		}
		str++;
	}
	return (NULL);
}

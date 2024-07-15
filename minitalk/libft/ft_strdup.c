/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:43:26 by jwozniak          #+#    #+#             */
/*   Updated: 2024/02/27 17:43:28 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(s) + 1;
	new_s = (char *)malloc(len);
	if (!new_s)
		return (NULL);
	if (ft_strlcpy(new_s, s, len) >= len)
	{
		free(new_s);
		return (NULL);
	}
	return (new_s);
}

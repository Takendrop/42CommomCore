/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:58:04 by jwozniak          #+#    #+#             */
/*   Updated: 2024/02/28 15:58:07 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	trimmed_len(const char *s, const char *set)
{
	size_t	len;

	len = 0;
	while (s && *s && is_in_set(*s, set))
		s++;
	while (*s)
	{
		s++;
		len++;
	}
	if (len)
	{
		s--;
		while (s && is_in_set(*s, set))
		{
			s--;
			len--;
		}
	}
	return (len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;
	char	*trimmed_str;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	len = trimmed_len(s1, set);
	trimmed_str = (char *)malloc(len + 1);
	if (!trimmed_str)
		return (NULL);
	while (*s1 && is_in_set(*s1, set))
		s1++;
	i = 0;
	while (i < len)
	{
		trimmed_str[i] = *s1++;
		i++;
	}
	trimmed_str[len] = '\0';
	return (trimmed_str);
}

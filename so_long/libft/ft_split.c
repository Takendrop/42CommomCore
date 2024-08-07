/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:47:05 by jwozniak          #+#    #+#             */
/*   Updated: 2024/02/28 16:47:06 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	*allocate_memory(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	return (mem);
}

static void	free_split(char **split)
{
	char	**ptr;

	if (split)
	{
		ptr = split;
		while (*ptr)
		{
			free(*ptr++);
		}
		free(split);
	}
}

char	**ft_split(const char *s, char c)
{
	size_t		n;
	size_t		i;
	char		**split;
	const char	*start;

	n = count_words(s, c);
	split = (char **)allocate_memory((n + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < n)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		split[i] = ft_substr(start, 0, s - start);
		if (!split[i])
			return (free_split(split), NULL);
		split[i++][s - start] = '\0';
	}
	split[i] = NULL;
	return (split);
}

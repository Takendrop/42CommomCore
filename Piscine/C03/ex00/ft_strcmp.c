/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:28:48 by jwozniak          #+#    #+#             */
/*   Updated: 2023/12/03 16:28:52 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (s1[i] || s2[i])
	{
		value = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (value)
		{
			return (value);
		}
		i++;
	}
	return (value);
}

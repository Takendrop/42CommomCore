/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:56:27 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 19:56:29 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	toUpper(char *str)
{
	while (*str)
	{
		*str = std::toupper(*str);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	bool	first;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOICE *" << std::endl;
		return (1);
	}
	first = true;
	for (int i = 1; i < argc; ++i)
	{
		if (!first)
			std::cout << " ";
		first = false;
		toUpper(argv[i]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return (0);
}

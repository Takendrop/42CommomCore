/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:22:29 by jwozniak          #+#    #+#             */
/*   Updated: 2024/05/23 16:22:30 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	args_check(int argc, char **argv)
{
	int		i;

	if (argc != 3)
	{
		ft_printf("Error: Run client with 2 arguments\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf("Error: Invalid PID (non-numeric characters)\n");
			exit(EXIT_FAILURE);
		}
	}
	if (*argv[2] == 0)
	{
		ft_printf("Error: Invalid message (empty)\n");
		exit(EXIT_FAILURE);
	}
}

void	send_message(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 8)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			shift++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	args_check(argc, argv);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_message(pid, str, ft_strlen(str));
	return (EXIT_SUCCESS);
}

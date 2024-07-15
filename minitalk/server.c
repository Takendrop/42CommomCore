/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:22:51 by jwozniak          #+#    #+#             */
/*   Updated: 2024/05/23 16:22:53 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

t_message	g_message = {0, 0};

void	bit_handler(int signal)
{
	if (signal == SIGUSR2)
		g_message.c |= (1 << g_message.bit_index);
	g_message.bit_index++;
	if (g_message.bit_index == 8)
	{
		ft_printf("%c", g_message.c);
		if (g_message.c == '\0')
			ft_printf("\n");
		g_message.c = 0;
		g_message.bit_index = 0;
	}
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_handler = bit_handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1 handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR2 handler");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server's PID: %d\n", pid);
	setup_signal_handlers();
	while (1)
	{
	}
	return (0);
}

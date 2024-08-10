/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:02:26 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 17:02:32 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_state(philo, "is thinking");
	ft_usleep(philo->time_to_sleep);
}

void	sleep_philo(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	print_state(philo, "has taken a fork");
	print_state(philo, "is eating");
	philo->last_meal = get_time_ms();
	philo->meals_eaten++;
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	has_died(t_philo *philo)
{
	long long	current_time;
	long long	death_time;

	current_time = get_time_ms();
	death_time = philo->last_meal + philo->time_to_die;
	return (current_time > death_time);
}

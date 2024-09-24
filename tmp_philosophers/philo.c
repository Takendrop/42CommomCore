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
	if (philo->program->end_flag)
        return;
	print_state(philo, "is thinking");
}

void	sleep_philo(t_philo *philo)
{
	if (philo->program->end_flag)
        return;
	print_state(philo, "is sleeping");
	ft_usleep(philo->program->args[3]);
}

void	eat(t_philo *philo)
{
	if (philo->program->end_flag)
        return;
	if (philo->id % 2 == 0)
	{
    	pthread_mutex_lock(philo->r_fork);
		print_state(philo, "has taken a fork");
    	pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a fork");
	}
	else
	{
    	pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a fork");
    	pthread_mutex_lock(philo->r_fork);
		print_state(philo, "has taken a fork");
	}
	if (philo->program->end_flag)
    {
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
        return;
    }
	print_state(philo, "is eating");
	philo->last_meal = get_time_ms();
	philo->meals_eaten++;
	ft_usleep(philo->program->args[2]);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (philo->meals_eaten == philo->program->args[4])
	{
		pthread_mutex_lock(&philo->program->meal_lock);
		philo->ate_all = 1;
		pthread_mutex_unlock(&philo->program->meal_lock);
	}
}

int	is_dead(t_philo *philo)
{
	long long	current_time;
	long long	death_time;

	current_time = get_time_ms();
	death_time = philo->last_meal + philo->program->args[1];
	//printf("current time: %lld\n last meal: %lld \ndeath time: %lld\n", current_time, philo->last_meal, death_time);
	return (current_time > death_time);
}

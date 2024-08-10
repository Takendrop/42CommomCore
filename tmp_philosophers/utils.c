/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:55:18 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 16:55:19 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time_ms()
{
	struct timeval	tv;
	long long		time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_ms);
}

void	ft_usleep(long long ms)
{
	usleep(ms * 1000);
}

void print_state(t_philo *philo, const char *state)
{
    long long		timestamp;
    pthread_mutex_t	*write_lock;

    timestamp = get_time_ms() - philo->start_time;
    write_lock = philo->write_lock;
    pthread_mutex_lock(write_lock);
    printf("%lld %d %s\n", timestamp, philo->id, state);
    pthread_mutex_unlock(write_lock);
}

void	cleanup(t_program *program, pthread_mutex_t *forks, int num_philos)
{
	int i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	free(program->philos);
	free(forks);
}
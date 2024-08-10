/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:16:57 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 17:16:58 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_program(t_program *program)
{
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;

	dead_lock = program->dead_lock;
	meal_lock = program->meal_lock;
	write_lock = program->write_lock;
	program->dead_flag = 0;
	pthread_mutex_init(&dead_lock, NULL);
	pthread_mutex_init(&meal_lock, NULL);
	pthread_mutex_init(&write_lock, NULL);
	program->dead_lock = dead_lock;
	program->meal_lock = meal_lock;
	program->write_lock = write_lock;
}

void init_philos(t_program *program, int num_philos, long long time_to_die, long long time_to_eat, long long time_to_sleep, int num_times_to_eat)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *)malloc(num_philos * sizeof(pthread_mutex_t));
	if (!forks)
	{
		perror("malloc");
		exit(1);
	}
	program->philos = (t_philo *)malloc(num_philos * sizeof(t_philo));
	if (!program->philos)
	{
		perror("malloc");
		free(forks); // Free forks if malloc for philosophers fails
		exit(1);
	}
	
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	
	i = 0;
	while (i < num_philos)
	{
		program->philos[i].id = i + 1;
		program->philos[i].eating = 0;
		program->philos[i].meals_eaten = 0;
		program->philos[i].last_meal = get_time_ms();
		program->philos[i].time_to_die = time_to_die;
		program->philos[i].time_to_eat = time_to_eat;
		program->philos[i].time_to_sleep = time_to_sleep;
		program->philos[i].start_time = get_time_ms();
		program->philos[i].num_of_philos = num_philos;
		program->philos[i].num_times_to_eat = num_times_to_eat;
		program->philos[i].dead = &program->dead_flag;
		program->philos[i].r_fork = &forks[i];
		program->philos[i].l_fork = &forks[(i + 1) % num_philos];
		program->philos[i].write_lock = &program->write_lock;
		program->philos[i].dead_lock = &program->dead_lock;
		program->philos[i].meal_lock = &program->meal_lock;
		i++;
	}
}

void	init_threads(t_program *program, int num_philos, pthread_t *threads)
{
	int i;

	i = 0;
	while (i < num_philos)
	{
		pthread_create(&threads[i], NULL, philosopher_routine, &program->philos[i]);
		i++;
	}
}
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

void	init_program(t_program *program, int argc, char **argv)
{
	int				i;

	program->args = (int *)malloc((argc - 1) * sizeof(int));
	if (!program->args)
	{
		perror("malloc");
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		program->args[i - 1] = atoi(argv[i]);
		i++;
	}
	program->all_ate = 0;
	program->end_flag = 0;
	program->dead_flag = 0;
	program->start_time = get_time_ms();
	pthread_mutex_init(&program->end_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);
}

void	init_philos(t_program *program)
{
	pthread_mutex_t	*forks;
	int				i;

    forks = (pthread_mutex_t *)malloc(program->args[0] * sizeof(pthread_mutex_t));
    if (!forks)
    {
        perror("malloc");
        exit(1);
    }
    i = 0;
    while (i < program->args[0])
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    program->forks = forks;
    program->philos = (t_philo *)malloc(program->args[0] * sizeof(t_philo));
    if (!program->philos)
    {
        perror("malloc");
        exit(1);
    }
    i = 0;
    while (i < program->args[0])
    {
        program->philos[i].id = i + 1;
        program->philos[i].ate_all = 0;
		program->philos[i].meals_eaten = 0;
        program->philos[i].last_meal = get_time_ms();
        program->philos[i].r_fork = &program->forks[i];
        program->philos[i].l_fork = &program->forks[(i + 1) % program->args[0]];
        program->philos[i].program = program;
        i++;
    }
}

void	init_and_join_threads(t_program *program, pthread_t *threads)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < program->args[0])
	{
		pthread_create(&threads[i], NULL, philosopher_routine, &program->philos[i]);
		usleep(100);
		i++;
	}
	pthread_create(&monitor_thread, NULL, monitor_routine, program);
	i = 0;
    while (i < program->args[0])
    {
        pthread_join(threads[i], NULL);
        i++;
    }
    pthread_join(monitor_thread, NULL);
}
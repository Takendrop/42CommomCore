/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:55:03 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 16:55:05 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
    t_philo	*philo;

    philo = (t_philo *)arg;
    while (!philo->program->end_flag)
    {
        think(philo);
        eat(philo);
        sleep_philo(philo);
    }
    return (NULL);
}

int	all_philosophers_ate(t_program *program)
{
    int	i;
    int all_ate;

    i = 0;
    all_ate = 1;
    while (i < program->args[0])
    {
        if (!program->philos[i].ate_all)
        {
            all_ate = 0;
            break;
        }
        i++;
    }
    return (all_ate);
}

void	*monitor_routine(void *arg)
{
    t_program	*program;
    int			i;

    program = (t_program *)arg;
    while (!program->end_flag)
    {
        i = 0;
        while (i < program->args[0])
        {
            if (is_dead(&program->philos[i]))
            {
                pthread_mutex_lock(&program->dead_lock);
				pthread_mutex_lock(&program->write_lock);
				print_state(&program->philos[i], "died");
                program->dead_flag = 1;
                pthread_mutex_unlock(&program->dead_lock);
				pthread_mutex_unlock(&program->write_lock);
				pthread_mutex_lock(&program->end_lock);
				program->end_flag = 1;
				pthread_mutex_unlock(&program->end_lock);
                return (NULL);
            }
            i++;
        }
		pthread_mutex_lock(&program->meal_lock);
        if (all_philosophers_ate(program))
        {
            pthread_mutex_lock(&program->end_lock);
            program->end_flag = 1;
            pthread_mutex_unlock(&program->end_lock);
        }
		pthread_mutex_unlock(&program->meal_lock);
		usleep(1000);
    }
    return (NULL);
}

int	main(int argc, char **argv)
{
    t_program	program;
    pthread_t	*threads;

    if (argc < 5 || argc > 6)
    {
        fprintf(stderr, "Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return (1);
    }
    init_program(&program, argc, argv);
    init_philos(&program);
    threads = (pthread_t *)malloc(program.args[0] * sizeof(pthread_t));
    if (!threads)
    {
        perror("malloc");
        return (1);
    }
    init_and_join_threads(&program, threads);
    cleanup(&program);
    free(threads);
    return (0);
}
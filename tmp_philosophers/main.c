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
    t_philo *philo;
    int dead_flag;

    philo = (t_philo *)arg;
    dead_flag = 0;
    
    while (!dead_flag)
    {
        think(philo);
        eat(philo);
        sleep_philo(philo);

        if (has_died(philo))
        {
            pthread_mutex_lock(philo->dead_lock);
            *philo->dead = 1;
            pthread_mutex_unlock(philo->dead_lock);
            print_state(philo, "died");
            dead_flag = 1;
        }
    }
    return (NULL);
}

int	all_philosophers_ate(t_program *program)
{
    int i;
    int all_ate;

    i = 0;
    all_ate = 1;
    while (i < program->philos->num_of_philos)
    {
        if (program->philos[i].meals_eaten < program->philos[i].num_times_to_eat)
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
    t_program *program;
    int i;
    int dead_flag;

    program = (t_program *)arg;
    dead_flag = 0;
    
    while (!dead_flag)
    {
        i = 0;
        while (i < program->philos->num_of_philos)
        {
            if (has_died(&program->philos[i]))
            {
                pthread_mutex_lock(&program->dead_lock);
                program->dead_flag = 1;
                pthread_mutex_unlock(&program->dead_lock);
                print_state(&program->philos[i], "died");
                return (NULL);
            }
            i++;
        }
        if (all_philosophers_ate(program))
        {
            pthread_mutex_lock(&program->dead_lock);
            program->dead_flag = 1;
            pthread_mutex_unlock(&program->dead_lock);
        }
        usleep(10000);
    }
    return (NULL);
}

int	main(int argc, char **argv)
{
    t_program	program;
    pthread_t	*threads;
    pthread_t	monitor_thread;
    int			i;
    int			num_philos;
    long long	time_to_die;
    long long	time_to_eat;
    long long	time_to_sleep;
    int			num_times_to_eat;

    if (argc < 5 || argc > 6)
    {
        fprintf(stderr, "Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return (1);
    }
    num_philos = atoi(argv[1]);
    time_to_die = atoll(argv[2]);
    time_to_eat = atoll(argv[3]);
    time_to_sleep = atoll(argv[4]);
    num_times_to_eat = (argc == 6) ? atoi(argv[5]) : -1;
    init_program(&program);
    init_philos(&program, num_philos, time_to_die, time_to_eat, time_to_sleep, num_times_to_eat);
    threads = (pthread_t *)malloc(num_philos * sizeof(pthread_t));
    if (!threads)
    {
        perror("malloc");
        return (1);
    }
    i = 0;
    while (i < num_philos)
    {
        pthread_create(&threads[i], NULL, philosopher_routine, &program.philos[i]);
        i++;
    }
    pthread_create(&monitor_thread, NULL, monitor_routine, &program);
    i = 0;
    while (i < num_philos)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
    pthread_join(monitor_thread, NULL);
    cleanup(&program, program.philos[0].r_fork, num_philos);
    free(threads);
    return (0);
}
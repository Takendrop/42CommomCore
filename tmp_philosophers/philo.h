/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:55:12 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 16:55:14 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					eating;
	int					meals_eaten;
	long long			last_meal;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			start_time;
	int					num_of_philos;
	int					num_times_to_eat;
	int					*dead;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
}	t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}	t_program;

void		*philosopher_routine(void *arg);
void		*monitor_routine(void *arg);
long long	get_time_ms();
void		ft_usleep(long long ms);
void		print_state(t_philo *philo, const char *state);
void		think(t_philo *philo);
void		sleep_philo(t_philo *philo);
void		eat(t_philo *philo);
int			has_died(t_philo *philo);
int			all_philosophers_ate(t_program *program);
void		init_program(t_program *program);
void		init_philos(t_program *program, int num_philos, long long time_to_die, long long time_to_eat, long long time_to_sleep, int num_times_to_eat);
void		init_threads(t_program *program, int num_philos, pthread_t *threads);
void		cleanup(t_program *program, pthread_mutex_t *forks, int num_philos);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:42:26 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 16:46:01 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

# include "input.h"

# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define GRAY	"\033[1;30m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CIAN	"\033[1;36m"
# define WHITE	"\033[1;37m"

typedef pthread_mutex_t	t_mtx;

typedef enum e_threadop
{
	INIT,
	LOCK,
	UNLOCK,
	JOIN,
	DETACH,
	CREATE,
	DESTROY,
}	t_threadop;

typedef enum e_timecode
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
}	t_timecode;

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKING_FIRST_FORK,
	TAKING_SECOND_FORK,
	DYING,
}	t_philo_status;

typedef struct s_forks
{
	t_mtx	fork;
	int		id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	long		last_meal_time;
	bool		is_full;
	pthread_t	thread_id;
	t_mtx		mutex;
	t_fork		*first_fork;
	t_fork		*second_fork;
}	t_philo;

typedef struct s_simulation
{
	long	num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	limit_meals;
	long	start_time;
	long	num_threads_running;
	bool	end;
	bool	threads_ready;
	t_philo	*philos;
	t_fork	*forks;
	t_mtx	struct_mutex;
	t_mtx	write_mutex;
}	t_simulation;

void	print_error(const char *msg, bool exit);
void	print_debug(const char *msg);

void	*solid_malloc(size_t bytes);
void	solid_mutex(t_mtx *mutex, t_threadop threadop);
void	solid_thread(pthread_t *thread, void *(*thread_func)(void *), \
	void *arg, t_threadop threadop);

long	gettime(t_timecode time_code);

bool	get_bool(t_mtx *mutex, bool *var);
void	set_bool(t_mtx *mutex, bool *dest, bool value);
long	get_long(t_mtx *mutex, long *var);
void	set_long(t_mtx *mutex, long *dest, long value);
void	increase_long(t_mtx *mutex, long *value);
bool	simulation_finished(t_simulation *simulation);

void	setup_simulation(t_simulation *simulation);
void	clean_simulation(t_simulation *simulation);

void	run_simulation(t_simulation *simulation);

void	write_action(t_philo_status status, t_simulation *simulation, \
	t_philo *philo);

#endif

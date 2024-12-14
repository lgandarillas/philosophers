/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:52:29 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/08 12:54:04 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static bool	all_threads_running(t_mtx *mutex, long *num_threads_runnig, \
	long num_philos)
{
	bool	done;

	done = false;
	solid_mutex(mutex, LOCK);
	if (*num_threads_runnig == num_philos)
		done = true;
	solid_mutex(mutex, UNLOCK);
	return (done);
}

static bool	all_philos_full(t_simulation *simulation)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < simulation->num_philos)
	{
		philo = &simulation->philos[i];
		if (get_long(&philo->mutex, &philo->meals_counter) \
			< simulation->limit_meals)
			return (false);
	}
	return (true);
}

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->mutex, &philo->is_full) == true)
		return (false);
	elapsed = gettime_millis() - \
		get_long(&philo->mutex, &philo->last_meal_time);
	time_to_die = philo->simulation->time_to_die;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

static void	check_philos_alive(t_simulation *simulation)
{
	int	i;

	i = -1;
	while (++i < simulation->num_philos && \
		!get_bool(&simulation->mutex, &simulation->end))
	{
		if (philo_died(simulation->philos + i))
		{
			set_bool(&simulation->mutex, &simulation->end, true);
			print_action(DYING, simulation, simulation->philos + i);
			break ;
		}
	}
}

void	*supervisor(void *arg)
{
	t_simulation	*simulation;

	simulation = (t_simulation *)arg;
	while (!all_threads_running(&simulation->mutex, \
		&simulation->num_threads_running, simulation->num_philos))
		usleep(100);
	while (!get_bool(&simulation->mutex, &simulation->end))
	{
		if (simulation->limit_meals > 0 && all_philos_full(simulation))
		{
			usleep(500);
			set_bool(&simulation->mutex, &simulation->end, true);
			break ;
		}
		check_philos_alive(simulation);
	}
	return (NULL);
}

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

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->mutex, &philo->is_full) == true)
		return (false);
	elapsed = gettime(MILLISECONDS) - \
		get_long(&philo->mutex, &philo->last_meal_time);
	time_to_die = philo->simulation->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}

void	*supervisor(void *arg)
{
	t_simulation	*simulation;
	int				i;

	simulation = (t_simulation *)arg;
	while (all_threads_running(&simulation->struct_mutex, \
		&simulation->num_threads_running, simulation->num_philos == false))
		;
	while (get_bool(&simulation->struct_mutex, &simulation->end) == false)
	{
		i = -1;
		while (++i < simulation->num_philos && \
			get_bool(&simulation->struct_mutex, &simulation->end) == false)
		{
			if (philo_died(simulation->philos + i) == true)
			{
				set_bool(&simulation->struct_mutex, &simulation->end, true);
				write_action(DYING, simulation, simulation->philos + i);
			}
		}
	}
	return (NULL);
}

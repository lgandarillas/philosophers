/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:28:09 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 19:28:19 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	*one_philo_routine(void *arg)
{
	t_simulation	*simulation;
	t_philo			*philo;

	philo = (t_philo *)arg;
	simulation = philo->simulation;
	while (!get_bool(&simulation->mutex, &simulation->threads_ready))
		usleep(100);
	set_long(&philo->mutex, &philo->last_meal_time, gettime_millis());
	increase_long(&simulation->mutex, &simulation->num_threads_running);
	print_action(TAKING_FIRST_FORK, simulation, philo);
	while (!get_bool(&simulation->mutex, &simulation->end))
		usleep(100);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	t_simulation	*simulation;

	simulation = philo->simulation;
	solid_mutex(&philo->first_fork->mutex, LOCK);
	print_action(TAKING_FIRST_FORK, simulation, philo);
	solid_mutex(&philo->second_fork->mutex, LOCK);
	print_action(TAKING_SECOND_FORK, simulation, philo);
	set_long(&philo->mutex, &philo->last_meal_time, gettime_millis());
	increase_long(&philo->mutex, &philo->meals_counter);
	print_action(EATING, simulation, philo);
	usleep(simulation->time_to_eat * 1e3);
	solid_mutex(&philo->first_fork->mutex, UNLOCK);
	solid_mutex(&philo->second_fork->mutex, UNLOCK);
}

static void	think(t_philo *philo)
{
	t_simulation	*simulation;
	long			time_to_think;

	simulation = philo->simulation;
	print_action(THINKING, simulation, philo);
	if (simulation->num_philos % 2 == 0)
		return ;
	time_to_think = simulation->time_to_eat - \
		4 * simulation->time_to_sleep;
	if (time_to_think < 0)
		time_to_think = simulation->time_to_sleep / 8;
	usleep(time_to_think * 1e3);
}

static void	*multiple_philo_routine(void *arg)
{
	t_simulation	*simulation;
	t_philo			*philo;

	philo = (t_philo *)arg;
	simulation = philo->simulation;
	while (!get_bool(&simulation->mutex, &simulation->threads_ready))
		usleep(100);
	set_long(&philo->mutex, &philo->last_meal_time, gettime_millis());
	increase_long(&simulation->mutex, &simulation->num_threads_running);
	if (philo->id % 2 == 0)
		usleep(500);
	while (!get_bool(&simulation->mutex, &simulation->end))
	{
		if (philo->is_full)
			break ;
		eat(philo);
		print_action(SLEEPING, simulation, philo);
		usleep(simulation->time_to_sleep * 1e3);
		think(philo);
	}
	return (NULL);
}

void	run_simulation(t_simulation *simulation)
{
	int		i;

	if (simulation->limit_meals == 0)
		return ;
	if (simulation->num_philos == 1)
	{
		solid_thread(&simulation->philos[0].pthread_id, one_philo_routine, \
			&simulation->philos[0], CREATE);
	}
	else
	{
		i = -1;
		while (++i < simulation->num_philos)
			solid_thread(&simulation->philos[i].pthread_id, \
				multiple_philo_routine, &simulation->philos[i], CREATE);
	}
	solid_thread(&simulation->pthread_supervisor, \
		supervisor, simulation, CREATE);
	simulation->start_time = gettime_millis();
	set_bool(&simulation->mutex, &simulation->threads_ready, true);
	i = -1;
	while (++i < simulation->num_philos)
		solid_thread(&simulation->philos[i].pthread_id, NULL, NULL, JOIN);
	set_bool(&simulation->mutex, &simulation->end, true);
	solid_thread(&simulation->pthread_supervisor, NULL, NULL, JOIN);
}

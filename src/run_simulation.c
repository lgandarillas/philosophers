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
	set_long(&philo->mutex, &philo->last_meal_time, gettime(MILLISECONDS));
	increase_long(&simulation->mutex, &simulation->num_threads_running);
	write_action(TAKING_FIRST_FORK, simulation, philo);
	while (!simulation_finished(simulation))
		usleep(200);
	return (NULL);
}

static void	one_philo_simulation(t_simulation *simulation)
{
	t_philo	*philo;
	long	start_time;

	philo = &simulation->philos[0];
	start_time = gettime(MILLISECONDS);
	set_long(&simulation->mutex, &simulation->start_time, start_time);
	set_long(&philo->mutex, &philo->last_meal_time, start_time);
	solid_thread(&philo->pthread_id, one_philo_routine, philo, CREATE);
	solid_thread(&simulation->pthread_supervisor, \
		supervisor, simulation, CREATE);
	set_bool(&simulation->mutex, &simulation->threads_ready, true);
	solid_thread(&philo->pthread_id, NULL, NULL, JOIN);
	set_bool(&simulation->mutex, &simulation->end, true);
	solid_thread(&simulation->pthread_supervisor, NULL, NULL, JOIN);
}

void	run_simulation(t_simulation *simulation)
{
	if (simulation->limit_meals == 0)
		return ;
	else if (simulation->num_philos == 1)
		one_philo_simulation(simulation);
	else
		printf("Multiple philos not implemented yet\n");
}

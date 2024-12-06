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

static void	*single_philo(void *arg)
{
	t_simulation	*simulation;
	t_philo			*philo;

	simulation = (t_simulation *)arg;
	philo = &simulation->philos[0];
	while (!get_bool(&simulation->struct_mutex, &simulation->threads_ready))
		;
	set_long(&philo->mutex, &philo->last_meal_time, gettime(MILLISECONDS));
	increase_long(&simulation->struct_mutex, &simulation->num_threads_running);
	write_action(TAKING_FIRST_FORK, simulation, philo);
	while (!simulation_finished(simulation))
		usleep(200);
	return (NULL);
}

void	run_simulation(t_simulation *simulation)
{
	if (simulation->limit_meals == 0)
		return ;
	else if (simulation->num_philos == 1)
		solid_thread(&simulation->philos[0].thread_id, single_philo, \
			&simulation, CREATE);
	else
		printf("HOLA\n");
}

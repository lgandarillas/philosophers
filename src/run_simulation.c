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

void	one_philo_simulation(t_simulation *simulation)
{
	t_philo	*philo;
	long	start_time;
	long	time_to_die;

	philo = &simulation->philos[0];
	start_time = gettime(MILLISECONDS);
	set_long(&simulation->mutex, &simulation->start_time, start_time);
	set_long(&philo->mutex, &philo->last_meal_time, start_time);
	time_to_die = get_long(&simulation->mutex, &simulation->time_to_die);
	usleep(time_to_die);
	set_bool(&simulation->mutex, &simulation->end, true);
	write_action(DYING, simulation, philo);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:01:41 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 20:01:52 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_action(t_philo_status status, t_simulation *simulation, \
	t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECONDS) - simulation->start_time;
	solid_mutex(&simulation->write_mutex, LOCK);
	if ((status == TAKING_FIRST_FORK || status == TAKING_SECOND_FORK) \
		&& !simulation_finished(simulation))
		printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !simulation_finished(simulation))
		printf("%-6ld %d is eating\n", elapsed, philo->id);
	else if (status == SLEEPING && !simulation_finished(simulation))
		printf("%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !simulation_finished(simulation))
		printf("%-6ld %d is thinking\n", elapsed, philo->id);
	else if (status == DYING)
		printf("%-6ld %d died\n", elapsed, philo->id);
	solid_mutex(&simulation->write_mutex, UNLOCK);
}

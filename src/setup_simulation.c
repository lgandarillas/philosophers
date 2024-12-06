/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:16:00 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 16:16:12 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	setup_simulation(t_simulation *simulation)
{
	int	i;

	simulation->end = false;
	simulation->philos = solid_malloc(sizeof(t_philo) * simulation->num_philos);
	simulation->forks = solid_malloc(sizeof(t_fork) * simulation->num_philos);
	i = -1;
	while (++i < simulation->num_philos)
	{
		solid_mutex_handle(&simulation->forks[i].fork, INIT);
		simulation->forks[i].id = i;
	}
}

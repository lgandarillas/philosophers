/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:06:34 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 17:06:44 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	clean_simulation(t_simulation *simulation)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < simulation->num_philos)
	{
		philo = simulation->philos + i;
		solid_mutex(&philo->mutex, DESTROY);
	}
	solid_mutex(&simulation->write_mutex, DESTROY);
	solid_mutex(&simulation->struct_mutex, DESTROY);
	free(simulation->forks);
	free(simulation->philos);
}

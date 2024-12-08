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

static void	assign_forks(t_simulation *simulation, int philo_position)
{
	t_philo	*philo;
	int		num_philos;

	philo = &simulation->philos[philo_position];
	num_philos = simulation->num_philos;
	philo->first_fork = &simulation->forks[(philo_position + 1) % num_philos];
	philo->second_fork = &simulation->forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &simulation->forks[philo_position];
		philo->second_fork = \
			&simulation->forks[(philo_position + 1) % num_philos];
	}
}

static void	setup_philos(t_simulation *simulation)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < simulation->num_philos)
	{
		philo = simulation->philos + i;
		philo->id = i + 1;
		philo->is_full = false;
		philo->meals_counter = 0;
		philo->last_meal_time = 0;
		philo->thread_id = 0;
		solid_mutex(&philo->mutex, INIT);
		assign_forks(simulation, i);
	}
}

void	setup_simulation(t_simulation *simulation)
{
	int	i;

	simulation->end = false;
	simulation->threads_ready = false;
	simulation->start_time = gettime(MILLISECONDS);
	simulation->num_threads_running = 0;
	simulation->philos = solid_malloc(sizeof(t_philo) * simulation->num_philos);
	simulation->forks = solid_malloc(sizeof(t_fork) * simulation->num_philos);
	i = -1;
	while (++i < simulation->num_philos)
	{
		solid_mutex(&simulation->forks[i].fork, INIT);
		simulation->forks[i].id = i;
	}
	setup_philos(simulation);
}

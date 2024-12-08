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

/*
static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->mutex, &philo->is_full))
		return (false);
	elapsed = gettime(MILLISECONDS) - \
		get_long(&philo->mutex, &philo->last_meal_time);
	time_to_die = philo->simulation->time_to_die / 1e3;
	if (elapsed > time_to_die)
		return (true);
	return (false);
}
*/

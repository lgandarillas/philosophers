/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_and_getters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:37:24 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 16:37:32 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	get_bool(t_mtx *mutex, bool *var)
{
	bool	result;

	solid_mutex_handler(mutex, LOCK);
	result = *var;
	solid_mutex_handler(mutex, UNLOCK);
	return (result);
}

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	solid_mutex_handler(mutex, LOCK);
	*dest = value;
	solid_mutex_handler(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *var)
{
	long	result;

	solid_mutex_handler(mutex, LOCK);
	result = *var;
	solid_mutex_handler(mutex, UNLOCK);
	return (result);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	solid_mutex_handler(mutex, LOCK);
	*dest = value;
	solid_mutex_handler(mutex, UNLOCK);
}

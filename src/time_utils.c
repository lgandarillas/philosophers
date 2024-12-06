/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:22:30 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 16:22:42 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	gettime(t_timecode time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		print_error("[ERROR] : gettimeofday() failed.\n", true);
	if (time_code == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1e3));
	else if (time_code == MILLISECONDS)
		return (tv.tv_sec * 1e3 + (tv.tv_usec / 1e3));
	else if (time_code == MICROSECONDS)
		return (tv.tv_sec * 1e3 + (tv.tv_usec));
	else
		print_error("[ERROR] : Wrong input to gettime().\n", true);
	return (0);
}

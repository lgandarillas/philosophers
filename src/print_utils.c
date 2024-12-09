/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:12:57 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 19:13:01 by lgandari         ###   ########.fr       */
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
		printf(GREEN"%-6ld %d is eating\n"RESET, elapsed, philo->id);
	else if (status == SLEEPING && !simulation_finished(simulation))
		printf(BLUE"%-6ld %d is sleeping\n"RESET, elapsed, philo->id);
	else if (status == THINKING && !simulation_finished(simulation))
		printf(CIAN"%-6ld %d is thinking\n"RESET, elapsed, philo->id);
	else if (status == DYING)
		printf(RED"%-6ld %d died\n"RESET, elapsed, philo->id);
	solid_mutex(&simulation->write_mutex, UNLOCK);
}

void	print_error(const char *msg, bool _exit)
{
	if (write(2, RED, sizeof(RED) - 1) < 0)
		print_error("[ERROR] : write() failed", false);
	while (*msg != '\0')
	{
		if (write(2, msg, 1) < 0)
			print_error("[ERROR] : write() failed", false);
		msg++;
	}
	if (write(2, RESET, sizeof(RESET) - 1) < 0)
		print_error("[ERROR] : write() failed", false);
	if (_exit)
		exit(EXIT_FAILURE);
}

void	print_debug(const char *msg)
{
	if (write(1, GRAY, sizeof(GRAY) - 1) < 0)
		print_error("[ERROR] : write() failed", false);
	while (*msg != '\0')
	{
		if (write(1, msg, 1) < 0)
			print_error("[ERROR] : write() failed", false);
		msg++;
	}
	if (write(1, RESET, sizeof(RESET) - 1) < 0)
		print_error("[ERROR] : write() failed", false);
}

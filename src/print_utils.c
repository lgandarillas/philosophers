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

void	print_error(const char *msg, bool _exit)
{
	write(2, RED, sizeof(RED) - 1);
	while (*msg != '\0')
	{
		write(2, msg, 1);
		msg++;
	}
	write(2, RESET, sizeof(RESET) - 1);
	if (_exit)
		exit(EXIT_FAILURE);
}

void	print_debug(const char *msg)
{
	write(1, GRAY, sizeof(GRAY) - 1);
	while (*msg != '\0')
	{
		write(1, msg, 1);
		msg++;
	}
	write(1, RESET, sizeof(RESET) - 1);
}

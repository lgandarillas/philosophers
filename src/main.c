/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:49:30 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 12:35:03 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 5 || argc == 6)
		;
	else
	{
		print_error("Wrong parameters.\n");
		print_debug("Usage: ./philo num_philos time_die time_eat time_sleep [num_eat]\n");
		return (1);
	}
	return (0);
}

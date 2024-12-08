/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:49:30 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 13:13:22 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_simulation	simulation;

	if (argc != REQUIRED_ARGUMENTS && argc != OPTIONAL_ARGUMENTS)
	{
		print_error(INVALID_ARGUMENTS, false);
		print_debug(USAGE);
		return (42);
	}
	save_input(&simulation, argv);
	setup_simulation(&simulation);
	run_simulation(&simulation);
	clean_simulation(&simulation);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:13:59 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 19:14:02 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static const char	*clean_input(const char *str)
{
	const char	*num;
	int			len;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		print_error("[ERROR] : Invalid input (negative number).\n", true);
	if (!is_digit(*str))
		print_error("[ERROR] : Not a valid input.\n", true);
	num = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		print_error("[ERROR] : Value bigger than INT_MAX\n", true);
	return (num);
}

static long	ft_atol(const char *num_str)
{
	long	num;

	num = 0;
	num_str = clean_input(num_str);
	while (is_digit(*num_str))
	{
		num = (num * 10) + (*num_str++ - '0');
	}
	if (num > INT_MAX)
		print_error("[ERROR] : Value bigger than INT_MAX\n", true);
	return (num);
}

void	save_input(t_simulation *simulation, char **argv)
{
	simulation->num_philos = ft_atol(argv[1]);
	simulation->time_to_die = ft_atol(argv[2]) * 1e3;
	simulation->time_to_eat = ft_atol(argv[3]) * 1e3;
	simulation->time_to_sleep = ft_atol(argv[3]) * 1e3;
	if (argv[5])
		simulation->limit_meals = ft_atol(argv[5]);
	else
		simulation->limit_meals = -1;
	if (simulation->num_philos == 0)
		print_error("[ERROR] : Invalid simulation with 0 philos.\n", true);
	if (simulation->time_to_die < 6 * 1e4 \
		|| simulation->time_to_eat < 6 * 1e4 \
		|| simulation->time_to_sleep < 6 * 1e4)
		print_error("[ERROR] : Use timestamps bigger than 60ms.\n", true);
}

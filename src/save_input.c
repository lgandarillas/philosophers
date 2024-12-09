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
		print_error(INVALID_NEGATIVE, true);
	if (!is_digit(*str))
		print_error(INVALID_NOT_DIGIT, true);
	num = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		print_error(INVALID_DATATYPE, true);
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
		print_error(INVALID_DATATYPE, true);
	return (num);
}

void	save_input(t_simulation *simulation, char **argv)
{
	simulation->num_philos = ft_atol(argv[1]);
	simulation->time_to_die = ft_atol(argv[2]);
	simulation->time_to_eat = ft_atol(argv[3]);
	simulation->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		simulation->limit_meals = ft_atol(argv[5]);
	else
		simulation->limit_meals = -1;
	if (simulation->num_philos == 0)
		print_error(NO_PHILOSOPHERS, true);
	if (simulation->time_to_die < 60 \
		|| simulation->time_to_eat < 60 \
		|| simulation->time_to_sleep < 60)
		print_error(INVALID_TIMESTAMP, true);
}

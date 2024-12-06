/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:39:51 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 13:07:29 by lgandari         ###   ########.fr       */
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
	{
		print_error("[ERROR] : Value bigger than INT_MAX\n", true);
		exit(EXIT_FAILURE);
	}
	return (num);
}

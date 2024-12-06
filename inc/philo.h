/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:42:26 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 13:08:02 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>

#define RESET	"\033[0m"
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define GRAY	"\033[1;30m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA "\033[1;35m"

#define CIAN	"\033[1;36m"
#define WHITE	"\033[1;37m"


void	print_error(const char *msg, bool exit);
void	print_debug(const char *msg);


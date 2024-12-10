/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:41:55 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/08 09:45:30 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define GRAY		"\033[1;30m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CIAN		"\033[1;36m"
# define WHITE		"\033[1;37m"

# define REQUIRED_ARGUMENTS 5
# define OPTIONAL_ARGUMENTS 6

# define INVALID_ARGUMENTS	"[ERROR] : Wrong arguments.\n"
# define INVALID_NEGATIVE	"[ERROR] : Invalid input (negative number).\n"
# define INVALID_NOT_DIGIT	"[ERROR] : Invalid input (not a digit).\n"
# define INVALID_DATATYPE	"[ERROR] : Invalid input (not an int).\n"
# define INVALID_TIMESTAMP	"[ERROR] : Invalid timestamp (expected > 60ms).\n"
# define NO_PHILOSOPHERS	"[ERROR] : No philosophers to simulate.\n"
# define USAGE "Usage: ./philo num_philos time_die time_eat \
time_sleep [num_eat]\n"

# define MTX_FAIL			"[ERROR] : Mutex failed.\n"
# define MTX_FAIL_LOCK		"[ERROR] : Mutex failed (LOCK).\n"
# define MTX_FAIL_UNLOCK	"[ERROR] : Mutex failed (UNLOCK).\n"
# define MTX_FAIL_INIT		"[ERROR] : Mutex failed (INIT).\n"
# define MTX_FAIL_DESTROY	"[ERROR] : Mutex failed (DESTROY).\n"

# define PRINT_EDEADLK		"[ERROR] : EDEADLK, Deadlock detected.\n"
# define PRINT_EPERM		"[ERROR] : EPERM, Opperation not permitted.\n"
# define PRINT_ENOMEM		"[ERROR] : ENOMEM, Cannot allocate memory.\n"
# define PRINT_EBUSY		"[ERROR] : EBUSY, Resource busy.\n"
# define PRINT_EAGAIN		"[ERROR] : EAGAIN, Insufficient resources.\n"
# define PRINT_EPERM		"[ERROR] : EPERM, Opperation not permitted.\n"
# define PRINT_EINVAL		"[ERROR] : EINVAL, Invalid argument.\n"
# define PRINT_ESRCH		"[ERROR] : ESRCH, Thread ID not found.\n"
# define MALLOC_FAIL		"[ERROR] : Malloc failed.\n"
# define INVALID_THREAD_OP	"[ERROR] : Invalid thread operation.\n"
# define INVALID_GETTIME_OP	"[ERROR] : Invalid code for gettime_millis().\n"
# define GETTIME_FAIL		"[ERROR] : gettime_millis() failed.\n"

typedef enum e_threadop
{
	INIT,
	LOCK,
	UNLOCK,
	JOIN,
	DETACH,
	CREATE,
	DESTROY,
}	t_threadop;

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKING_FIRST_FORK,
	TAKING_SECOND_FORK,
	DYING,
}	t_philo_status;

#endif

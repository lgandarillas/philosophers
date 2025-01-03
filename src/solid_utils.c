/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:14:48 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 19:14:53 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	print_mutex_error(int status, t_threadop threadop)
{
	const char	*error_msg;

	if (status == 0)
		return ;
	error_msg = NULL;
	if (status == EINVAL)
	{
		if (threadop == LOCK || threadop == UNLOCK)
			error_msg = MTX_FAIL_LOCK;
		else if (threadop == INIT)
			error_msg = MTX_FAIL_INIT;
		else if (threadop == DESTROY)
			error_msg = MTX_FAIL_DESTROY;
	}
	else if (status == EDEADLK)
		error_msg = PRINT_EDEADLK;
	else if (status == EPERM)
		error_msg = PRINT_EPERM;
	else
		error_msg = MTX_FAIL;
	print_error(error_msg, true);
}

static void	print_thread_error(int status)
{
	if (status == EAGAIN)
		print_error(PRINT_EAGAIN, true);
	else if (status == EPERM)
		print_error(PRINT_EPERM, true);
	else if (status == EINVAL)
		print_error(PRINT_EINVAL, true);
	else if (status == ESRCH)
		print_error(PRINT_ESRCH, true);
	else if (status == EDEADLK)
		print_error(PRINT_EDEADLK, true);
}

void	*solid_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		print_error(MALLOC_FAIL, true);
	return (ret);
}

void	solid_mutex(t_mtx *mutex, t_threadop threadop)
{
	int	status;

	status = 0;
	if (threadop == LOCK)
		status = pthread_mutex_lock(mutex);
	else if (threadop == UNLOCK)
		status = pthread_mutex_unlock(mutex);
	else if (threadop == INIT)
		status = pthread_mutex_init(mutex, NULL);
	else if (threadop == DESTROY)
		status = pthread_mutex_destroy(mutex);
	else
		print_error(INVALID_THREAD_OP, true);
	if (status != 0)
		print_mutex_error(status, threadop);
}

void	solid_thread(pthread_t *thread, void *(*thread_func)(void *), \
	void *arg, t_threadop threadop)
{
	int	status;

	status = 0;
	if (threadop == CREATE)
		status = pthread_create(thread, NULL, thread_func, arg);
	else if (threadop == JOIN)
		status = pthread_join(*thread, NULL);
	else if (threadop == DETACH)
		status = pthread_detach(*thread);
	else
		print_error(INVALID_THREAD_OP, true);
	if (status != 0)
		print_thread_error(status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:11:22 by lgandari          #+#    #+#             */
/*   Updated: 2024/12/06 15:13:07 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*solid_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		print_error("[ERROR] : Malloc failed.\n", true);
	return (ret);
}

static void	print_mutex_error(int status, t_threadop threadop)
{
	if (status == EINVAL)
	{
		if (threadop == LOCK || threadop == UNLOCK)
			print_error("[ERROR] : Mutex error.\n", true);
		else if (threadop == INIT)
			print_error("[ERROR] : Mutex initialization failed.\n", true);
		else if (threadop == DESTROY)
			print_error("[ERROR] : Mutex destruction failed.\n", true);
	}
	else if (status == EDEADLK)
		print_error("[ERROR] : EDEADLK, Deadlock detected.\n", true);
	else if (status == EPERM)
		print_error("[ERROR] : EPERM, Opperation not permitted.\n", true);
	else if (status == ENOMEM)
		print_error("[ERROR] : ENOMEM, Cannot allocate memory.\n", true);
	else if (status == EBUSY)
		print_error("[ERROR] : EBUSY, Resource busy.\n", true);
	else
		print_error("[ERROR] : Unknown mutex error.\n", true);
}

void	solid_mutex_handle(t_mtx *mutex, t_threadop threadop)
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
		print_error("[ERROR] : Wrong threadop for mutex handle.\n", true);
	if (status != 0)
		print_mutex_error(status, threadop);
}

static void	print_thread_error(int status, t_threadop threadop)
{
	if (status == EAGAIN)
		print_error("[ERROR] : EAGAIN, Insufficient resources.\n", true);
	else if (status == EPERM)
		print_error("[ERROR] : EPERM, Permission denied.\n", true);
	else if (status == EINVAL)
	{
		if (threadop == CREATE)
			print_error("[ERROR] : EINVAL, Invalid thread attributes.\n", true);
		else if (threadop == JOIN || threadop == DETACH)
			print_error("[ERROR] : EINVAL, Thread not joinable.\n", true);
	}
	else if (status == ESRCH)
		print_error("[ERROR] : ESRCH, Thread ID not found.\n", true);
	else if (status == EDEADLK)
		print_error("[ERROR] : EDEADLK, Deadlock detected.\n", true);
}

void	solid_thread_handle(pthread_t *thread, void *(*thread_func)(void *), \
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
		print_error("[ERROR] : Wrong threadop for thread handle.\n", true);
	if (status != 0)
		print_thread_error(status, threadop);
}

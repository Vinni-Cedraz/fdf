/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threaded_workers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/28 15:47:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include <pthread.h>

static t_task			get_this_wrkrs_task(t_task action, int thread_number);
static void				*array_iter(void *action);
static int				get_start_idx(int thread_number);
static int				get_end_idx(int thread_number);

void	multi_threaded_workers(t_task task)
{
	pthread_t	workers[NUM_THREADS];
	t_task		this_worker_task[NUM_THREADS];
	int			idx;

	idx = 0;
	while (idx < NUM_THREADS)
	{
		this_worker_task[idx] = get_this_wrkrs_task(task, idx);
		pthread_create(
			&workers[idx],
			NULL,
			&array_iter,
			((void *)&this_worker_task[idx]));
		idx++;
	}
	idx = -1;
	while (++idx < NUM_THREADS)
		pthread_join(workers[idx], NULL);
}

static inline int	get_start_idx(int thread_number)
{
	uint	map_size;
	int		remainder;

	if (1 == thread_number)
		return (0);
	map_size = get_data()->map->size;
	remainder = map_size % NUM_THREADS;
	return ((map_size / NUM_THREADS) * (thread_number - 1) + remainder);
}

static inline int	get_end_idx(int thread_number)
{
	uint	map_size;
	short	remainder;

	map_size = get_data()->map->size;
	remainder = map_size % NUM_THREADS;
	return ((map_size / NUM_THREADS) * thread_number + remainder);
}

static inline t_task	get_this_wrkrs_task(t_task task, int idx)
{
	int	start_idx;
	int	end_idx;

	if (paint_it_black == task.action)
	{
		start_idx = get_img_start_idx(idx + 1);
		end_idx = get_img_end_idx(idx + 1);
	}
	else
	{
		start_idx = get_start_idx(idx + 1);
		end_idx = get_end_idx(idx + 1);
	}
	return ((t_task){
		.action = task.action,
		.rot = task.rot,
		.start_idx = start_idx,
		.end_idx = end_idx});
}

static void	*array_iter(void *task)
{
	t_worker_task	this_task;
	t_point			***arr;

	arr = get_data()->map->arr;
	this_task = *((t_worker_task *)(task));
	this_task.width = get_data()->map->width;
	if (this_task.action == paint_it_black)
		this_task.width = get_data()->img->width;
	while (this_task.start_idx < this_task.end_idx)
	{
		this_task.row = this_task.start_idx / this_task.width;
		this_task.col = this_task.start_idx % this_task.width;
		this_task.p = arr[this_task.row][this_task.col];
		this_task.action(&this_task);
		this_task.start_idx++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threaded_iter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:12:37 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/27 22:30:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include <pthread.h>

static t_actidx			get_actidx(t_actidx action, int thread_number);
static void				*array_iter(void *action);
static int				get_start_idx(int thread_number);
static int				get_end_idx(int thread_number);

void	multi_threaded_iter(t_action_and_idx action)
{
	int					thread_nb;
	pthread_t			threads[NUM_THREADS];
	t_action_and_idx	this_action_and_idx[NUM_THREADS];

	thread_nb = 0;
	while (thread_nb < NUM_THREADS)
	{
		this_action_and_idx[thread_nb] = get_actidx(action, thread_nb);
		pthread_create(&threads[thread_nb], NULL, &array_iter,
			((void *)&this_action_and_idx[thread_nb]));
		thread_nb++;
	}
	thread_nb = -1;
	while (++thread_nb < NUM_THREADS)
		pthread_join(threads[thread_nb], NULL);
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

static inline t_actidx	get_actidx(t_actidx action_and_idx, int thread_number)
{
	int	start_idx;
	int	end_idx;

	if (paint_it_black == action_and_idx.action)
	{
		start_idx = get_img_start_idx(thread_number + 1);
		end_idx = get_img_end_idx(thread_number + 1);
	}
	else
	{
		start_idx = get_start_idx(thread_number + 1);
		end_idx = get_end_idx(thread_number + 1);
	}
	return ((t_action_and_idx){.action = action_and_idx.action,
		.start_idx = start_idx, .end_idx = end_idx});
}

static void	*array_iter(void *action_fptr)
{
	t_arrpoints_iter	iter;
	t_action_and_idx	actidx;

	actidx = *((t_action_and_idx *)(action_fptr));
	iter = (t_arrpoints_iter){
		.start_idx = actidx.start_idx,
		.end_idx = actidx.end_idx,
		.width = get_data()->map->width,
		.rot = (t_matrix){0},
	};
	if (actidx.action == paint_it_black)
		iter.width = get_data()->img->width;
	else if (actidx.action == transform_a_point)
		iter.rot = actidx.rot;
	while (iter.start_idx < iter.end_idx)
	{
		iter.row = iter.start_idx / iter.width;
		iter.col = iter.start_idx % iter.width;
		iter.p = &get_data()->map->arr[iter.col][iter.row];
		actidx.action(&iter);
		iter.start_idx++;
	}
	return (NULL);
}

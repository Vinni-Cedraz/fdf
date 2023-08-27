/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_threaded_iter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:12:37 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/27 19:16:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include <pthread.h>

static t_shpidx		get_t_shape_and_idx(t_shpidx shape, int thread_number);
static void			*arrpoints_iter(void *shape_fptr);
static int			get_start_idx(int thread_number);
static int			get_end_idx(int thread_number);

void	spawn_threads(t_shape_and_idx shape)
{
	int				thread_nb;
	pthread_t		threads[NUM_THREADS];
	t_shape_and_idx	this_shape_and_idx[NUM_THREADS];

	thread_nb = 0;
	while (thread_nb < NUM_THREADS)
	{
		this_shape_and_idx[thread_nb] = get_t_shape_and_idx(shape, thread_nb);
		pthread_create(
			&threads[thread_nb],
			NULL,
			&arrpoints_iter,
			((void *)&this_shape_and_idx[thread_nb]));
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

static inline t_shpidx	get_t_shape_and_idx(t_shpidx shape, int thread_number)
{
	const int	start_idx = get_start_idx(thread_number + 1);
	const int	end_idx = get_end_idx(thread_number + 1);

	return ((t_shape_and_idx){
		.fptr = shape.fptr,
		.start_idx = start_idx,
		.end_idx = end_idx
	});
}

static void	*arrpoints_iter(void *shape_fptr)
{
	t_arrpoints_iter	iter;

	iter = (t_arrpoints_iter){
		.end_idx = get_iter_end_idx(shape_fptr),
		.start_idx = get_iter_start_idx(shape_fptr),
		.map_width = get_data()->map->width,
		.row = 0,
		.col = 0,
	};
	while (iter.start_idx < iter.end_idx)
	{
		iter.row = iter.start_idx / iter.map_width;
		iter.col = iter.start_idx % iter.map_width;
		((t_shape_and_idx *)(shape_fptr))->fptr(iter.row, iter.col);
		iter.start_idx++;
	}
	return (NULL);
}

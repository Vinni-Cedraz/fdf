/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreaded_iter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:12:37 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/27 19:16:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include <pthread.h>

typedef void	*(*t_shape)(t_point *, int row, int col);
void			*square(t_point *p, int row, int col);

typedef struct s_shape_and_idx
{
	t_shape		fptr;
	int			start_idx;
	int			end_idx;
}				t_shape_and_idx;

void			spawn_threads(t_shape_and_idx shape);
void			*arrpoints_iter(void *shape_fptr);

// these ones will be called by the button event
void	render_lines_square(void)
{
	spawn_threads((t_shape_and_idx){.fptr = square});
}

int	get_start_idx(int thread_number)
{
	uint	map_size;
	int		remainder;

	if (1 == thread_number)
		return (0);
	map_size = get_data()->map->size;
	remainder = map_size % NUM_THREADS;
	return ((map_size / NUM_THREADS) * (thread_number - 1) + remainder);
}

int	get_end_idx(int thread_number)
{
	uint	map_size;
	short	remainder;

	map_size = get_data()->map->size;
	remainder = map_size % NUM_THREADS; 
	return ((map_size / NUM_THREADS) * thread_number + remainder);
}

t_shape_and_idx	get_t_shape_and_idx(t_shape_and_idx shape, int thread_number)
{
	const int	start_idx = get_start_idx(thread_number + 1);
	const int	end_idx = get_end_idx(thread_number + 1);

	return ((t_shape_and_idx){
		.fptr = shape.fptr,
		.start_idx = start_idx,
		.end_idx = end_idx
	});
}

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

void	*arrpoints_iter(void *shape_fptr)
{
	t_point	**arr;
	t_map	*map;
	int		end_idx;
	int		start_idx;
	int		row;
	int		col;

	map = get_data()->map;
	arr = map->arr;
	end_idx = ((t_shape_and_idx *)(shape_fptr))->end_idx;
	start_idx = ((t_shape_and_idx *)(shape_fptr))->start_idx;
	while (start_idx < end_idx)
	{
		row = start_idx / (int)map->width;
		col = start_idx % (int)map->width;
		((t_shape_and_idx *)(shape_fptr))->fptr(&arr[row][col], row, col);
		start_idx++;
	}
	return (NULL);
}

// the following functions are the grid methods
void	*square(t_point *p, int row, int col)
{
	t_data	*d;

	d = get_data();
	if (col + 1 < d->map->width)
		render_line_bonus(*p, d->map->arr[row][col + 1]);
	if (row + 1 < d->map->height)
		render_line_bonus(*p, d->map->arr[row + 1][col]);
	return (NULL);
}

void	cross(void)
{
	int		i;
	int		j;
	t_point	p1;
	t_data	*d;

	i = -1;
	j = -1;
	d = get_data();
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			if (j < d->map->width - 1 && i < d->map->height - 1)
			{
				p1 = d->map->arr[i][j];
				render_line_bonus(p1, d->map->arr[i + 1][j + 1]);
				p1 = d->map->arr[i + 1][j];
				render_line_bonus(p1, d->map->arr[i][j + 1]);
			}
		}
	}
}

void	pentagram(void)
{
	int		i;
	int		j;
	t_point	p1;
	t_data	*d;

	i = -1;
	j = -1;
	d = get_data();
	while (++i < d->map->height - 3)
	{
		j = -1;
		while (++j < d->map->width - 3)
		{
			p1 = d->map->arr[i + 1][j];
			render_line_bonus(p1, d->map->arr[i + 1][j + 2]);
			render_line_bonus(p1, d->map->arr[i + 2][j + 2]);
			p1 = d->map->arr[i + 2][j];
			render_line_bonus(p1, d->map->arr[i][j + 1]);
			render_line_bonus(p1, d->map->arr[i + 1][j + 2]);
			p1 = d->map->arr[i][j + 1];
			render_line_bonus(p1, d->map->arr[i + 2][j + 2]);
		}
	}
}

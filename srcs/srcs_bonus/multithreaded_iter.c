/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreaded_iter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:37:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/25 19:24:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include <pthread.h>

typedef void	*(*t_shape)(t_point *, int row, int col);
void			*square(t_point *p, int row, int col);

typedef struct s_shape_and_idx
{
	t_shape		fptr;
	int			idx;
}				t_shape_and_idx;

void			spawn_threads(t_shape_and_idx shape);

// these ones will be called by the button event
void	render_lines_square(void)
{
	spawn_threads((t_shape_and_idx){.fptr = square, .idx = 0});
}

void	*arrpoints_iter(void *shape_fptr)
{
	t_point	**arr;
	t_map	*map;
	int		idx;
	int		row;
	int		col;

	idx = ((t_shape_and_idx)(shape_fptr)).idx;
	map = get_data()->map;
	arr = map->arr;
	while (idx++ < (int)map->size)
	{
		row = idx / (int)map->width;
		col = idx % (int)map->width;
		((t_shape_and_idx)&(shape_fptr)).shape(&arr[row][col], row, col);
		idx++;
	}
	return (NULL);
}

// this one here will create the threads and call them with two function pointer
// arguments: 1-> arrpoints_iter 2-> the argument it received when it was called
// by render_lines_<shape>
void	spawn_threads(t_shape_and_idx shape)
{
	int			i;
	pthread_t	threads[8];

	i = -1;
	while (++i < 8)
	{
		pthread_create(&threads[i], NULL, arrpoints_iter,
				(void *)&(t_shape_and_idx){.fptr = shape, .idx = get_idx(i)});
	}
	i = -1;
	while (++i < 8)
		pthread_join(threads[i], NULL);
}

// the following functions are the grid methods
void	*square(t_point *p, int row, int col)
{
	t_data	*d;

	d = get_data();
	if (col < d->map->width)
		render_line_bonus(*p, d->map->arr[row - 1][col]);
	if (row < d->map->height)
		render_line_bonus(*p, d->map->arr[row][col - 1]);
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

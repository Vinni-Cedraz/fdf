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

// int i goes from 0 to 7 and represents the number of the thread being created
int	get_start_idx(int i)
{
	size_t	map_size;

	map_size = get_data()->map->size;
	return ((map_size / 8) * i);
}

int	get_end_idx(int i)
{
	size_t	map_size;

	map_size = get_data()->map->size;
	return (2 * (map_size / 8) * i);
}

t_shape_and_idx	getshape(t_shape_and_idx shape, int i)
{
	return ((t_shape_and_idx){.fptr = shape.fptr, .start_idx = get_start_idx(i),
		.end_idx = get_end_idx(i)});
}

// this one here will create the threads and call them with two function pointer
// arguments: 1-> arrpoints_iter 2-> the argument it received when it was called
// by render_lines_<shape>
void	spawn_threads(t_shape_and_idx shape)
{
	int				i;
	pthread_t		threads[8];
	t_shape_and_idx	this_shape[8];

	i = -1;
	while (++i < 8)
	{
		this_shape[i] = getshape(shape, i);
		pthread_create(&threads[i], NULL, arrpoints_iter, ((void *)&shape));
	}
	i = -1;
	while (++i < 8)
		pthread_join(threads[i], NULL);
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
	while (start_idx++ < end_idx)
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
	if (col < d->map->width)
		render_line_bonus(*p, d->map->arr[row][col + 1]);
	if (row < d->map->height)
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

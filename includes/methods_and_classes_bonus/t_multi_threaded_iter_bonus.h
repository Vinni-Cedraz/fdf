/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_multi_threaded_iter_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:05:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/27 20:11:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MULTI_THREADED_ITER_BONUS_H
# define T_MULTI_THREADED_ITER_BONUS_H

# include "t_map_bonus.h"
# define NUM_THREADS 8

# include "fdf_t_data_bonus.h"
# include <sys/types.h>

typedef void			*(*t_shape)(int row, int col);

typedef struct s_iter
{
	int					end_idx;
	int					start_idx;
	uint				map_width;
	int					row;
	int					col;
}						t_arrpoints_iter;

typedef struct s_shape_and_idx
{
	t_shape				fptr;
	int					start_idx;
	int					end_idx;
}						t_shape_and_idx;

typedef t_shape_and_idx	t_shpidx;

static void				*square(int r, int c) __attribute__((unused));
static int				get_iter_end_idx(void *f) __attribute__((unused));
static int				get_iter_start_idx(void *f) __attribute__((unused));

static inline void	*square(int row, int col)
{
	t_data	*d;
	t_point	*p;

	d = get_data();
	p = &d->map->arr[row][col];
	if (col + 1 < d->map->width)
		render_line_bonus(*p, d->map->arr[row][col + 1]);
	if (row + 1 < d->map->height)
		render_line_bonus(*p, d->map->arr[row + 1][col]);
	return (NULL);
}

static inline int	get_iter_end_idx(void *shape_fptr)
{
	return (((t_shape_and_idx *)(shape_fptr))->end_idx);
}

static inline int	get_iter_start_idx(void *shape_fptr)
{
	return (((t_shape_and_idx *)(shape_fptr))->start_idx);
}

#endif

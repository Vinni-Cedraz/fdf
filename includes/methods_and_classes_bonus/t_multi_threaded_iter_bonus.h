/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_multi_threaded_iter_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:05:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/27 22:26:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MULTI_THREADED_ITER_BONUS_H
# define T_MULTI_THREADED_ITER_BONUS_H

# include "t_map_bonus.h"
# include "t_rotation_matrices_bonus.h"
# define NUM_THREADS 8

# include "fdf_t_data_bonus.h"
# include <sys/types.h>

typedef struct s_iter
{
	int						end_idx;
	int						start_idx;
	uint					width;
	int						row;
	int						col;
	t_point					*p;
	t_matrix				rot;
}							t_arrpoints_iter;

typedef void				*(*t_action)(t_arrpoints_iter *iter);

typedef struct s_shpidx
{
	t_action				action;
	t_matrix				rot;
	int						start_idx;
	int						end_idx;
}							t_action_and_idx;

typedef t_action_and_idx	t_actidx;
typedef t_arrpoints_iter	t_iter;

static void					*render_square(t_iter *i) __attribute__((unused));
static void					*render_cross(t_iter *i) __attribute__((unused));
static int					get_iter_end_idx(void *f) __attribute__((unused));
static int					get_iter_start_idx(void *f) __attribute__((unused));
static void					*render_pentagram(t_iter *i)__attribute__((unused));

static inline void	*render_square(t_arrpoints_iter *iter)
{
	t_map	*map;
	t_point	*p1;
	int		row;
	int		col;

	row = iter->row;
	col = iter->col;
	map = get_data()->map;
	p1 = &map->arr[row][col];
	if (col + 1 < map->width)
		render_line_bonus(p1, &map->arr[row][col + 1]);
	if (row + 1 < map->height)
		render_line_bonus(p1, &map->arr[row + 1][col]);
	return (NULL);
}

static inline void	*render_cross(t_iter *iter)
{
	t_point	*p1;
	t_map	*map;
	int		row;
	int		col;

	row = iter->row;
	col	= iter->col;
	map = get_data()->map;
	if (col < map->width - 1 && row < map->height - 1)
	{
		p1 = &map->arr[row][col];
		render_line_bonus(p1, &map->arr[row + 1][col + 1]);
		p1 = &map->arr[row + 1][col];
		render_line_bonus(p1, &map->arr[row][col + 1]);
	}
	return (NULL);
}

static inline void	*render_pentagram(t_iter *iter)
{
	t_point	*p1;
	t_map	*map;
	int		row;
	int		col;

	row = iter->row;
	col = iter->col;
	map = get_data()->map;
	if (row < map->height - 3 && col < map->width - 3)
	{
		p1 = &map->arr[row + 1][col];
		render_line_bonus(p1, &map->arr[row + 1][col + 2]);
		render_line_bonus(p1, &map->arr[row + 2][col + 2]);
		p1 = &map->arr[row + 2][col];
		render_line_bonus(p1, &map->arr[row][col + 1]);
		render_line_bonus(p1, &map->arr[row + 1][col + 2]);
		p1 = &map->arr[row][col + 1];
		render_line_bonus(p1, &map->arr[row + 2][col + 2]);
	}
	return (NULL);
}

#endif

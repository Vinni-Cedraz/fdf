/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_includes_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:20:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/24 14:27:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INCLUDES_BONUS_H
# define FDF_INCLUDES_BONUS_H

# include "fdf_defines.h"
# include "fdf_keycodes.h"
# include "fdf_prototypes_bonus.h"
# include "fdf_t_data_bonus.h"
# include "linked_list_tools.h"
# include "methods_and_classes_bonus.h"
# include "printf_libft_includes.h"
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <string.h>

// debugging function
void					print_state(void);

// to be included on t_multithreaded_iter in the future:
# define NUM_THREADS 8
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
// alias:
typedef t_shape_and_idx	t_shpidx;
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
static inline int			get_iter_end_idx(void *shape_fptr)
{
	return (((t_shape_and_idx *)(shape_fptr))->end_idx);
}
static inline int			get_iter_start_idx(void *shape_fptr)
{
	return (((t_shape_and_idx *)(shape_fptr))->start_idx);
}
void					spawn_threads(t_shape_and_idx shape);

#endif

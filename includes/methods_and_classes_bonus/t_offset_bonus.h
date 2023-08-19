/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_offset_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 22:04:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OFFSET_BONUS_H
# define T_OFFSET_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "fdf_t_data_bonus.h"
# include "t_map_bonus.h"
# include "t_scale_bonus.h"

static void			up(t_data *d) __attribute__((unused));
static void			down(t_data *d) __attribute__((unused));
static void			left(t_data *d) __attribute__((unused));
static void			right(t_data *d) __attribute__((unused));
static void			calculate_initial_offset(t_data *d) __attribute__((unused));

typedef struct s_offset
{
	double			move_x;
	double			move_y;
	double			initial_move_x;
	double			initial_move_y;
	int				neutral_zoom;
	t_func_ptr		set_initial_offset;
	t_func_ptr		move[4];
}					t_offset;

static inline void	up(t_data *d)
{
	d->offset->move_y -= 25;
}

static inline void	down(t_data *d)
{
	d->offset->move_y += 25;
}

static inline void	left(t_data *d)
{
	d->offset->move_x -= 25;
}

static inline void	right(t_data *d)
{
	d->offset->move_x += 25;
}

static inline void	calculate_initial_offset(t_data *d)
{
	double	x_offset;
	double	y_offset;
	t_scale	sca;

	sca = *d->scale;
	x_offset = (sca.win_wdth - d->map->target_width + sca.menu_width) / 2;
	y_offset = (sca.win_hght - d->map->target_height) / 2;
	d->offset->move_x = x_offset;
	d->offset->initial_move_x = x_offset;
	d->offset->move_y = y_offset;
	d->offset->initial_move_y = x_offset;
}

#endif

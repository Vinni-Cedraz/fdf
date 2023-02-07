/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_offset_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:27:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 12:52:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OFFSET_BONUS_H
# define T_OFFSET_BONUS_H

# include "fdf_t_data_bonus.h"

static void			up(t_data *d) __attribute__((unused));
static void			down(t_data *d) __attribute__((unused));
static void			left(t_data *d) __attribute__((unused));
static void			right(t_data *d) __attribute__((unused));

typedef struct s_offset
{
	double			scale;
	double			scale_z;
	double			move_x;
	double			move_y;
	int				neutral_zoom;
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:38:53 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 12:51:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COLOR_BONUS_H
# define T_COLOR_BONUS_H

# include "fdf_t_data_bonus.h"

static void			create_hsl_map(t_data *data) __attribute__((unused));

typedef struct s_hsl
{
	double			h;
	double			s;
	double			l;
}					t_hsl;

typedef struct s_rgb
{
	double			r;
	double			g;
	double			b;
}					t_rgb;

typedef struct s_color
{
	double			base;
	double			shaded;
	double			tinted;
	t_rgb			rgb_map[6];
	t_hsl			hsl_map[6];
	t_hsl			hsl;
	t_func_ptr		create_hsl_map;
}					t_color;

static inline void	create_hsl_map(t_data *d)
{
	d->c->hsl_map[0] = (t_hsl){0.0, 1.0, 1.0};
	d->c->hsl_map[1] = (t_hsl){60.0, 1.0, 0.5};
	d->c->hsl_map[2] = (t_hsl){120.0, 1.0, 0.75};
	d->c->hsl_map[3] = (t_hsl){180.0, 1.0, 0.5};
	d->c->hsl_map[4] = (t_hsl){240.0, 1.0, 0.5};
	d->c->hsl_map[5] = (t_hsl){300.0, 1.0, 1.0};
}

#endif

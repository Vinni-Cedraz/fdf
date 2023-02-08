/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:38:53 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 23:45:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COLOR_BONUS_H
# define T_COLOR_BONUS_H

# include "fdf_t_data_bonus.h"
# include "t_map_bonus.h"

typedef struct s_hsl	t_hsl;

static void				colorize_points(t_data *d) __attribute__((unused));
static void				create_hsl_map(t_hsl *hsl_map) __attribute__((unused));

typedef struct s_hsl
{
	double				h;
	double				s;
	double				l;
}						t_hsl;

typedef struct s_rgb
{
	double				r;
	double				g;
	double				b;
}						t_rgb;

typedef struct s_color
{
	double				base;
	double				shaded;
	double				tinted;
	t_rgb				rgb_map[6];
	t_hsl				hsl_map[6];
	t_hsl				hsl;
	t_func_ptr			create_hsl_map;
}						t_color;

static inline void	create_hsl_map(t_hsl *hsl_map)
{
	hsl_map[0] = (t_hsl){0.0, 1.0, 1.0};
	hsl_map[1] = (t_hsl){60.0, 1.0, 0.5};
	hsl_map[2] = (t_hsl){120.0, 1.0, 0.75};
	hsl_map[3] = (t_hsl){180.0, 1.0, 0.5};
	hsl_map[4] = (t_hsl){240.0, 1.0, 0.5};
	hsl_map[5] = (t_hsl){300.0, 1.0, 1.0};
}

static inline void	colorize_points(t_data *d)
{
	t_n	*tmp;

	create_hsl_map(d->c->hsl_map);
	tmp = d->map->pts;
	while (tmp)
	{
		compute_color_gradient_bonus(&tmp->point, d);
		tmp = tmp->next;
	}
}

#endif

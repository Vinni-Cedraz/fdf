/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color_gradient_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:29:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 12:21:28 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static long			rgb_to_int(double r, double g, double b);
static long			hsl_to_rgb(t_color *c);
static int			get_color_wheel_sector_of_hue(double h);
static void			compute_color_gradient_bonus(t_point *p, t_data *d);

void	colorize_points_bonus(t_data *d)
{
	t_n	*tmp;

	d->color->create_hsl_map(d->color->hsl_map);
	tmp = d->map->pts;
	while (tmp)
	{
		compute_color_gradient_bonus(&tmp->point, d);
		tmp = tmp->next;
	}
}

static inline void	compute_color_gradient_bonus(t_point *p, t_data *d)
{
	double	normalized_z;
	int		index;
	double	interpolation;
	t_hsl	hsl_low;
	t_hsl	hsl_high;

	if (p->color != CYAN || d->map->is_plateau)
		return ;
	normalized_z = (p->z - d->map->min_z) / (d->map->max_z - d->map->min_z);
	index = (int)(normalized_z * 5);
	if (index > 5 || index < 0)
		index = 5;
	interpolation = normalized_z * 5 - index;
	hsl_low = d->color->hsl_map[index];
	hsl_high = d->color->hsl_map[index + 1];
	d->color->hsl.h = hsl_low.h + (hsl_high.h - hsl_low.h) * interpolation;
	d->color->hsl.s = hsl_low.s + (hsl_high.s - hsl_low.s) * interpolation;
	d->color->hsl.l = hsl_low.l + (hsl_high.l - hsl_low.l) * interpolation;
	p->color = hsl_to_rgb(d->color);
}

static inline long	hsl_to_rgb(t_color *c)
{
	int		i;
	double	fractional;
	double	p_color;

	i = get_color_wheel_sector_of_hue(c->hsl.h);
	fractional = (c->hsl.h / 60 - i);
	c->base = c->hsl.l * (1 - c->hsl.s);
	c->shaded = c->hsl.l * (1 - c->hsl.s * fractional);
	c->tinted = c->hsl.l * (1 - c->hsl.s * (1 - fractional));
	c->create_rgb_map(c);
	p_color = rgb_to_int(c->rgb_map[i].r, c->rgb_map[i].g, c->rgb_map[i].b);
	return (p_color);
}

static inline int	get_color_wheel_sector_of_hue(double h)
{
	return ((int)floor(h / 60) % 6);
}

static inline long	rgb_to_int(double r, double g, double b)
{
	long	red;
	long	green;
	long	blue;

	red = (long)(r * 255);
	green = (long)(g * 255);
	blue = (long)(b * 255);
	return ((red << 16) | (green << 8) | blue);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:29:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/22 15:54:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static long			rgb_to_int(double r, double g, double b);
static long			hsl_to_rgb(t_color *c);
static int			get_color_wheel_sector_of_hue(double h);
static void			compute_color_gradient(t_point *p);

void	colorize_points_bonus(void)
{
	t_data	*d;

	d = get_data();
	d->color->create_hsl_map(d->color->hsl_map);
	ft_lstpoint_iter(d->map->pts, &compute_color_gradient);
}

static inline void	compute_color_gradient(t_point *p)
{
	t_compute_color	c;
	t_data			*d;

	d = get_data();
	if (p->color != CYAN || d->map->is_plateau)
		return ;
	c.normalized_z = (p->z - d->map->min_z) / (d->map->max_z - d->map->min_z);
	c.index = (int)(c.normalized_z * 5);
	if (c.index > 5 || c.index < 0)
		c.index = 5;
	c.interpol = c.normalized_z * 5 - c.index;
	c.hsl_low = d->color->hsl_map[c.index];
	c.hsl_high = d->color->hsl_map[c.index + 1];
	d->color->hsl.h = c.hsl_low.h + (c.hsl_high.h - c.hsl_low.h) * c.interpol;
	d->color->hsl.s = c.hsl_low.s + (c.hsl_high.s - c.hsl_low.s) * c.interpol;
	d->color->hsl.l = c.hsl_low.l + (c.hsl_high.l - c.hsl_low.l) * c.interpol;
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

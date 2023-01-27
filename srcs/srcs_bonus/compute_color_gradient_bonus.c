/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color_gradient_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:29:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 22:56:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static long			rgb_to_int(double r, double g, double b);
static long			hsl_to_rgb(t_compute_color *c);
static int			get_color_wheel_sector_of_hue(double h);
static void			initialize_rgb_map(t_compute_color *c);

void	compute_color_gradient_bonus(t_point *p, t_data *d)
{
	double	range;
	double	normalized_z;

	if (p->color != CYAN || d->map->is_plateau)
		return ;
	range = d->map->max_z - d->map->min_z;
	normalized_z = (p->z - d->map->min_z) / range;
	d->c.saturation = 1;
	d->c.light = 1;
	if (normalized_z <= d->map->min_z)
		d->c.hue = 240;
	else if (normalized_z >= d->map->max_z)
		d->c.hue = 300;
	else
	{
		d->c.hue = normalized_z * 60 + 240;
		d->c.light = 0.5 + normalized_z / 2;
	}
	p->color = hsl_to_rgb(&d->c);
}

static inline long	hsl_to_rgb(t_compute_color *c)
{
	int		i;
	double	fractional;
	double	p_color;

	i = get_color_wheel_sector_of_hue(c->hue);
	fractional = (c->hue / 60 - i);
	c->base = c->light * (1 - c->saturation);
	c->shaded = c->light * (1 - c->saturation * fractional);
	c->tinted = c->light * (1 - c->saturation * (1 - fractional));
	initialize_rgb_map(c);
	p_color = rgb_to_int(c->rgb_map[i].r, c->rgb_map[i].g, c->rgb_map[i].b);
	return (p_color);
}

static inline void	initialize_rgb_map(t_compute_color *c)
{
	c->rgb_map[0] = (t_rgb){.r = c->light, .g = c->tinted, .b = c->base};
	c->rgb_map[1] = (t_rgb){.r = c->shaded, .g = c->light, .b = c->base};
	c->rgb_map[2] = (t_rgb){.r = c->base, .g = c->light, .b = c->tinted};
	c->rgb_map[3] = (t_rgb){.r = c->base, .g = c->shaded, .b = c->light};
	c->rgb_map[4] = (t_rgb){.r = c->tinted, .g = c->base, .b = c->light};
	c->rgb_map[5] = (t_rgb){.r = c->light, .g = c->base, .b = c->shaded};
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color_gradient_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:29:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 12:03:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static long			rgb_to_int(double r, double g, double b);
static long			hsv_to_rgb(t_d h, t_d s, t_d v, t_data *d);

void	compute_color_gradient_bonus(t_point *p, t_data *d)
{
	double	range;
	double	normalized_z;
	double	hue;
	double	saturation;
	double	value;

	range = d->map->max_z - d->map->min_z;
	normalized_z = (p->z - d->map->min_z) / range;
	saturation = 1;
	value = 1;
	if (normalized_z <= d->map->min_z)
		hue = 240;
	else if (normalized_z >= d->map->max_z)
		hue = 300;
	else
	{
		hue = normalized_z * 60 + 240;
		value = 0.5 + normalized_z / 2;
	}
	p->color = hsv_to_rgb(hue, saturation, value, d);
}

static inline long	hsv_to_rgb(t_d h, t_d s, t_d v, t_data *d)
{
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	i = (int)floor(h / 60) % 6;
	f = h / 60 - i;
	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));
	d->rgb_map[0] = (t_rgb){.r = v, .g = t, .b = p};
	d->rgb_map[1] = (t_rgb){.r = q, .g = v, .b = p};
	d->rgb_map[2] = (t_rgb){.r = p, .g = v, .b = t};
	d->rgb_map[3] = (t_rgb){.r = p, .g = q, .b = v};
	d->rgb_map[4] = (t_rgb){.r = t, .g = p, .b = v};
	d->rgb_map[5] = (t_rgb){.r = v, .g = p, .b = q};
	return (rgb_to_int(d->rgb_map[i].r, d->rgb_map[i].g, d->rgb_map[i].b));
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

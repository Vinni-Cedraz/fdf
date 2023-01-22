/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color_gradient_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:29:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 14:09:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static long			rgb_to_int(double r, double g, double b);
static long			hsl_to_rgb(t_d h, t_d s, t_d v, t_data *d);
static int			get_color_wheel_sector_of_hue(double h);

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
	p->color = hsl_to_rgb(hue, saturation, value, d);
}

static inline long	hsl_to_rgb(t_d hue, t_d saturation, t_d light, t_data *d)
{
	int		i;
	double	fractional;
	double	base;
	double	shaded;
	double	tinted;

	i = get_color_wheel_sector_of_hue(hue);
	fractional = (hue / 60 - i);
	base = light * (1 - saturation);
	shaded = light * (1 - saturation * fractional);
	tinted = light * (1 - saturation * (1 - fractional));
	d->rgb_map[0] = (t_rgb){.r = light, .g = tinted, .b = base};
	d->rgb_map[1] = (t_rgb){.r = shaded, .g = light, .b = base};
	d->rgb_map[2] = (t_rgb){.r = base, .g = light, .b = tinted};
	d->rgb_map[3] = (t_rgb){.r = base, .g = shaded, .b = light};
	d->rgb_map[4] = (t_rgb){.r = tinted, .g = base, .b = light};
	d->rgb_map[5] = (t_rgb){.r = light, .g = base, .b = shaded};
	return (rgb_to_int(d->rgb_map[i].r, d->rgb_map[i].g, d->rgb_map[i].b));
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

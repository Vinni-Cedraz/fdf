/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:15:04 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/04 20:07:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static double			get_phi(t_point p, double steps_y);

void	get_phi_and_theta(t_data *d)
{
	t_point	p;
	t_n		*map;
	double	steps_x;
	double	steps_y;

	map = d->map->pts;
	steps_x = (M_PI * 2) / d->map->width;
	steps_y = M_PI / d->map->height;
	d->map->radius = d->map->width / (M_PI * 2);
	d->map->radius *= d->offset->scale;
	while (map)
	{
		p = map->point;
		p.ball.theta = p.ol.raw.x * steps_x;
		p.ball.phi = get_phi(p, steps_y);
		map->point = p;
		map = map->next;
	}
}

static inline double	get_phi(t_point p, double steps_y)
{
	double	phi;

	phi = (p.ol.raw.y + (p.ol.raw.y / 2)) * steps_y + 0.5 * steps_y;
	return (phi);
}

void	go_spherical(t_data *d)
{
	float	phi;
	float	theta;
	t_n		*node;
	t_point	p;

	node = d->map->pts;
	while (node)
	{
		p = node->point;
		phi = p.ball.phi;
		theta = p.ball.theta;
		p.x = (d->map->radius + (p.ol.raw.z * 0.05)) * cos(theta) * sin(phi);
		p.y = (d->map->radius + (p.ol.raw.z * 0.05)) * sin(theta) * sin(phi);
		p.z = (d->map->radius + (p.ol.raw.z * 0.05)) * cos(phi);
		node->point = p;
		node = node->next;
	}
	d->state.parallel = 0;
}

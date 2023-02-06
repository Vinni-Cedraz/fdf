/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:15:04 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 22:07:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	update_state_after_spherical(t_data *d);

void	get_phi_and_theta(t_data *d)
{
	t_point	p;
	t_n		*map;
	double	steps_x;
	double	steps_y;

	map = d->map->pts;
	steps_x = (M_PI * 2) / (d->map->width - 1);
	steps_y = M_PI / d->map->height;
	while (map)
	{
		p = map->point;
		p.ball.phi = (p.ol.raw.x) * steps_x;
		p.ball.theta = (p.ol.raw.y + (d->map->height / 2)) * steps_y - M_PI / 2;
		map->point = p;
		map = map->next;
	}
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
		p.x = (d->map->radius + (p.ol.raw.z * 0.05)) * cos(phi) * sin(theta);
		p.y = (d->map->radius + (p.ol.raw.z * 0.05)) * sin(phi) * sin(theta);
		p.z = (d->map->radius + (p.ol.raw.z * 0.05)) * cos(theta);
		node->point = p;
		node = node->next;
	}
	update_state_after_spherical(d);
}

static void	update_state_after_spherical(t_data *d)
{
	d->state = spherical;
	d->map->ball.center_x = (d->map->min_x + d->map->max_x) / 2;
	d->map->ball.center_y = (d->map->min_y + d->map->max_y) / 2;
	d->map->ball.center_z = (d->map->min_z + d->map->max_z) / 2;
}

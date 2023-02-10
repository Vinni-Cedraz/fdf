/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:15:04 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/10 16:46:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			update_state_after_spherical(t_data *d);

void	get_phi_and_theta(t_data *d)
{
	t_point	p;
	t_n		*map;
	double	spread_points_horizontally;
	double	spread_points_vertically;

	map = d->map->pts;
	spread_points_horizontally = M_PI * 2 / (d->map->width - 1);
	spread_points_vertically = M_PI / d->map->height;
	while (map)
	{
		p = map->point;
		p.ball.phi = -p.ol.raw.x * spread_points_horizontally;
		p.ball.theta = p.ol.raw.y * spread_points_vertically;
		map->point = p;
		map = map->next;
	}
}

void	go_spherical(t_data *d)
{
	float	phi;
	float	theta;
	float	rho;
	t_n		*node;

	if (d->state != randomly_rotated && d->state != spherical)
		return ;
	node = d->map->pts;
	while (node)
	{
		phi = node->point.ball.phi;
		theta = node->point.ball.theta;
		rho = (d->map->radius + (node->point.ol.raw.z * d->map->ball.delta));
		node->point.x = rho * cos(phi) * sin(theta);
		node->point.y = rho * sin(phi) * sin(theta);
		node->point.z = rho * cos(theta);
		node = node->next;
	}
	update_state_after_spherical(d);
}

inline void	increase_sphere_height(t_data *d)
{
	d->map->ball.delta += 0.05;
	go_spherical(d);
}

inline void	decrease_sphere_height(t_data *d)
{
	d->map->ball.delta -= 0.05;
	go_spherical(d);
}

static inline void	update_state_after_spherical(t_data *d)
{
	static int	first;

	first++;
	d->state = spherical;
	d->offset->move_x = (double)WIN_WDTH / 2 + MENU_WIDTH;
	d->offset->move_y = (double)WIN_HGHT / 2;
	if (first == 1)
	{
		get_xy_range_bonus(d);
		get_altitude_range_bonus(d->map);
		d->map->ball.center_x = (d->map->min_x + d->map->max_x) / 2;
		d->map->ball.center_y = (d->map->min_y + d->map->max_y) / 2;
		d->map->ball.center_z = (d->map->min_z + d->map->max_z) / 2;
	}
}

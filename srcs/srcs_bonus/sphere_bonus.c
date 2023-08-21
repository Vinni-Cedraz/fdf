/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:15:04 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:35:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			update_state_after_spherical(void);

void	get_phi_and_theta(t_point *point)
{
	double	spread_points_vertically;
	double	spread_points_horizontally;

	get_data()->map->set_radius();
	spread_points_horizontally = PI * 2 / (get_data()->map->width - 1);
	spread_points_vertically = PI / get_data()->map->height;
	point->ball.phi = -(point->ol.raw.x * spread_points_horizontally);
	point->ball.theta = point->ol.raw.y * spread_points_vertically;
}

void	go_spherical(void)
{
	float	phi;
	float	theta;
	float	rho;
	t_n		*node;
	t_data	*d;

	d = get_data();
	if (d->state != randomly_rotated && d->state != spherical)
		return ;
	node = d->map->pts;
	while (node->next != d->map->pts)
	{
		phi = node->point.ball.phi;
		theta = node->point.ball.theta;
		rho = (d->map->radius + (node->point.ol.raw.z * d->map->ball.delta));
		node->point.x = rho * cos(phi) * sin(theta);
		node->point.y = rho * sin(phi) * sin(theta);
		node->point.z = rho * cos(theta);
		node = node->next;
	}
	update_state_after_spherical();
}

inline void	increase_sphere_height(void)
{
	get_data()->map->ball.delta += 0.01;
	go_spherical();
}

inline void	decrease_sphere_height(void)
{
	get_data()->map->ball.delta -= 0.01;
	go_spherical();
}

static inline void	update_state_after_spherical(void)
{
	static size_t	first;
	t_data			*d;

	first++;
	d = get_data();
	d->state = spherical;
	d->offset->move_x = (double)WIN_WDTH / 2 + (double)d->scale->menu_width / 2;
	d->offset->move_y = (double)WIN_HGHT / 2;
	if (first == 1)
	{
		get_xyz_range_bonus();
		d->map->ball.center_x = (d->map->min_x + d->map->max_x) / 2;
		d->map->ball.center_y = (d->map->min_y + d->map->max_y) / 2;
		d->map->ball.center_z = (d->map->min_z + d->map->max_z) / 2;
	}
}

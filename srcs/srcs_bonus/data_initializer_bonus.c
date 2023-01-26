/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/26 12:43:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			find_center_of_the_map(t_data *d);
static void			get_phi_and_theta(t_node_with_a_point *map);
static void			aux_get_phi_and_theta(t_point *p);

void	data_initializer_bonus(t_data *d)
{
	d->matrix = ft_calloc(sizeof(t_rotation_matrices), 1);
	d->mlx = malloc(sizeof(t_mlx));
	open_win_and_img_bonus(d);
	d->state = (t_state){0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
	initialize_transition_methods_bonus(d);
	get_altitude_range_bonus(d->map);
	colorize_points_bonus(d);
	define_rotation_matrices_bonus(d->matrix);
	find_center_of_the_map(d);
	get_phi_and_theta(d->map->pts);
}

static void	find_center_of_the_map(t_data *d)
{
	uint				index;
	t_node_with_a_point	*central_node;

	if (d->map->size % 2 == 0)
		index = (d->map->size / 2) + d->map->width / 2;
	else
		index = d->map->size / 2;
	central_node = ft_lstpoint_getby_index(d->map->pts, index);
	d->center.x = central_node->point.x;
	d->center.y = central_node->point.y;
	d->center.z = central_node->point.z;
}

static void	get_phi_and_theta(t_node_with_a_point *map)
{
	t_node_with_a_point	*aux;

	aux = map;
	while (aux)
	{
		aux_get_phi_and_theta(&aux->point);
		aux = aux->next;
	}
}

static inline void	aux_get_phi_and_theta(t_point *p)
{
	p->ball.theta = atan2(p->x, p->y);
	p->ball.phi = atan2(p->z, hypot(p->x, p->y));
}

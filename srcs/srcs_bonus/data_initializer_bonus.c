/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 16:50:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include <libs/ft_printf_libft/libft/libft_bonus.h>

static void			get_phi_and_theta(t_node_with_a_point *map);
static void			aux_get_phi_and_theta(t_point *p);
void				take_zoom_snapshot(t_data *d);

void	data_initializer_bonus(t_data *d)
{
	d->matrix = ft_calloc(sizeof(t_rotation_matrices), 1);
	d->mlx = malloc(sizeof(t_mlx));
	open_win_and_img_bonus(d);
	d->state = (t_state){0, 0, 0, 0, 0, 1, 1};
	initialize_lookup_lists_bonus(d);
	get_altitude_range_bonus(d->map);
	colorize_points_bonus(d);
	define_rotation_matrices_bonus(d->matrix);
	d->map->get_center = &find_map_center;
	get_phi_and_theta(d->map->pts);
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

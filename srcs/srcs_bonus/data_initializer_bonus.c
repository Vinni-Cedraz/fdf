/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/25 23:05:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			find_center_of_the_map(t_data *d);
static void			open_win_and_img(t_data *data);
static void			get_phi_and_theta(t_node_with_a_point *map);
static void			aux_get_phi_and_theta(t_point *p);

void	data_initializer_bonus(t_data *d)
{
	d->matrix = ft_calloc(sizeof(t_rotation_matrices), 1);
	d->mlx = malloc(sizeof(t_mlx));
	open_win_and_img(d);
	d->state = (t_state){0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
	initialize_transition_methods_bonus(d);
	get_altitude_range_bonus(d->map);
	colorize_points_bonus(d);
	define_rotation_matrices_bonus(d->matrix);
	find_center_of_the_map(d);
	get_phi_and_theta(d->map->pts);
}

static void	open_win_and_img(t_data *d)
{
	int	win_w;
	int	win_h;
	int	*bpp;
	int	*endian;
	int	*line_len;

	bpp = &d->img->bpp;
	line_len = &d->img->line_len;
	win_w = WINDOW_WIDTH;
	win_h = WINDOW_HEIGHT;
	endian = &d->img->endian;
	d->mlx->ptr = mlx_init();
	d->img->width = WINDOW_WIDTH;
	d->img->height = WINDOW_HEIGHT;
	d->mlx->win_ptr = mlx_new_window(d->mlx->ptr, win_w, win_h, "mlx 42");
	d->img->ptr = mlx_new_image(d->mlx->ptr, win_w, win_h);
	d->img->addr = mlx_get_data_addr(d->img->ptr, bpp, line_len, endian);
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

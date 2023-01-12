/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 19:51:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			find_center_of_the_map(t_data *d);
// static void			open_win_and_img(t_data *data);
static void			get_phi_and_theta(t_node_with_a_point *map);
static void			aux_get_phi_and_theta(t_point *p);

void	data_initializer_bonus(t_data *d)
{
	// d->matrix = ft_calloc(sizeof(t_rotation_matrices), 1);
	// d->mlx = malloc(sizeof(t_mlx));
	// open_win_and_img(d);
	d->state = (t_state){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
	// define_rotation_matrices_bonus(d->matrix);
	find_center_of_the_map(d);
	get_phi_and_theta(d->map->pts);
}

// static void	open_win_and_img(t_data *data)
// {
// 	data->mlx->mlx_ptr = mlx_init();
// 	data->img->width = WINDOW_WIDTH;
// 	data->img->height = WINDOW_HEIGHT;
// 	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, WINDOW_WIDTH,
// 			WINDOW_HEIGHT, "mlx 42");
// 	data->img->mlx_img = mlx_new_image(data->mlx->mlx_ptr, WINDOW_WIDTH,
// 			WINDOW_HEIGHT);
// 	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
// 			&data->img->line_len, &data->img->endian);
// }

static void	find_center_of_the_map(t_data *d)
{
	uint	half_map_size;

	half_map_size = d->map->size / 2;
	d->offset.cx = ft_lstpoint_getby_index(d->map->pts, half_map_size)->point.x;
	d->offset.cy = ft_lstpoint_getby_index(d->map->pts, half_map_size)->point.y;
	d->offset.cz = ft_lstpoint_getby_index(d->map->pts, half_map_size)->point.z;
	printf("cx: %lf cy: %lf cz: %lf\n", d->offset.cx, d->offset.cy, d->offset.cz);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 23:36:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			find_center_of_the_map(t_data *d);
static void			open_win_and_img(t_data *data);
static void			get_phi_and_theta(t_map *map);
static inline void	aux_get_phi_and_theta(t_point *p);

void	data_initializer_bonus(t_data *d)
{
	d->matrix = ft_calloc(sizeof(t_rotation_matrices), 1);
	d->mlx = malloc(sizeof(t_mlx));
	open_win_and_img(d);
	d->state = (t_state){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
	define_rotation_matrices_bonus(d->matrix);
	find_center_of_the_map(d);
	get_phi_and_theta(d->map);
}

static void	open_win_and_img(t_data *data)
{
	data->mlx->mlx_ptr = mlx_init();
	data->img->width = WINDOW_WIDTH;
	data->img->height = WINDOW_HEIGHT;
	data->mlx->win_ptr = mlx_new_window(data->mlx->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "mlx 42");
	data->img->mlx_img = mlx_new_image(data->mlx->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
}

static void	find_center_of_the_map(t_data *d)
{
	d->offset.cx = d->map->pts[d->map->height / 2][d->map->width / 2].x;
	d->offset.cy = d->map->pts[d->map->height / 2][d->map->width / 2].y;
	d->offset.cz = d->map->pts[d->map->height / 2][d->map->width / 2].z;
}

static void	get_phi_and_theta(t_map *map)
{
	t_short	i;
	t_short	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			aux_get_phi_and_theta(&map->pts[i][j]);
	}
}

static inline void	aux_get_phi_and_theta(t_point *p)
{
	double	latitude;
	double	longitude;

	latitude = atan2(p->z, sqrt(pow(p->x, 2) + pow(p->y, 2)));
	longitude = atan2(p->y, p->x);
	p->theta = -longitude;
	p->phi = -(90 - latitude);
}

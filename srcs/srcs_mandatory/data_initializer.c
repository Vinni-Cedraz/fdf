/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/08 17:19:27 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	open_win_and_img(t_data *data);
static void	find_center_of_the_img(t_data *d);

void	data_initializer(t_data *d)
{
	d->do_step_one = 0;
	d->do_step_two = 0;
	d->matrix = ft_calloc(sizeof(t_rotation_matrices), 1);
	if (ft_strnstr(d->argv[1], "elem-fract.fdf", ft_strlen(d->argv[1])))
		d->move_y -= 50;
	find_center_of_the_img(d);
	open_win_and_img(d);
	define_rotation_matrices(d->matrix);
}

static void	open_win_and_img(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->img->width = WINDOW_WIDTH;
	data->img->height = WINDOW_HEIGHT;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"mlx 42");
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
}

static void	find_center_of_the_img(t_data *d)
{
	d->cx = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->cy = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->cz = d->map->arr[d->map->height / 2][d->map->width / 2].z;
}

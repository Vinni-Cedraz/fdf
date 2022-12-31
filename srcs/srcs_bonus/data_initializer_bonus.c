/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 16:41:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	open_win_and_img(t_data *data);

void	data_initializer_bonus(t_data *d)
{
	open_win_and_img(d);
	d->grid_style_nb = 1;
	d->rotations_history = ft_lstnew(NULL);
	d->reverse_5_around_x = 0;
	d->rotate_5_around_x = 0;
	d->neutral_x = 1;
	d->neutral_y = 1;
	d->reverse_5_around_y = 0;
	d->rotate_5_around_y = 0;
	d->apply_iso = 0;
	d->reset_iso = 0;
	d->neutral_iso = 0;
	d->do_step_one = 0;
	d->do_step_two = 0;
	d->zoom_in = 0;
	d->zoom_out = 0;
	d->neutral_zoom = 1;
	d->move_x = 0;
	d->move_y = 0;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 22:06:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	open_win_and_img(t_data *data);

void	data_initializer_bonus(t_data *d)
{
	d->mlx = malloc(sizeof(t_mlx));
	open_win_and_img(d);
	d->rotations_history = ft_lstnew(NULL);
	d->state.grid_style_nb = 1;
	d->state.reverse_5_around_x = 0;
	d->state.rotate_5_around_x = 0;
	d->state.neutral_x = 1;
	d->state.neutral_y = 1;
	d->state.reverse_5_around_y = 0;
	d->state.rotate_5_around_y = 0;
	d->state.step_forward = 0;
	d->state.step_back = 0;
	d->state.isometric = 0;
	d->state.do_step_one = 0;
	d->state.do_step_two = 0;
	d->state.zoom_in = 0;
	d->state.zoom_out = 0;
	d->state.neutral_zoom = 1;
	d->offset = (t_offset){0, 0, 0, 0, 0, 0, 0, 0, 0};
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

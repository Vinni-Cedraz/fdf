/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_win_n_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:55:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 19:28:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	open_img(t_data *data);

void	open_win_n_img(t_data *data)
{
	data->mlx->ptr = mlx_init();
	data->img->width = WINDOW_WIDTH;
	data->img->height = WINDOW_HEIGHT;
	data->mlx->win = mlx_new_window(data->mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"mlx 42");
	open_img(data);
}

static void	open_img(t_data *data)
{
	data->img->ptr = mlx_new_image(data->mlx->ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->ptr, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
}

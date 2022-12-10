/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_win_n_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:55:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/10 17:23:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

void	open_win_n_img(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"mlx 42");
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
}

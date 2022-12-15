/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:30:39 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/15 19:32:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

void	open_img(t_data *data)
{
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, \
	WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, \
	&data->img->line_len, &data->img->endian);
}

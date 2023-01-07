/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:47:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/06 22:31:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	paint_it_black(t_data *data);

int	draw(t_data *d)
{
	paint_it_black(d);
	colorize(d->map);
	render_map(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
	return (0);
}

static void	paint_it_black(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->height)
	{
		j = 0;
		while (j < data->img->width)
		{
			put_pixel_img(data->img, j, i, BLACK);
			j++;
		}
		i++;
	}
}

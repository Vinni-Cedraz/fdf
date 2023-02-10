/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:47:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/10 19:11:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	paint_it_black(t_data *data);

int	draw(t_data *d)
{
	static short	first;

	first++;
	paint_it_black(d);
	colorize(d->map);
	if (first == 1)
	{
		linear_transformations(d, &d->matrix->rot_z_45);
		linear_transformations(d, &d->matrix->rot_x_54_73);
	}
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

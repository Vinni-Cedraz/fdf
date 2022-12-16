/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/15 23:44:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

int	deal_key(int key, t_data *data)
{
	if (key == XK_ESCAPE)
		close_win(data);
	if (key == XK_RIGHT)
	{
		blackout(data);
		data->move_x += 25;
		render_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img->mlx_img, 0, 0);
	}
	if (key == XK_LEFT)
	{	
		blackout(data);
		data->move_x -= 25;
		render_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img->mlx_img, 0, 0);
	}
	if (key == XK_UP)
	{
		blackout(data);
		data->move_y -= 25;
		render_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img->mlx_img, 0, 0);
	}
	if (key == XK_DOWN)
	{
		blackout(data);
		data->move_y += 25;
		render_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img->mlx_img, 0, 0);
	}
	return (0);
}

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img);
	ft_free_t_data(&data);
	exit(0);
}

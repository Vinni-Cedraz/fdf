/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/26 17:06:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	close_win_bonus(t_data *data)
{
	printf("biggest x %f\n", data->map->arr[data->map->height - 1][data->map->width - 1].x);
	printf("biggest y %f\n", data->map->arr[data->map->height - 1][data->map->width - 1].y);
	printf("smallest x %f\n", data->map->arr[0][0].x);
	printf("smallest y %f\n", data->map->arr[0][0].y);
	printf("WIDTH: %f", data->map->arr[data->map->height - 1][data->map->width - 1].x - data->map->arr[0][0].x);
	printf("HEIGHT: %f", data->map->arr[data->map->height - 1][data->map->width - 1].y - data->map->arr[0][0].y);
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img);
	ft_free_t_map(data->map->arr);
	free(data->map);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:18:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 19:33:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx->ptr, data->img->ptr);
	mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	mlx_destroy_display(data->mlx->ptr);
	free(data->mlx->ptr);
	free(data->img);
	free_t_map(data->map->arr);
	free(data->map);
	exit(0);
}

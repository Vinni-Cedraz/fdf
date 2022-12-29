/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 22:28:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	close_win_bonus(t_data *data)
{
	mlx_destroy_image(data->mlx->ptr, data->img->ptr);
	mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	mlx_destroy_display(data->mlx->ptr);
	free(data->mlx->ptr);
	free(data->img);
	ft_free_t_map(data->map->arr);
	free(data->map);
	free(data->mlx);
	free(data->offset);
	free(data->state);
	exit(0);
}

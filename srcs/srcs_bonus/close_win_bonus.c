/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 21:05:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	close_win_bonus(t_data *data)
{
	if (data->state.neutral_y == 0)
		two_steps_to_isometry_bonus(data, 1, 0);
	else if (data->state.neutral_x == 0)
		two_steps_to_isometry_bonus(data, 1, 0);
	free(data->rotations_history);
	mlx_destroy_image(data->mlx->mlx_ptr, data->img->mlx_img);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx);
	free(data->img);
	ft_free_t_map(data->map->pts);
	free(data->map);
	free(data->matrix);
	free(data);
	exit(0);
}

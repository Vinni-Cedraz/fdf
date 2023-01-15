/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/14 22:57:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	close_win_bonus(t_data *d)
{
	if (d->state.neutral_y == 0)
		two_steps_to_isometry_bonus(d, 1, 0);
	else if (d->state.neutral_x == 0)
		two_steps_to_isometry_bonus(d, 1, 0);
	mlx_destroy_image(d->mlx->mlx_ptr, d->img->mlx_img);
	mlx_destroy_window(d->mlx->mlx_ptr, d->mlx->win_ptr);
	mlx_destroy_display(d->mlx->mlx_ptr);
	free(d->mlx->mlx_ptr);
	free(d->mlx);
	free(d->img);
	free(d->matrix);
	ft_lstpoint_free(&d->map->pts);
	free(d->map);
	free(d);
	exit(0);
}

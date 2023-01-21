/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 01:47:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	close_win_bonus(t_data *d)
{
	mlx_destroy_image(d->mlx->ptr, d->img->ptr);
	mlx_destroy_window(d->mlx->ptr, d->mlx->win_ptr);
	mlx_destroy_display(d->mlx->ptr);
	free(d->mlx->ptr);
	free(d->mlx);
	free(d->img);
	free(d->matrix);
	ft_lstpoint_free(&d->map->pts);
	free(d->map);
	free(d);
	exit(0);
}

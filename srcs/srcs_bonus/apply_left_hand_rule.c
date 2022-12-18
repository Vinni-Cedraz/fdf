/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_left_hand_rule.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:04:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/17 21:10:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_apply_left_hand_rule(t_point *point);

int	apply_left_hand_rule(t_data *d)
{
	blackout_bns(d);
	aux_apply_left_hand_rule(*d->map->arr);
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
	return (0);
}

static void	aux_apply_left_hand_rule(t_point *point)
{
	int	x;
	int	y;
	int	z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = -x;
	point->y = -y;
	point->z = -z;
}

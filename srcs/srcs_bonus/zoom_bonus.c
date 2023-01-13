/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 20:56:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	zoom_in(t_data *d);
static void	zoom_out(t_data *d);
static void	reset_zoom(t_data *d);

void	zoom_bonus(t_data *d, t_short in, t_short out, t_short reset)
{
	if (in)
	{
		if ((d->state.zoom_in - d->state.zoom_out) >= 36)
			return ;
		zoom_in(d);
	}
	else if (out)
	{
		if ((d->state.zoom_out - d->state.zoom_in) >= 36)
			return ;
		zoom_out(d);
	}
	else if (reset)
		reset_zoom(d);
}

static void	zoom_in(t_data *d)
{
	double				centered_origin_x;
	double				centered_origin_y;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	d->state.zoom_in++;
	while (tmp)
	{
		centered_origin_x = tmp->point.x - d->center.x;
		centered_origin_y = tmp->point.y - d->center.y;
		tmp->point.x = d->center.x + centered_origin_x * 1.1;
		tmp->point.y = d->center.y + centered_origin_y * 1.1;
		tmp = tmp->next;
	}
	update_state(d);
}

static void	zoom_out(t_data *d)
{
	double				centered_origin_x;
	double				centered_origin_y;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	d->state.zoom_out++;
	while (tmp)
	{
		centered_origin_x = tmp->point.x - d->center.x;
		centered_origin_y = tmp->point.y - d->center.y;
		tmp->point.x = d->center.x + centered_origin_x / 1.1;
		tmp->point.y = d->center.y + centered_origin_y / 1.1;
		tmp = tmp->next;
	}
	update_state(d);
}

static void	reset_zoom(t_data *d)
{
	t_short	i;
	t_short	successive_operations;

	i = -1;
	if (d->state.neutral_zoom)
		return ;
	zoom_bonus(d, 1, 0, 0);
	zoom_bonus(d, 0, 1, 0);
	if (d->state.zoom_in > d->state.zoom_out)
	{
		successive_operations = (d->state.zoom_in - d->state.zoom_out);
		while (++i < successive_operations)
			zoom_bonus(d, 0, 1, 0);
	}
	else
	{
		successive_operations = (d->state.zoom_out - d->state.zoom_in);
		while (++i < successive_operations)
			zoom_bonus(d, 1, 0, 0);
	}
}

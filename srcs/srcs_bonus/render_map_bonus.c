/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 07:21:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_render_map(t_data *d);
static void	render_last_line(t_data *d);
static void	render_last_column(t_data *d);

void	render_map_bns(t_data *d)
{
	aux_render_map(d);
	render_last_line(d);
	render_last_column(d);
	draw_menu_background(d->img);
	draw_menu(d);
}

static void	aux_render_map(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height - 1)
	{
		j = 0;
		while (j < d->map->width - 1)
		{
			if (j <= d->map->width / 2)
				render_line_bns(d->map->arr[i][j], d->map->arr[i][j + 1], \
				d->map->arr[i][j].color, d);
			else
				render_line_bns(d->map->arr[i][j], d->map->arr[i][j + 1], \
				d->map->arr[i][j + 1].color, d);
			if (i < d->map->height / 2)
				render_line_bns(d->map->arr[i][j], d->map->arr[i + 1][j], \
				d->map->arr[i][j].color, d);
			else
				render_line_bns(d->map->arr[i][j], d->map->arr[i + 1][j], \
				d->map->arr[i + 1][j].color, d);
			j++;
		}
		i++;
	}
}

static void	render_last_column(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->map->height - 1)
	{
		if (i < d->map->height - 1)
			render_line_bns(d->map->arr[i][d->map->width - 1], \
				d->map->arr[i + 1][d->map->width - 1], \
				d->map->arr[i + 1][d->map->width - 1].color, d);
		i++;
	}
}

static void	render_last_line(t_data *d)
{
	int	j;

	j = 0;
	while (j < d->map->width - 1)
	{
		if (j <= d->map->width / 2)
			render_line_bns(d->map->arr[d->map->height - 1][j], \
				d->map->arr[d->map->height - 1][j + 1], \
				d->map->arr[d->map->height - 1][j].color, d);
		else
			render_line_bns(d->map->arr[d->map->height - 1][j], \
				d->map->arr[d->map->height - 1][j + 1], \
				d->map->arr[d->map->height - 1][j + 1].color, d);
		j++;
	}
}

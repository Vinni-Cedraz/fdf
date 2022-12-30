/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_x_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:28:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 12:26:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_rotate_5_around_x(t_data *d);
static void	aux_reverse_5_around_x(t_data *d);
static void	find_center(t_data *d);

void	rotate_5_around_x(t_data *d)
{
	if (!d->neutral_iso)
		return ;
	d->rotate_5_around_x++;
	ft_lstadd_front(&d->rotations_history, ft_lstnew("rot_x"));
	if ((d->rotate_5_around_x - d->reverse_5_around_x) == 0)
		d->neutral_x = 1;
	else
		d->neutral_x = 0;
	zoom(d, 0, 0, 1);
	aux_rotate_5_around_x(d);
}

void	reverse_5_around_x(t_data *d)
{
	if (!d->neutral_iso)
		return ;
	d->reverse_5_around_x++;
	ft_lstadd_front(&d->rotations_history, ft_lstnew("rev_x"));
	if ((d->rotate_5_around_x - d->reverse_5_around_x) == 0)
		d->neutral_x = 1;
	else
		d->neutral_x = 0;
	zoom(d, 0, 0, 1);
	aux_reverse_5_around_x(d);
}

static void	find_center(t_data *d)
{
	d->cy = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->cx = d->map->arr[d->map->height / 2][d->map->width / 2].x;
}

static void	aux_rotate_5_around_x(t_data *d)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			y = d->map->arr[i][j].y - d->cy;
			z = d->map->arr[i][j].z - d->cz;
			d->map->arr[i][j].y = y * cos(RAD_5) + z * sin(RAD_5) + d->cy;
			d->map->arr[i][j].z = -y * sin(RAD_5) + z * cos(RAD_5) + d->cz;
			j++;
		}
		i++;
	}
}

static void	aux_reverse_5_around_x(t_data *d)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			y = d->map->arr[i][j].y - d->cy;
			z = d->map->arr[i][j].z - d->cz;
			d->map->arr[i][j].y = y * cos(RAD_5) - z * sin(RAD_5) + d->cy;
			d->map->arr[i][j].z = y * sin(RAD_5) + z * cos(RAD_5) + d->cz;
			j++;
		}
		i++;
	}
}

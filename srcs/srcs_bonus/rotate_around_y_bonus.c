/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_around_y_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:50:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 19:07:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_rotate_5_around_y(t_data *d);
static void	aux_reverse_5_around_y(t_data *d);
static void	find_center(t_data *d);

void	rotate_around_y(t_data *d, short int rot, short int rev)
{
	if (!d->neutral_iso)
		return ;
	if (rot)
	{
		d->rotate_5_around_y++;
		ft_lstadd_front(&d->rotations_history, ft_lstnew("rev_y"));
		if ((d->rotate_5_around_y - d->reverse_5_around_y) == 0)
			d->neutral_y = 1;
		else
			d->neutral_y = 0;
		zoom_bonus(d, 0, 0, 1);
		aux_rotate_5_around_y(d);
	}
	if (rev)
	{
		d->reverse_5_around_y++;
		ft_lstadd_front(&d->rotations_history, ft_lstnew("rot_y"));
		if ((d->rotate_5_around_y - d->reverse_5_around_y) == 0)
			d->neutral_y = 1;
		else
			d->neutral_y = 0;
		zoom_bonus(d, 0, 0, 1);
		aux_reverse_5_around_y(d);
	}
}

static void	find_center(t_data *d)
{
	d->cx = (double)d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->cz = (double)d->map->arr[d->map->height / 2][d->map->width / 2].z;
}

static void	aux_rotate_5_around_y(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x - d->cx;
			z = d->map->arr[i][j].z - d->cz;
			d->map->arr[i][j].x = x * cos(RAD) + z * sin(RAD) + d->cx;
			d->map->arr[i][j].z = -x * sin(RAD) + z * cos(RAD) + d->cz;
			j++;
		}
		i++;
	}
}

static void	aux_reverse_5_around_y(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x - d->cx;
			z = d->map->arr[i][j].z - d->cz;
			d->map->arr[i][j].x = x * cos(-RAD) + z * sin(-RAD) + d->cx;
			d->map->arr[i][j].z = -x * sin(-RAD) + z * cos(-RAD) + d->cz;
			j++;
		}
		i++;
	}
}
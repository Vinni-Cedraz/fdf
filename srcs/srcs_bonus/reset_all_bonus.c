/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_all_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:11:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 01:28:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	reset_zoom(t_data *d)
{
	short int	successive_operations;
	short int	i;

	i = -1;
	if (d->neutral_zoom)
		return ;
	else if (d->zoom_in > d->zoom_out)
	{
		successive_operations = (d->zoom_in - d->zoom_out);
		while (++i < successive_operations)
			zoom_out(d);
	}
	else
	{
		successive_operations = (d->zoom_out - d->zoom_in);
		while (++i < successive_operations)
			zoom_in(d);
	}
}

void	reset_rotation_around_x(t_data *d)
{
	short int	successive_operations;
	short int	i;

	i = -1;
	if (d->neutral_x)
		return ;
	else if (d->rotate_2_around_x > d->reverse_2_around_x)
	{
		successive_operations = (d->rotate_2_around_x - d->reverse_2_around_x);
		while (++i < successive_operations)
			reverse_2_around_x(d);
	}
	else
	{
		successive_operations = (d->reverse_2_around_x - d->rotate_2_around_x);
		while (++i < successive_operations)
			rotate_2_around_x(d);
	}
}

void	reset_rotation_around_y(t_data *d)
{
	short int	successive_operations;
	short int	i;

	i = -1;
	if (d->neutral_y)
		return ;
	else if (d->rotate_2_around_y > d->reverse_2_around_y)
	{
		successive_operations = (d->rotate_2_around_y - d->reverse_2_around_y);
		while (++i < successive_operations)
			reverse_2_around_y(d);
	}
	else
	{
		successive_operations = (d->reverse_2_around_y - d->rotate_2_around_y);
		while (++i < successive_operations)
			rotate_2_around_y(d);
	}
}

void	get_back_to_isometric(t_data *d)
{
	reset_zoom(d);
	reset_rotation_around_x(d);
	reset_rotation_around_y(d);
}

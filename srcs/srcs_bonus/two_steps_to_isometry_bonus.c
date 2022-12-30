/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_steps_to_isometry_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 20:05:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	take_first_step(t_map *map);
static void	take_second_step(t_map *map);
static void	restore_isometric_state(t_data *d);

void	two_steps_to_isometry_bonus(t_data *d, short int not_from_parallel)
{
	if (not_from_parallel)
		restore_isometric_state(d);
	if (d->neutral_iso)
		return ;
	d->apply_iso++;
	if ((d->apply_iso - d->reset_iso) == 1)
	{
		d->do_step_one = 1;
		d->do_step_two = 0;
	}
	else if ((d->apply_iso - d->reset_iso) == 2)
	{
		d->do_step_two = 1;
		d->do_step_one = 0;
	}
	else
		return ;
	if (d->do_step_one)
		take_first_step(d->map);
	else if (d->do_step_two)
		take_second_step(d->map);
	if (d->apply_iso - d->reset_iso == 2)
		d->neutral_iso = 1;
}

static void	take_first_step(t_map *map)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x = map->arr[i][j].x;
			y = map->arr[i][j].y;
			map->arr[i][j].x = x * cos(RAD_45) - y * sin(RAD_45);
			map->arr[i][j].y = x * sin(RAD_45) + y * cos(RAD_45);
			j++;
		}
		i++;
	}
}

static void	take_second_step(t_map *map)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			y = map->arr[i][j].y;
			z = map->arr[i][j].z;
			map->arr[i][j].y = y * cos(RAD_54_73) - z * sin(RAD_54_73);
			map->arr[i][j].z = y * sin(RAD_54_73) + z * cos(RAD_54_73);
			j++;
		}
		i++;
	}
}

static void	restore_isometric_state(t_data *d)
{
	t_node	*temp;

	temp = d->rotations_history;
	if (temp->content == NULL)
		return ;
	while (temp)
	{
		if (temp->content == NULL)
			break ;
		else if (!ft_strncmp(temp->content, "rev_x", 5))
			rotate_around_x(d, 0, 1);
		else if (!ft_strncmp(temp->content, "rot_x", 5))
			rotate_around_x(d, 1, 0);
		else if (!ft_strncmp(temp->content, "rev_y", 5))
			rotate_around_y(d, 0, 1);
		else if (!ft_strncmp(temp->content, "rot_y", 5))
			rotate_around_y(d, 1, 0);
		temp = temp->next;
	}
	ft_free_list(&d->rotations_history);
	d->neutral_iso = 1;
	d->do_step_one = 0;
	d->do_step_two = 1;
}

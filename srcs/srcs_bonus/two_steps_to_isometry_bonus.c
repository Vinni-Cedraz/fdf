/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_steps_to_isometry_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/25 23:55:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf_libft/libft/libft_bonus.h"
#include "fdf_includes_bonus.h"

void		apply_iso_steps(t_data *d);
void		restore_from_snapshot(t_data *d);
static void	take_snapshot(t_data *d);

void	two_steps_to_isometry_bonus(t_data *d, t_isometry_changer iso_changer)
{
	iso_changer.action(d);
	if (d->state.isometric)
		take_snapshot(d);
}

void	apply_iso_steps(t_data *d)
{
	((t_func_ptr)(d->state_transition_methods->content))(d);
	d->state_transition_methods = d->state_transition_methods->next;
}

static void	take_snapshot(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.ol.x = tmp->point.x;
		tmp->point.ol.y = tmp->point.y;
		tmp->point.ol.z = tmp->point.z;
		tmp = tmp->next;
	}
}

void	restore_from_snapshot(t_data *d)
{
	t_node_with_a_point	*tmp;

	if (d->state.isometric)
		return ;
	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.x = tmp->point.ol.x;
		tmp->point.y = tmp->point.ol.y;
		tmp->point.z = tmp->point.ol.z;
		tmp = tmp->next;
	}
}

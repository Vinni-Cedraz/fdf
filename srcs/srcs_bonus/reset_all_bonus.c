/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_all_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:11:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/29 19:05:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	reset_zoom(t_data *d)
{
	short int	successive_operations;
	short int	i;

	i = -1;
	zoom_out(d);
	zoom_in(d);
	if (d->neutral_zoom)
		return ;
	if (d->zoom_in > d->zoom_out)
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

void	reset_rotations(t_data *d)
{
	t_node	*temp;

	if (d->rotations_history->content == NULL)
		return ;
	temp = d->rotations_history;
	while (temp)
	{
		if (temp->content == NULL)
			break ;
		if (!ft_strncmp(temp->content, "rot_x", 5))
			reverse_5_around_x(d);
		else if (!ft_strncmp(temp->content, "rev_x", 5))
			rotate_5_around_x(d);
		else if (!ft_strncmp(temp->content, "rot_y", 5))
			reverse_5_around_y(d);
		else if (!ft_strncmp(temp->content, "rev_y", 5))
			rotate_5_around_y(d);
		temp = temp->next;
	}
	ft_free_list(&d->rotations_history);
}

void	get_back_to_isometric(t_data *d)
{
	reset_zoom(d);
	reset_rotations(d);
}

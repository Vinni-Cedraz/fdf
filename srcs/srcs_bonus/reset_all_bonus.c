/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_all_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:11:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 12:26:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

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
		else if (!ft_strncmp(temp->content, "rot_x", 5))
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
	zoom(d, 0, 0, 1);
	reset_rotations(d);
}

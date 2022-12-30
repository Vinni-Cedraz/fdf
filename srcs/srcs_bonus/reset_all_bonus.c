/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_all_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:11:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 16:27:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	get_back_to_isometric(t_data *d, double angle)
{
	t_node	*temp;

	if (d->rotations_history->content == NULL)
		return ;
	temp = d->rotations_history;
	while (temp)
	{
		if (temp->content == NULL)
			break ;
		else if (!ft_strncmp(temp->content, "rev_x", 5))
			rotate_around_x(d, angle, 0, 1);
		else if (!ft_strncmp(temp->content, "rot_x", 5))
			rotate_around_x(d, angle, 1, 0);
		else if (!ft_strncmp(temp->content, "rev_y", 5))
			rotate_around_y(d, angle, 0, 1);
		else if (!ft_strncmp(temp->content, "rot_y", 5))
			rotate_around_y(d, angle, 1, 0);
		temp = temp->next;
	}
	ft_free_list(&d->rotations_history);
}

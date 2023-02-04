/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_toarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:45:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/04 07:27:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

void	ft_lstpoint_toarr(t_n *node, t_ui width, t_point **arr)
{
	t_ui	i;
	t_ui	j;

	i = 0;
	j = 0;
	while (node)
	{
		arr[i][j] = node->point;
		node = node->next;
		j++;
		if (j == width)
		{
			j = 0;
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_toarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:45:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:31:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

void	ft_lstpoint_toarr(t_n *node, t_ui width, t_point **arr)
{
	t_ui	i;
	t_ui	j;
	t_n		*dummy;

	i = 0;
	j = 0;
	dummy = node;
	while (node->next != dummy)
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

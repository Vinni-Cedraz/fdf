/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_toarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:45:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/15 12:26:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

t_point	**ft_lstpoint_toarr(t_node_with_a_point *node, uint width)
{
	uint	i;
	uint	j;
	uint	height;
	t_point	**array;

	height = (ft_lstpoint_size(node) / width);
	array = (t_point **)malloc((height) * sizeof(t_point *));
	i = 0;
	j = 0;
	while (node)
	{
		if (j == 0)
			array[i] = (t_point *)malloc(width * sizeof(t_point));
		array[i][j] = node->point;
		node = node->next;
		j++;
		if (j == width)
		{
			j = 0;
			i++;
		}
	}
	return (array);
}

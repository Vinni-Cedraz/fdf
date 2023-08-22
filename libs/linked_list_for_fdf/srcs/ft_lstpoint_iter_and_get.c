/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_iter_and_get.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:21:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/22 15:22:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"
#include <limits.h>

t_xy	ft_lstpoint_iter_and_get(t_n *list_point, t_point_calc_fptr calculate)
{
	t_n					*first;
	static t_xy_range	result;
	t_xy_range			range;

	first = list_point;
	range = (t_xy){
		.max_x = SHRT_MIN,
		.min_x = SHRT_MAX,
		.max_y = SHRT_MIN,
		.min_y = SHRT_MAX
	};
	result = range;
	while (list_point->next != first)
	{
		result = calculate(&list_point->point, result);
		list_point = list_point->next;
	}
	return (result);
}

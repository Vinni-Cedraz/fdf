/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_iter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:44:04 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/19 08:46:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

void	ft_lstpoint_iter(t_node *list_point, t_point_apply_fptr apply)
{
	t_node	*first;

	first = list_point;
	while (list_point->next != first)
	{
		apply(&list_point->point);
		list_point = list_point->next;
	}
}

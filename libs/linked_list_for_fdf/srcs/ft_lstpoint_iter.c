/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_iter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:44:04 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/21 17:41:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/linked_list_tools.h"

void	ft_lstpoint_iter(t_n *list_point, t_point_apply_fptr apply)
{
	t_n	*first;

	first = list_point;
	while (list_point->next != first)
	{
		apply(&list_point->point);
		list_point = list_point->next;
	}
}

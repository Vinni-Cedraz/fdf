/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:22:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/23 21:13:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

void	ft_lstpoint_print(t_node_with_a_point **lst)
{
	t_node_with_a_point	*tmp;

	if (!lst || !*lst)
	{
		if (!lst)
			ft_putstr("\n\n all nodes and list itself were already freed \n");
		else
			ft_putstr("\n\n empty list");
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		ft_printf("%d, ", (int)tmp->point.x);
		ft_printf("%d, ", (int)tmp->point.y);
		ft_printf("%d, ", (int)tmp->point.z);
		ft_printf("%d;\n", (int)tmp->point.color);
		tmp = tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:33:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 15:59:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

t_n	*ft_lstpoint_dup(t_n *lst)
{
	t_n	*new_lst;
	t_n	*new_node;

	if (!lst)
		return (NULL);
	new_lst = ft_lstpoint_new();
	new_node = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_node->next = ft_lstpoint_new();
		new_node = new_node->next;
		lst = lst->next;
	}
	return (new_lst);
}

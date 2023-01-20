/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:33:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/19 21:03:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

// duplicates a LINKED list of 't_node_with_a_point' s
t_node_with_a_point	*ft_lstpoint_dup(t_node_with_a_point *lst)
{
	t_node_with_a_point	*new_lst;
	t_node_with_a_point	*new_node;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_getby_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/23 21:13:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

t_n	*ft_lstpoint_getby_index(t_n *lst, uint i)
{
	if (!i)
		return (NULL);
	while (lst)
	{
		if (!i--)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

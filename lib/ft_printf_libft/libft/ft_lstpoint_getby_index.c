/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_getby_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 15:39:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node_with_a_point	*ft_lstpoint_getby_index(t_node_with_a_point *lst, uint i)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_get_by_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:41:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 16:20:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

typedef t_node_with_a_point	t_p_node;

int	ft_lstpoint_getby_content(t_p_node *lst, double x, double y, t z)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->point.x == x && lst->point.y == y && lst->point.z == z)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

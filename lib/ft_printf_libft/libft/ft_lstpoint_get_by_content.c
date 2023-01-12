/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_get_by_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:41:30 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 15:43:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

typedef double d;

int	ft_lstpoint_getby_content(t_node_with_a_point *lst, d x, d y, d z)
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

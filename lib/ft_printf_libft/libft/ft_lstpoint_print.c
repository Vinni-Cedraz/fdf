/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:22:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/13 10:50:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstpoint_print(t_node_with_a_point **lst)
{
	t_node_with_a_point	*tmp;

	if (!lst || !*lst)
	{
		if (!lst)
			printf("\n\n all nodes and list itself were already freed \n");
		else
			printf("\n\n empty list");
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		printf("%f, ", tmp->point.x);
		printf("%f, ", tmp->point.y);
		printf("%f, ", tmp->point.z);
		printf("%d;\n", tmp->point.color);
		tmp = tmp->next;
	}
}

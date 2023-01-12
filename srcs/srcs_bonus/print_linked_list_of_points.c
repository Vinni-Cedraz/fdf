/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_linked_list_of_points.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:27:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/11 23:29:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"


void	print_linked_list_of_points(t_node **lst)
{
	t_node	*tmp;

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
		printf("%f, ", tmp->point->x);
		printf("%f; ", tmp->point->y);
		ft_putchar('-');
		ft_putchar('>');
		ft_putchar('\n');
		tmp = tmp->next;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:34:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 15:30:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstpoint_free(t_node_with_a_point **list)
{
	t_node_with_a_point	*tmp;

	tmp = *list;
	if (list == NULL)
		return ;
	while (tmp)
	{
		*list = tmp->next;
		free(tmp);
		tmp = *list;
	}
	list = NULL;
}

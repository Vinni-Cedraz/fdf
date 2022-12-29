/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:37:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/29 19:39:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_list(t_node **list)
{
	t_node	*tmp;

	if (list == NULL)
		return ;
	tmp = *list;
	while (tmp->next)
	{
		tmp = (*list)->next;
		free((void*)*list);
		*list = tmp;
	}
	list = NULL;
}

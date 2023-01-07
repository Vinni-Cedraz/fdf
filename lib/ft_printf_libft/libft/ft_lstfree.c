/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:37:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 12:58:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

void	ft_free_list(t_node **list)
{
	t_node	*tmp;

	if (list == NULL)
		return ;
	tmp = *list;
	while ((*list)->next)
	{
		tmp = (*list)->next;
		free((void *)*list);
		*list = tmp;
	}
	list = NULL;
}

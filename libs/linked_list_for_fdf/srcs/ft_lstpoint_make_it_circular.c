/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_make_it_circular.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:01:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:17:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

void	ft_lstpoint_make_it_circular(t_n **head)
{
	t_n	*tail;
	t_n	*dummy;

	if (!head || !*head)
		return ;
	dummy = ft_lstpoint_new();
	ft_lstpoint_front(head, dummy);
	tail = *head;
	while (tail)
	{
		if (!tail->next)
			break ;
		tail = tail->next;
	}
	tail->next = dummy;
}

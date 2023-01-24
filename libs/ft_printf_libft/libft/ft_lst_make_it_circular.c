/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_make_it_circular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:05:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/23 14:00:27 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lst_make_it_circular(t_node **head)
{
	t_node *tail;

	tail = *head;
	if (!head || !*head)
		return ;
	tail = ft_lstlast(*head)->next;
	tail->next = *head;
}

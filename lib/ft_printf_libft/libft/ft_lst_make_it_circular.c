/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_make_it_circular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:05:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 01:11:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lst_make_it_circular(t_fsm_node **head)
{
	t_fsm_node	*tail;

	tail = *head;
	if (!head || !*head)
		return ;
	tail = ft_lstfsm_last(*head)->next;
	tail->next = *head;
}

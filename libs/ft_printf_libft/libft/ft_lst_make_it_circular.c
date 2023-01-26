/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_make_it_circular.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:05:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/25 23:32:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lst_make_it_circular(t_node **head)
{
	t_node	*tail;

	if (!head || !*head)
		return ;
	tail = *head;
	tail = ft_lstlast(*head);
	tail->next = *head;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfsm_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:34:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 00:35:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_fsm_node	*ft_lstfsm_new(t_iso_context *content)
{
	t_fsm_node	*node;

	node = malloc(sizeof(*node));
	node->context = content;
	node->next = NULL;
	return (node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_node_for_a_point.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:59:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 14:46:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node	*ft_lstnew_node_for_a_point(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->point = (t_point){0, 0, 0, 0, {0, 0, 0}, {0, 0, 0}};
	node->next = NULL;
	return (node);
}

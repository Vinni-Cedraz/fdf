/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:59:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 15:52:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node_with_a_point	*ft_lstpoint_new(void)
{
	t_node_with_a_point	*node;

	node = (t_node_with_a_point *)malloc(sizeof(t_node_with_a_point));
	node->point = ((t_point){0, 0, 0, 0, {0, 0, 0}, {0, 0, 0}});
	node->next = NULL;
	return (node);
}

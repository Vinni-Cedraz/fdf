/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:59:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/18 20:39:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node_with_a_point	*ft_lstpoint_new(void)
{
	t_node_with_a_point	*n;

	n = (t_node_with_a_point *)malloc(sizeof(t_node_with_a_point));
	n->point = (t_point){0, 0, 0, 0, {0, 0, 0}, {0, 0, 0, 0, 0, 0, {0, 0, 0}}};
	n->next = NULL;
	return (n);
}

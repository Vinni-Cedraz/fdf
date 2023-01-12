/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:11:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/11 22:11:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node	*ft_lstnew_point(t_point *content)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	node->content = content;
	node->next = NULL;
	return (node);
}

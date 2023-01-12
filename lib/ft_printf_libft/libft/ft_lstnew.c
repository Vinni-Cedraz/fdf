/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:24:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 12:14:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node	*ft_lstnew(void *content)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	node->point = (t_point *)content;
	node->next = NULL;
	return (node);
}

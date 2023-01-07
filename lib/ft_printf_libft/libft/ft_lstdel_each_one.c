/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_each_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:10:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 12:58:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

void	ft_lstdel_each_one(t_node **lst, void (*del)(void *))
{
	t_node	*tmp;
	t_node	*element;

	if (*lst == NULL)
		return ;
	element = *lst;
	while (element != NULL)
	{
		tmp = element->next;
		ft_lstdel_one(element, del);
		element = tmp;
	}
	*lst = NULL;
}

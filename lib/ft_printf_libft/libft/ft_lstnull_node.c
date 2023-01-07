/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnull_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:12:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 12:59:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

void	ft_lst_del_content(void *node)
{
	t_node	*temp;

	temp = (t_node *)node;
	if (!temp || !temp->content)
		return ;
	temp->content = NULL;
}

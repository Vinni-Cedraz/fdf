/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnode_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:12:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/29 17:48:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_node_content(void *node)
{
	t_node	*temp;

	temp = (t_node *)node;
	if (!temp || !temp->content)
		return ;
	temp->content = NULL;
}

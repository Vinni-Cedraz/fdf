/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:59:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/04 07:39:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

t_n	*ft_lstpoint_new(void)
{
	t_n	*n;

	n = (t_n *)malloc(sizeof(t_n));
	bzero((char *)&n->point, sizeof(t_point));
	n->next = NULL;
	return (n);
}

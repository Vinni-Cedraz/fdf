/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoint_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:34:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 21:50:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_tools.h"

void	ft_lstpoint_free(t_n **list)
{
	t_n	*tmp;
	t_n	*dummy;
	t_n	*last;

	tmp = *list;
	dummy = tmp;
	last = dummy;
	while (last->next != dummy)
		last = last->next;
	last->next = NULL;
	while (tmp)
	{
		*list = tmp->next;
		free(tmp);
		tmp = *list;
	}
	list = NULL;
}

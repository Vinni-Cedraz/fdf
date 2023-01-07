/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 12:59:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

void	ft_lstprint(t_node *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		ft_putchar('-');
		ft_putchar('>');
		ft_putchar('\n');
		lst = lst->next;
	}
}

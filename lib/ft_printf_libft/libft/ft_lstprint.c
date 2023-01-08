/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 22:28:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

static inline size_t	aux_ft_putchar(char c);
static inline size_t	aux_ft_putstr(char *s);

void	ft_lstprint(t_node *lst)
{
	while (lst)
	{
		aux_ft_putstr(lst->content);
		aux_ft_putchar('-');
		aux_ft_putchar('>');
		aux_ft_putchar('\n');
		lst = lst->next;
	}
}

static inline size_t	aux_ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
		aux_ft_putchar(*(s + i++));
	return (i);
}

static inline size_t	aux_ft_putchar(char c)
{
	return (write(1, &c, 1));
}

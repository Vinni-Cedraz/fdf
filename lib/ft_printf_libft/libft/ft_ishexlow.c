/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexlow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:32:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 16:38:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	aux_ft_isdigit(int c);

int	ft_ishexlow(char *s)
{
	while (*s)
	{
		if (aux_ft_isdigit(*s) || (*s >= 'a' && *s <= 'f'))
			return (1);
		s++;
	}
	return (0);
}

static inline int	aux_ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

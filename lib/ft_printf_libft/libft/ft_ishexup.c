/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:31:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/17 19:56:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	aux_isdigit(int c);

int	ft_ishexup(char *s)
{
	while (*s)
	{
		if (aux_isdigit(*s) || (*s >= 'A' && *s <= 'F'))
			return (1);
		s++;
	}
	return (0);
}

static inline int	aux_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

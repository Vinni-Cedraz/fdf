/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexlow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:32:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/17 20:03:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	aux_isdigit(int c);

int	ft_ishexlow(char *s)
{
	while (s && *s)
	{
		if (aux_isdigit(*s) || (*s >= 'a' && *s <= 'f'))
			return (1);
		s++;
	}
	return (0);
}

static inline int	aux_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

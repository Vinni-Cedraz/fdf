/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:31:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/18 12:21:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	is_digit(int c);
static inline int	is_hexup(int c);

int	ft_ishexup(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (is_digit(*s) || is_hexup(*s))
			return (1);
		s++;
	}
	return (0);
}

static inline int	is_digit(int c)
{
	return ('0' <= c && c <= '9');
}

static inline int	is_hexup(int c)
{
	return ('A' <= c && c <= 'F');
}

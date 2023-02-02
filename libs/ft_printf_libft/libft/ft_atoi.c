/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:49:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/02 12:48:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_whitespace(char c);
static int			isdigit(int c);
static int			issign(int c);

int	ft_atoi(const char *asci)
{
	short	sign;
	int		i;
	int		to_int;

	i = 0;
	sign = 1;
	to_int = 0;
	if (!asci)
		return (0);
	while (is_whitespace(asci[i]))
		i++;
	if (issign(asci[i]))
	{
		sign = -1;
		i++;
	}
	while (isdigit(asci[i]))
	{
		to_int = (to_int * 10) + (asci[i] - '0');
		i++;
	}
	to_int *= sign;
	return (to_int);
}

static inline int	is_whitespace(char c)
{
	int					i;
	static const char	whitespaces[]
		= {SPACE,
		CARRIAGE_RETURN,
		NEWLINE,
		TAB,
		VERTICAL_TAB,
		FORMFEED};

	i = -1;
	while (++i < 6)
		if (c == whitespaces[i])
			return (1);
	return (0);
}

static inline int	isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static inline int	issign(int c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

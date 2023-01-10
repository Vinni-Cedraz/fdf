/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:49:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 10:29:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline short	check_if_whitespace(char c);

int	ft_atoi(const char *asci)
{
	short	sign;
	short	i;
	int		to_int;

	i = 0;
	sign = 1;
	to_int = 0;
	while (check_if_whitespace(asci[i]))
		i++;
	if (asci[i] == '-')
		sign = -1;
	if (asci[i] == '-' || asci[i] == '+')
		i++;
	while (asci[i] >= '0' && asci[i] <= '9')
	{
		to_int = to_int * 10 + (asci[i] - '0');
		i++;
	}
	to_int *= sign;
	return (to_int);
}

static inline short	check_if_whitespace(char c)
{
	if (c == SPACE)
		return (1);
	else if (c == CARRIAGE_RETURN)
		return (1);
	else if (c == NEWLINE)
		return (1);
	else if (c == TAB)
		return (1);
	else if (c == VERTICAL_TAB)
		return (1);
	else if (c == FORMFEED)
		return (1);
	else
		return (0);
}

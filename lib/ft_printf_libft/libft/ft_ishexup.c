/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:31:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 16:39:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	aux_ft_isdigit(int c);

int	ft_ishexup(int c)
{
	return (aux_ft_isdigit(c) || (c >= 'A' && c <= 'F') || c == 'x');
}

static inline int	aux_ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

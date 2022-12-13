/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexlow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:32:21 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/12 08:32:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexlow(int c)
{
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f') || c == 'x');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:20:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/22 18:41:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
		ft_putchar(*(s + i++));
	return (i);
}

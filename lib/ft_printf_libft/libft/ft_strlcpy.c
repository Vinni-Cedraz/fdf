/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:35:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/05 22:53:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (ft_strlen(src) + 1 < size)
		return (ft_strlen(ft_memcpy(dst, src, ft_strlen(src) + 1)));
	if (!size)
		return (ft_strlen(src));
	ft_memcpy(dst, src, size - 1);
	*(dst + size - 1) = '\0';
	return (ft_strlen(src));
}

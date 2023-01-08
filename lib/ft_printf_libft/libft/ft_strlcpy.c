/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:35:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 22:21:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static inline void	*aux_ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(((t_uc *)dst) + i) = *(((t_uc *)src) + i);
	return (dst);
}

static inline size_t	aux_ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (aux_ft_strlen(src) + 1 < size)
		return (aux_ft_strlen(aux_ft_memcpy(dst, src, aux_ft_strlen(src) + 1)));
	if (!size)
		return (aux_ft_strlen(src));
	aux_ft_memcpy(dst, src, size - 1);
	*(dst + size - 1) = '\0';
	return (aux_ft_strlen(src));
}

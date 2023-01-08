/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:35:43 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/08 00:26:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	aux_ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static inline void	*aux_ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(((t_uc *)dst) + i) = *(((t_uc *)src) + i);
	return (dst);
}

static inline size_t	aux_ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (aux_ft_strlen(src) + 1 < size)
		return (aux_ft_strlen(aux_ft_memcpy(dst, src, aux_ft_strlen(src) + 1)));
	if (!size)
		return (aux_ft_strlen(src));
	aux_ft_memcpy(dst, src, size - 1);
	*(dst + size - 1) = '\0';
	return (aux_ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		s_len;

	s_len = aux_ft_strlen(s);
	dest = (char *)malloc(s_len + 1);
	aux_ft_strlcpy(dest, s, s_len + 1);
	return (dest);
}

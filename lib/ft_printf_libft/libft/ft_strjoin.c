/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:31:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/08 00:34:45 by vcedraz-         ###   ########.fr       */
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

static inline size_t	aux_ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_sz;

	dst_sz = aux_ft_strlen(dst);
	if (size < dst_sz + 1 || size == 0)
		dst_sz = size;
	if (size > dst_sz)
		aux_ft_strlcpy(dst + dst_sz, src, size - dst_sz);
	return (dst_sz + aux_ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_ools	tool;

	if (!s1 || !s2)
		return (NULL);
	tool.len = aux_ft_strlen(s1) + aux_ft_strlen(s2) + 1;
	tool.res = malloc(tool.len);
	aux_ft_strlcpy(tool.res, s1, tool.len);
	aux_ft_strlcat(tool.res, s2, tool.len);
	return (free((char *)s1), free((char *)s2), tool.res);
}

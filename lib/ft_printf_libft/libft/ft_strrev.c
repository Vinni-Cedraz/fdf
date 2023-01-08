/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:28:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 18:01:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;

static inline void		*aux_ft_memcpy(void *dst, const void *src, size_t n);
static inline void		aux_swap(void *a, void *b, size_t size);

char	*ft_strrev(char *str, size_t strlen)
{
	t_ools	tool;

	tool.from_start = -1;
	tool.from_end = strlen;
	while (++tool.from_start < strlen / 2)
		aux_swap(&str[tool.from_start], &str[--tool.from_end], sizeof(char));
	return (str);
}

static inline void	aux_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	aux_ft_memcpy(tmp, a, size);
	aux_ft_memcpy(a, b, size);
	aux_ft_memcpy(b, tmp, size);
	free(tmp);
}

static inline void	*aux_ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(((t_uc *)dst) + i) = *(((t_uc *)src) + i);
	return (dst);
}

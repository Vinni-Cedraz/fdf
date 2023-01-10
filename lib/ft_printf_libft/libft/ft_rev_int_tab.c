/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:28:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 11:32:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static inline void	*aux_memcpy(void *dst, const void *src, size_t n);
static inline void	aux_swap(void *a, void *b, size_t size);

void	ft_rev_int_tab(size_t *tab, size_t size)
{
	t_counters	count;

	count.from_start = 0;
	count.from_end = size - 1;
	while (count.from_start < (size / 2))
	{
		aux_swap(&tab[count.from_start], &tab[count.from_end], sizeof(size_t));
		count.from_start++;
		count.from_end--;
	}
}

static inline void	aux_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	aux_memcpy(tmp, a, size);
	aux_memcpy(a, b, size);
	aux_memcpy(b, tmp, size);
	free(tmp);
}

static inline void	*aux_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	i = -1;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (++i < n)
		*(dest + i) = *(source + i);
	return (dest);
}

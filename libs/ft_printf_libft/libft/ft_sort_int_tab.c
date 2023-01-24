/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:25:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 19:21:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*aux_memcpy(void *dst, const void *src, size_t n);
static inline void	aux_swap(void *a, void *b, size_t size);
static inline short	aux_is_sorted(size_t *tab, size_t sz);

void	ft_sort_int_tab(size_t *tab, size_t size)
{
	size_t	begin;

	begin = -1;
	if (*tab == '\0' || size == 0)
		return ;
	while (++begin < size - 1)
	{
		if (tab[begin] > tab[begin + 1])
			aux_swap(&tab[begin], &tab[begin + 1], sizeof(size_t));
	}
	if (!aux_is_sorted(tab, size))
		ft_sort_int_tab(tab, size);
}

static inline short	aux_is_sorted(size_t *tab, size_t sz)
{
	size_t	i;

	i = -1;
	while (++i < sz - 1)
		if (tab[i] > tab[i + 1])
			return (0);
	return (1);
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

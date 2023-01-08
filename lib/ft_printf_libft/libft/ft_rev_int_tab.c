/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:28:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 17:27:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;
static inline void		*aux_ft_memcpy(void *dst, const void *src, size_t n);
static inline void		aux_ft_swap(void *a, void *b, size_t size);

void	ft_rev_int_tab(size_t *tab, size_t size)
{
	t_ools	tool;

	tool.from_start = 0;
	tool.from_end = size - 1;
	while (tool.from_start < (size / 2))
	{
		aux_ft_swap(&tab[tool.from_start], &tab[tool.from_end], sizeof(size_t));
		tool.from_start++;
		tool.from_end--;
	}
}

static inline void	aux_ft_swap(void *a, void *b, size_t size)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:25:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 17:29:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;
static inline void		*aux_ft_memcpy(void *dst, const void *src, size_t n);
static inline void		aux_ft_swap(void *a, void *b, size_t size);

void	ft_sort_int_tab(size_t *tab, size_t size)
{
	size_t	i;
	size_t	begin;

	i = 0;
	begin = 0;
	while (i < size - 1)
	{
		while (begin < size - 1)
		{
			if (tab[begin] > tab[begin + 1])
			{
				aux_ft_swap(&tab[begin], &tab[begin + 1], sizeof(size_t));
			}
			begin++;
		}
		i++;
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

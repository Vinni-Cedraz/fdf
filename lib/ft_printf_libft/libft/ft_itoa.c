/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:40:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 22:22:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*aux_ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!size || !nmemb)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	while (i < size * nmemb)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

static inline char	*aux_ft_strrev(char *str, size_t strlen)
{
	t_ools	tool;

	tool.from_start = -1;
	tool.from_end = strlen;
	while (++tool.from_start < strlen / 2)
		ft_swap(&str[tool.from_start], &str[--tool.from_end], sizeof(char));
	return (str);
}

static inline int	aux_ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static inline int	aux_ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	t_ools	nb;

	nb.i = 0;
	nb.abs = aux_ft_abs(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	nb.len = aux_ft_numlen(n);
	nb.to_ascii = aux_ft_calloc(nb.len + 1, sizeof(char));
	while (nb.abs != 0)
	{
		nb.to_ascii[nb.i++] = nb.abs % 10 + '0';
		nb.abs /= 10;
	}
	if (n > 0)
		return (aux_ft_strrev(nb.to_ascii, nb.len));
	ft_strlcat(nb.to_ascii, "-", nb.len + 1);
	return (aux_ft_strrev(nb.to_ascii, nb.len));
}

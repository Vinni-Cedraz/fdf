/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:40:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 10:51:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			aux_numlen(int n);
static void			*aux_calloc(size_t nmemb, size_t size);
static char			*aux_strrev(char *str, size_t strlen);

static inline int	aux_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	int		n_len;
	int		n_abs;
	char	*to_ascii;

	i = 0;
	n_abs = aux_abs(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	n_len = aux_numlen(n);
	to_ascii = aux_calloc(n_len + 1, sizeof(char));
	while (n_abs != 0)
	{
		to_ascii[i++] = n_abs % 10 + '0';
		n_abs /= 10;
	}
	if (n > 0)
		return (aux_strrev(to_ascii, n_len));
	ft_strlcat(to_ascii, "-", n_len + 1);
	return (aux_strrev(to_ascii, n_len));
}

static void	*aux_calloc(size_t nmemb, size_t size)
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

static char	*aux_strrev(char *str, size_t strlen)
{
	t_counters	count;

	count.from_start = -1;
	count.from_end = strlen;
	while (++count.from_start < strlen / 2)
		ft_swap(&str[count.from_start], &str[--count.from_end], sizeof(char));
	return (str);
}

static int	aux_numlen(int n)
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

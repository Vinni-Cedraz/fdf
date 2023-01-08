/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:46:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 22:19:32 by vcedraz-         ###   ########.fr       */
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

static size_t	converted_len(size_t n, char *base)
{
	t_ools	nb;

	nb.len = 1;
	nb.baselen = aux_ft_strlen(base);
	while (n >= nb.baselen)
	{
		n /= nb.baselen;
		nb.len++;
	}
	return (nb.len);
}

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

char	*ft_itoa_base(size_t n, char *base)
{
	t_ools	tool;

	tool.len = converted_len(n, base);
	tool.baselen = aux_ft_strlen(base);
	tool.str = aux_ft_calloc((tool.len + 1), sizeof(char));
	if (!tool.str)
		return (NULL);
	while (tool.len--)
	{
		tool.str[tool.len] = base[n % tool.baselen];
		n /= tool.baselen;
	}
	return (tool.str);
}

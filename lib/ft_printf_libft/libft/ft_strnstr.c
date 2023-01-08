/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:55:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 17:59:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;

static inline size_t	aux_ft_strlen(const char *str);
static inline int		aux_ft_strncmp(const char *s1, const char *s2,
							size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lil_sz;

	i = -1;
	lil_sz = aux_ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (big[++i] && i < len)
		if (!aux_ft_strncmp(big + i, little, lil_sz) && i + lil_sz <= len)
			return ((char *)(big + i));
	return (NULL);
}

static inline size_t	aux_ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static inline int	aux_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((t_uc)s1[i] - (t_uc)s2[i]);
}

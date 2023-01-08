/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:48:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 22:20:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	aux_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

static inline char	*aux_strrchr(const char *s, int c)
{
	int	i;

	i = aux_strlen(s) + 1;
	while (i-- > 0 && s)
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (NULL);
}

static inline void	*aux_memchr(const void *s, int c, size_t n)
{
	while (n-- != 0)
		if (*(t_uc *)s++ == (t_uc)c)
			return ((t_uc *)s - 1);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	set_len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = aux_strlen(s1);
	set_len = aux_strlen(set);
	while (aux_memchr(set, s1[i], set_len))
		i++;
	while (aux_strrchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}

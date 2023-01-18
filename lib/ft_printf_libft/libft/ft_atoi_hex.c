/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:38:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/18 00:15:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	is_whitespace(char c);
static inline int	is_digit(int c);
static inline int	is_sign(int c);
static inline int	is_valid_hex_char(char c);

int	ft_atoi_hex(const char *hex_str)
{
	int			i;
	int			res;
	int			len;
	const char	*start;
	const char	*end;

	i = 0;
	res = 0;
	while (is_whitespace(hex_str[i]))
		i++;
	if (hex_str[i] == '0' && (hex_str[i + 1] == 'x' || hex_str[i + 1] == 'X'))
		i += 2;
	start = hex_str + i;
	end = start;
	while (is_valid_hex_char(*end))
		end++;
	len = end - start;
	if (len < 6)
	{
		hex_str = (char *)malloc(sizeof(char) * (6 - len + 1));
		ft_memset((char *)hex_str, '0', 6 - len);
		ft_strlcpy((char *)hex_str + (6 - len), start, len);
		while (*hex_str)
		{
			if (is_digit(*hex_str))
				res = (res << 4) + (*hex_str - '0');
			else if (*hex_str >= 'a' && *hex_str <= 'f')
				res = (res << 4) + (*hex_str - 'a' + 10);
			else if (*hex_str >= 'A' && *hex_str <= 'F')
				res = (res << 4) + (*hex_str - 'A' + 10);
			hex_str++;
		}
		free((void *)hex_str);
	}
	else
		while (is_valid_hex_char(hex_str[i]))
		{
			if (is_digit(hex_str[i]))
				res = (res << 4) + (hex_str[i] - '0');
			else if (hex_str[i] >= 'a' && hex_str[i] <= 'f')
				res = (res << 4) + (hex_str[i] - 'a' + 10);
			else if (hex_str[i] >= 'A' && hex_str[i] <= 'F')
				res = (res << 4) + (hex_str[i] - 'A' + 10);
			i++;
		}
	return (res);
}

static inline int	is_whitespace(char c)
{
	if (c == SPACE)
		return (1);
	else if (c == CARRIAGE_RETURN)
		return (1);
	else if (c == NEWLINE)
		return (1);
	else if (c == TAB)
		return (1);
	else if (c == VERTICAL_TAB)
		return (1);
	else if (c == FORMFEED)
		return (1);
	else
		return (0);
}

static inline int	is_digit(int c)
{
	return ('0' <= c && c <= '9');
}

static inline int	is_sign(int c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

static inline int	is_valid_hex_char(char c)
{
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

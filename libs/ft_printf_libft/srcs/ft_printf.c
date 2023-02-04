/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022 22:57:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/03 20:59:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

static int	print_until(const char *str, va_list args);
static int	is_format(char c);

int	ft_printf(const char *fmt, ...)
{
	t_ools	type;

	if (!fmt)
		return (-1);
	type.counter = 0;
	va_start(type.list, fmt);
	type.counter += print_until(fmt, type.list);
	return (va_end(type.list), type.counter);
}

static int	print_until(const char *str, va_list args)
{
	t_counters	chars;
	int			lookup_index;

	chars.prntd = 0;
	chars.chckd = 0;
	lookup_index = -1;
	while (str[chars.chckd] != '\0')
	{
		if (str[chars.chckd] != '%')
		{
			chars.prntd += ft_putchar(str[chars.chckd]);
			lookup_index = -1;
		}
		else
			lookup_index = is_format(str[chars.chckd + 1]);
		if (lookup_index != -1 && str[chars.chckd] == '%')
		{
			chars.prntd += parser(lookup_index, args);
			chars.chckd++;
		}
		else if (lookup_index == -1 && str[chars.chckd] == '%')
			chars.prntd += ft_putchar(str[chars.chckd]);
		chars.chckd++;
	}
	return (chars.prntd);
}

static int	is_format(char c)
{
	int					i;
	static const int	formats[9] = {
		CHAR,
		STRING,
		POINTER,
		DECIMAL,
		INTEGER,
		HEX_LOWER,
		HEX_UPPER,
		UDECIMAL,
		PERCENT};

	i = -1;
	while (++i < 9)
		if (c == formats[i])
			return (i);
	return (-1);
}

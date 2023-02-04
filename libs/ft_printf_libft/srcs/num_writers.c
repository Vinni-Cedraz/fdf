/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_writers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:26:51 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/03 20:31:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

inline int	put_hexup(unsigned long long value)
{
	char	*str;
	int		counter;

	str = ft_itoa_base(value, HEX_BASE_UPPER);
	counter = put_string(str);
	return (free(str), counter);
}

inline int	put_hexlow(unsigned long long value)
{
	char	*str;
	int		counter;

	str = ft_itoa_base(value, HEX_BASE_LOWER);
	counter = put_string(str);
	return (free(str), counter);
}

inline int	put_decimal(signed long value)
{
	char	*str;
	int		counter;

	counter = 0;
	if (value < 0)
	{
		ft_putchar('-');
		value *= -1;
		counter++;
	}
	str = ft_itoa_base(value, DECIMAL_BASE);
	counter += put_string(str);
	return (free(str), counter);
}

inline int	put_unsigned(long value)
{
	int		counter;
	char	*str;

	str = ft_itoa_base(value, DECIMAL_BASE);
	counter = put_string(str);
	return (free(str), counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:11:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/03 21:04:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

int	put_string(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		str = EXCEPTION_STR;
	while (str[counter] != '\0')
		counter += ft_putchar(str[counter]);
	return (counter);
}

int	put_pointer(unsigned long long value)
{
	char	*str;
	int		counter;

	if (value == 0)
		return (put_string(ZERO_EXCEPTION_STR));
	str = ft_itoa_base(value, HEX_BASE_LOWER);
	counter = put_string(PRECEDING_STR);
	counter += put_string(str);
	return (free(str), counter);
}

int	put_percent(void)
{
	return (ft_putchar('%'));
}

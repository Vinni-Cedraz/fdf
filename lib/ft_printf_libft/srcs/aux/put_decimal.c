/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022 23:32:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 20:53:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

int	put_decimal(signed long value)
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

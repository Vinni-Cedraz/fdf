/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022 23:33:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 20:54:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

int	put_pointer(unsigned long long value)
{
	char	*str;
	int		counter;

	if (value == 0)
		return (put_string(ZERO_EXCEPTION_STR));
	str = ft_itoa_base(value, HEX_BASE);
	counter = put_string(PRECEDING_STR);
	counter += put_string(str);
	return (free(str), counter);
}

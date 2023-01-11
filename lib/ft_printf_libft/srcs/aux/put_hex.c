/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022 23:28:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 20:54:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

int	put_hex(unsigned long long value, int is_upper)
{
	char	*str;
	int		counter;

	if (is_upper)
	{
		str = ft_itoa_base(value, HEX_BASE_UPPER);
		counter = put_string(str);
		return (free(str), counter);
	}
	str = ft_itoa_base(value, HEX_BASE);
	counter = put_string(str);
	return (free(str), counter);
}

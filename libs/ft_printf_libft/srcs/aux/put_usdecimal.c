/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_usdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022 23:33:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 20:55:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

int	put_usdecimal(long value)
{
	char	*str;
	int		counter;

	str = ft_itoa_base(value, DECIMAL_BASE);
	counter = put_string(str);
	return (free(str), counter);
}

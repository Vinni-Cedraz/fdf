/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_to_num_writers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:25:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/03 20:25:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

inline int	call_putdeci(va_list args)
{
	return (put_decimal(va_arg(args, int)));
}

inline int	call_puthexup(va_list args)
{
	return (put_hexup(va_arg(args, unsigned int)));
}

inline int	call_puthexlow(va_list args)
{
	return (put_hexlow(va_arg(args, unsigned int)));
}

inline int	call_put_unsigned(va_list args)
{
	return (put_unsigned(va_arg(args, unsigned int)));
}

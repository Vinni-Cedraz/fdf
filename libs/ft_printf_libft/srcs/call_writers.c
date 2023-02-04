/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_writers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:23:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/03 20:59:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

inline int	call_putchar(va_list args)
{
	return (ft_putchar(va_arg(args, int)));
}

inline int	call_putstring(va_list args)
{
	return (put_string(va_arg(args, char *)));
}

inline int	call_putpointer(va_list args)
{
	return (put_pointer(va_arg(args, unsigned long long)));
}

inline int	call_put_percent(va_list args)
{
	(void)args;
	return (ft_putchar('%'));
}

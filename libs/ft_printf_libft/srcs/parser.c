/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:46:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/03 20:57:27 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft_includes.h"

int	parser(int i, va_list args)
{
	int								prntd_chars;
	static const t_ptr_to_put_funct	formatters[9] = {
		call_putchar,
		call_putstring,
		call_putpointer,
		call_putdeci,
		call_putdeci,
		call_puthexlow,
		call_puthexup,
		call_put_unsigned,
		call_put_percent
	};

	prntd_chars = formatters[i](args);
	return (prntd_chars);
}

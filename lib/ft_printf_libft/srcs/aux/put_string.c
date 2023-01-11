/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022 23:33:25 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 20:55:12 by vcedraz-         ###   ########.fr       */
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

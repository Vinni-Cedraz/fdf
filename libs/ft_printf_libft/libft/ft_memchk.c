/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:31:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/01 19:43:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memchk(size_t size1, size_t size2)
{
	if (!size2 || !size1)
		return (exit(1), 1);
	if (size1 != size2)
	{
		ft_putstr("Error: allocated wrong size for pointer");
		return (exit(1), 1);
	}
	return (0);
}

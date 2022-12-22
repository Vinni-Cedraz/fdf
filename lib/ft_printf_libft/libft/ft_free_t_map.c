/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:29:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/22 19:11:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_t_map(t_point **map)
{
	if (map == NULL)
		return ;
	ft_free_arr((char **)(map), (void **)(map));
	map = NULL;
}

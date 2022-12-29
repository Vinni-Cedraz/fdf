/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:29:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 16:40:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	ft_free_t_map(t_point **map)
{
	if (map == NULL)
		return ;
	ft_free_arr((char **)(map), (void **)(map));
	map = NULL;
}

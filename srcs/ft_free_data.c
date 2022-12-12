/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:52:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/11 23:53:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

void	ft_free_data(t_data **d)
{
	int	i;

	i = -1;
	while (++i < (*d)->map->height + 1)
		free((*d)->map->arr[i]);
	free((*d)->map->arr);
	free((*d)->map);
}

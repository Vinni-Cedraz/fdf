/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:29:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 12:32:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	aux_free_arr(char **arr, void **aux);

void	ft_free_t_map(t_point **map)
{
	if (map == NULL)
		return ;
	aux_free_arr((char **)(map), (void **)(map));
	map = NULL;
}

static inline void	aux_free_arr(char **arr, void **aux)
{
	while (*arr)
		free(*arr++);
	free(aux);
}

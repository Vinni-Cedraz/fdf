/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/01 14:40:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static int			hash_function(int key);

int	deal_keys_bonus(int key, t_data *d)
{
	int	index;

	index = hash_function(key);
	if (!d->lookup.events[index].f)
		return (0);
	d->lookup.events[index].f(d);
	return (0);
}

static inline int	hash_function(int key)
{
	return ((key % 96) + 32);
}
